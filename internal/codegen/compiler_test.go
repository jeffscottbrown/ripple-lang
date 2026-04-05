package codegen_test

import (
	"testing"

	"github.com/jeffscottbrown/ripple-lang/internal/codegen"
	"github.com/jeffscottbrown/ripple-lang/internal/parser"
	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
)

func TestCompiler_Emission(t *testing.T) {
	t.Run("Assignment and Suppose", func(t *testing.T) {
		code := `["jam"]
jerry_vibe becomes copacetic
suppose jerry_vibe vibes_like copacetic
say "Smooth water"
enough`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// Boolean variable must be stack-allocated and initialised to true (copacetic).
		assert.Contains(t, ir, "alloca i1")
		assert.Contains(t, ir, "store i1 1")

		// The condition must be evaluated at runtime – never hard-coded as true.
		assert.Contains(t, ir, "icmp eq i1")

		// The string literal must appear in the IR globals.
		assert.Contains(t, ir, "Smooth water")

		// Print must be wired to printf.
		assert.Contains(t, ir, "@printf")
	})

	t.Run("Harsh assignment", func(t *testing.T) {
		code := `["jam"]
vibe becomes harsh`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// A boolean variable must be allocated on the stack.
		assert.Contains(t, ir, "alloca i1")
		// harsh maps to i1 0.
		assert.Contains(t, ir, "store i1 0")
	})

	t.Run("Harshing_the_vibe_of operator", func(t *testing.T) {
		code := `["jam"]
vibe becomes copacetic
suppose vibe harshing_the_vibe_of copacetic
say "Not copacetic"
enough`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// harshing_the_vibe_of must lower to icmp ne on i1 values.
		assert.Contains(t, ir, "icmp ne i1")
	})

	t.Run("Louder_than operator", func(t *testing.T) {
		code := `["circle of friends"]
jerry: "Jerry"
janis: "Janis"

["albums"]
jerry: { "A" "B" "C" }
janis: { "A" "B" }

["jam"]
suppose jerry.albumcount louder_than janis.albumcount
say "Jerry has more"
enough`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// louder_than must lower to icmp sgt on i32 values.
		assert.Contains(t, ir, "icmp sgt i32")
	})

	t.Run("Quieter_than operator", func(t *testing.T) {
		code := `["circle of friends"]
jerry: "Jerry"
janis: "Janis"

["albums"]
jerry: { "A" "B" "C" }
janis: { "A" "B" }

["jam"]
suppose janis.albumcount quieter_than jerry.albumcount
say "Janis has fewer"
enough`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// quieter_than must lower to icmp slt on i32 values.
		assert.Contains(t, ir, "icmp slt i32")
	})

	t.Run("Otherwise branch", func(t *testing.T) {
		code := `["jam"]
vibe becomes copacetic
suppose vibe vibes_like copacetic
say "Yes"
otherwise
say "No"
enough`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// A conditional with an otherwise clause must emit the else basic block.
		assert.Contains(t, ir, "else.0:")
	})

	t.Run("No otherwise branch", func(t *testing.T) {
		code := `["jam"]
vibe becomes copacetic
suppose vibe vibes_like copacetic
say "Yes"
enough`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// The merge block must still appear for fall-through.
		assert.Contains(t, ir, "merge.0:")
		// Without an otherwise clause no else block should be emitted.
		assert.NotContains(t, ir, "else.0:")
	})

	t.Run("Has true at compile time", func(t *testing.T) {
		code := `["circle of friends"]
jerry: "Jerry"

["albums"]
jerry: { "A" "B" "C" }

["jam"]
suppose jerry has "A"
say "Found it"
enough`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// has is resolved at compile time; "A" is present so the branch must be
		// unconditionally true.
		assert.Contains(t, ir, "br i1 1")
	})

	t.Run("Has false at compile time", func(t *testing.T) {
		code := `["circle of friends"]
jerry: "Jerry"

["albums"]
jerry: { "A" "B" "C" }

["jam"]
suppose jerry has "Abbey Road"
say "Found it"
enough`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// has is resolved at compile time; "Abbey Road" is absent so the branch
		// must be unconditionally false.
		assert.Contains(t, ir, "br i1 0")
	})

	t.Run("Name resolution", func(t *testing.T) {
		code := `["circle of friends"]
jerry: "Jerry Garcia"

["jam"]
say jerry.name`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// The resolved string value must be present as a global constant.
		assert.Contains(t, ir, "Jerry Garcia")
	})

	t.Run("Albumcount resolution", func(t *testing.T) {
		code := `["circle of friends"]
jerry: "Jerry"
janis: "Janis"

["albums"]
jerry: { "A" "B" "C" }
janis: { "A" "B" }

["jam"]
suppose jerry.albumcount louder_than janis.albumcount
say "Jerry has more"
enough`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// albumcount is resolved at compile time to the length of the list.
		// jerry has 3 albums, janis has 2.
		assert.Contains(t, ir, "icmp sgt i32 3, 2")
	})

	t.Run("Multi-arg say", func(t *testing.T) {
		code := `["jam"]
say "a" "b"`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// Two string arguments must produce a format string with two %s directives.
		assert.Contains(t, ir, "%s%s")
	})

	t.Run("And operator", func(t *testing.T) {
		code := `["jam"]
a becomes copacetic
b becomes copacetic
suppose a and b
    say "yes"
enough`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// and between two i1 values must lower to the LLVM and i1 instruction.
		assert.Contains(t, ir, "and i1")
	})

	t.Run("Or operator", func(t *testing.T) {
		code := `["jam"]
a becomes harsh
b becomes copacetic
suppose a or b
    say "yes"
enough`
		prog, err := parser.Parse(code)
		require.NoError(t, err)

		ir, err := codegen.New().Compile(prog)
		require.NoError(t, err)

		// or between two i1 values must lower to the LLVM or i1 instruction.
		assert.Contains(t, ir, "or i1")
	})
}

func TestCompiler_Analysis(t *testing.T) {
	t.Run("Reject collection in circle of friends", func(t *testing.T) {
		code := `["circle of friends"]
jerry: { "Jerry" "Garcia" }`

		_, err := parser.Parse(code)

		assert.Error(t, err)
		assert.ErrorContains(t, err, `unexpected token "{"`)
	})

	t.Run("Reject unknown artist property", func(t *testing.T) {
		code := `["circle of friends"]
jerry: "Jerry Garcia"

["jam"]
say jerry.height`

		prog, err := parser.Parse(code)
		require.NoError(t, err)
		_, err = codegen.New().Compile(prog)
		assert.Error(t, err)
		// Update to match: "artist 'jerry' does not have a property named 'height'"
		assert.ErrorContains(t, err, "artist does not have that property: height")
	})

	t.Run("Reject unrecorded artist", func(t *testing.T) {
		code := `["jam"]
say bob.name`

		prog, err := parser.Parse(code)
		require.NoError(t, err)

		_, err = codegen.New().Compile(prog)
		assert.Error(t, err)
		assert.ErrorContains(t, err, "not in your circle of friends")
	})

	t.Run("Reject usage before definition", func(t *testing.T) {
		code := `["jam"]
say vibe
vibe becomes copacetic`

		prog, err := parser.Parse(code)
		require.NoError(t, err)

		_, err = codegen.New().Compile(prog)
		assert.Error(t, err)
		assert.ErrorContains(t, err, "variable for artist is not defined: vibe")
	})
}
