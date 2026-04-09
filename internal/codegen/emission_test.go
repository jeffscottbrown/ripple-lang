package codegen_test

import (
	"testing"

	"github.com/jeffscottbrown/ripple-lang/internal/codegen"
	"github.com/jeffscottbrown/ripple-lang/internal/parser"
	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
)

func TestCompiler_Emission(t *testing.T) {
	t.Run("Booleans and Logic", func(t *testing.T) {
		code := `[jam]
                 vibe becomes copacetic
                 suppose vibe vibes_like copacetic
                   say "Copacetic"
                 otherwise
                   say "Harsh"
                 enough`
		ir := compileOrFatal(t, code)

		// Check allocation and initialization
		assert.Contains(t, ir, "%0 = alloca i1")
		assert.Contains(t, ir, "store i1 true, i1* %0")

		// Check Comparison and Branching with unique indices
		assert.Contains(t, ir, "icmp eq i1")
		assert.Contains(t, ir, "br i1 %2, label %then.0, label %else.0")

		// Check standardized, indexed block names
		assert.Contains(t, ir, "then.0:")
		assert.Contains(t, ir, "else.0:")
		assert.Contains(t, ir, "merge.0:")
	})

	t.Run("Compile Time Has Resolution", func(t *testing.T) {
		code := `[friends]
                 jerry: "Jerry"
                 [albums]
                 jerry: { "Workingman's Dead" }
                 [jam]
                 suppose jerry.albums has "Workingman's Dead"
                   say "Found it"
                 enough`
		ir := compileOrFatal(t, code)

		// 'has' resolves to a constant 'true' branch at compile time
		// Note the label index .0 because it's the first conditional in this test
		assert.Contains(t, ir, "br i1 true, label %then.0, label %merge.0")
	})

	t.Run("Numeric Comparisons", func(t *testing.T) {
		code := `[friends]
                 jerry: "Jerry"
                 janis: "Janis"
                 [albums]
                 jerry: { "A" "B" }
                 janis: { "C" }
                 [jam]
                 suppose jerry.albumcount louder_than janis.albumcount
                   say "Jerry wins"
                 enough`
		ir := compileOrFatal(t, code)

		// Check compile-time resolution of album counts (3 vs 2)
		// icmp sgt i32 2, 1 (jerry has 2, janis has 1)
		assert.Contains(t, ir, "icmp sgt i32 2, 1")
	})

	t.Run("Multi-Argument Output", func(t *testing.T) {
		code := `[jam]
                 say "One" "Two" "Three"`
		ir := compileOrFatal(t, code)

		// Check format string generation with newlines (\0A)
		assert.Contains(t, ir, "c\"%s%s%s\\0A\\00\"")
		assert.Contains(t, ir, "call i32 (i8*, ...) @printf")
	})

	t.Run("Attributes and Identifiers", func(t *testing.T) {
		code := `[friends]
                 jerry: "Jerry Garcia"
                 [jam]
                 say jerry.name`
		ir := compileOrFatal(t, code)

		// Verify the string was interned as a global
		assert.Contains(t, ir, "Jerry Garcia")
		// Verify GEP points to a i8 array (string)
		assert.Contains(t, ir, "getelementptr [13 x i8]")
	})

	t.Run("And Operator", func(t *testing.T) {
		code := `[jam]
                 a becomes copacetic
                 b becomes copacetic
                 suppose a and b
                   say "yes"
                 enough`
		ir := compileOrFatal(t, code)

		// Check the i1 logic instruction
		assert.Contains(t, ir, "and i1")
	})
}

// Helper to reduce boilerplate in emission tests.
func compileOrFatal(t *testing.T, code string) string {
	t.Helper()
	prog, err := parser.Parse(code)
	require.NoError(t, err)

	ir, err := codegen.New().Compile(prog)
	require.NoError(t, err, "Code failed to compile IR")
	return ir
}
