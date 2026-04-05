// Package runner_test contains end-to-end integration tests for the Ripple
// compiler/runner pipeline. Each test compiles a Ripple source string to a
// native binary via clang and asserts the captured stdout.
//
// All tests call skipIfNoClang at the top and are therefore safe to run in
// environments where clang is absent (CI matrices without LLVM, for example).
package runner_test

import (
	"bytes"
	"os/exec"
	"strings"
	"testing"

	"github.com/jeffscottbrown/ripple-lang/internal/runner"
	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
)

// skipIfNoClang marks the calling test as skipped when clang is not on PATH.
// It must be called at the top of every test function in this file because the
// runner pipeline requires clang to lower LLVM IR to a native binary.
func skipIfNoClang(t *testing.T) {
	t.Helper()
	if _, err := exec.LookPath("clang"); err != nil {
		t.Skip("clang not found; skipping integration test")
	}
}

// TestExecute_Say_StringLiteral verifies the simplest possible Ripple program:
// a single jam section containing one say statement with a string literal.
//
// Language features demonstrated:
//   - ["jam"] section header syntax
//   - say statement with a double-quoted string literal
//   - runner.Execute returns the captured stdout including the trailing newline
func TestExecute_Say_StringLiteral(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["jam"]
say "hello world"
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "hello world\n", out.String())
}

// TestExecute_Assignment_Copacetic_TrueBranch verifies that assigning the boolean
// literal 'copacetic' (true) to a variable and then testing it with
// "suppose <var> vibes_like copacetic" causes the then-body to execute.
//
// Language features demonstrated:
//   - 'becomes' assignment operator
//   - 'copacetic' boolean literal (true)
//   - 'suppose … enough' conditional with 'vibes_like' equality operator
//   - then-body executes when condition is satisfied
func TestExecute_Assignment_Copacetic_TrueBranch(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["jam"]
vibe becomes copacetic
suppose vibe vibes_like copacetic
    say "it is golden"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "it is golden\n", out.String())
}

// TestExecute_Assignment_Harsh_FalseBranch verifies that assigning 'harsh'
// (false) to a variable causes a "suppose <var> vibes_like copacetic" block to
// be skipped entirely, producing no output.
//
// Language features demonstrated:
//   - 'harsh' boolean literal (false)
//   - then-body is suppressed when the condition evaluates to false
//   - program produces empty stdout when no say is reached
func TestExecute_Assignment_Harsh_FalseBranch(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["jam"]
vibe becomes harsh
suppose vibe vibes_like copacetic
    say "should not print"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "", out.String())
}

// TestExecute_HarshingTheVibeOf_NotEqual verifies the 'harshing_the_vibe_of'
// (not-equal) operator. A variable holding 'copacetic' is compared with 'harsh'
// using 'harshing_the_vibe_of'; since copacetic != harsh the condition is true
// and the then-body executes.
//
// Language features demonstrated:
//   - 'harshing_the_vibe_of' keyword as the not-equal (!=) operator
//   - comparing a variable against a boolean literal
//   - then-body executes when harshing_the_vibe_of comparison yields true
func TestExecute_HarshingTheVibeOf_NotEqual(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["jam"]
vibe becomes copacetic
suppose vibe harshing_the_vibe_of harsh
    say "vibe is not muddy"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "vibe is not muddy\n", out.String())
}

// TestExecute_Otherwise_TrueBranch verifies the full suppose/otherwise/enough
// construct when the condition is true. With a 'copacetic' vibe the then-branch
// should execute and the otherwise-branch should be skipped.
//
// Language features demonstrated:
//   - 'suppose … otherwise … enough' if/else syntax
//   - then-branch taken when condition is true
//   - otherwise-branch is not reached when condition is true
func TestExecute_Otherwise_TrueBranch(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["jam"]
vibe becomes copacetic
suppose vibe vibes_like copacetic
    say "golden branch"
otherwise
    say "muddy branch"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "golden branch\n", out.String())
}

// TestExecute_Otherwise_FalseBranch verifies that when the condition of a
// suppose block is false the otherwise-branch executes instead of the
// then-body. Assigning 'harsh' makes "vibes_like copacetic" false.
//
// Language features demonstrated:
//   - otherwise-branch taken when condition evaluates to false
//   - then-body is skipped when otherwise-branch is selected
func TestExecute_Otherwise_FalseBranch(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["jam"]
vibe becomes harsh
suppose vibe vibes_like copacetic
    say "golden branch"
otherwise
    say "muddy branch"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "muddy branch\n", out.String())
}

// TestExecute_LouderThan_AlbumCount verifies the 'louder_than' (greater-than)
// operator when comparing album counts. Jerry has 3 albums and Janis has 2,
// so jerry.albumcount louder_than janis.albumcount is true.
//
// Language features demonstrated:
//   - ["circle of friends"] section with "Key: Display Name" entries
//   - ["albums"] section with "key: { title title … }" collection entries
//   - '.albumcount' attribute resolves to the number of albums at compile time
//   - 'louder_than' keyword as the greater-than (>) operator
func TestExecute_LouderThan_AlbumCount(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["circle of friends"]
jerry: "Jerry Garcia"
janis: "Janis Joplin"

["albums"]
jerry: { "Workingman's Dead" "American Beauty" "Europe 72" }
janis: { "Kozmic Blues" "Pearl" }

["jam"]
suppose jerry.albumcount louder_than janis.albumcount
    say "Jerry has more albums"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "Jerry has more albums\n", out.String())
}

// TestExecute_QuieterThan_AlbumCount verifies the 'quieter_than' (less-than)
// operator when comparing album counts. With the same data as the louder_than
// test, Janis's count of 2 is less than Jerry's count of 3.
//
// Language features demonstrated:
//   - 'quieter_than' keyword as the less-than (<) operator
//   - numeric attribute comparison produces a boolean result
//   - then-body executes when quieter_than comparison yields true
func TestExecute_QuieterThan_AlbumCount(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["circle of friends"]
jerry: "Jerry Garcia"
janis: "Janis Joplin"

["albums"]
jerry: { "Workingman's Dead" "American Beauty" "Europe 72" }
janis: { "Kozmic Blues" "Pearl" }

["jam"]
suppose janis.albumcount quieter_than jerry.albumcount
    say "Janis has fewer albums"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "Janis has fewer albums\n", out.String())
}

// TestExecute_Has_Present verifies that the 'has' operator returns true when
// the given title exists in the artist's album collection. The compiler
// resolves 'has' entirely at compile time against the albums section.
//
// Language features demonstrated:
//   - 'has' keyword for collection membership testing
//   - 'person.albums has "title"' syntax — left side is an Attr, right is a string
//   - then-body executes when the album is found in the collection
func TestExecute_Has_Present(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["circle of friends"]
jerry: "Jerry Garcia"

["albums"]
jerry: { "Workingman's Dead" "American Beauty" "Europe 72" }

["jam"]
suppose jerry.albums has "American Beauty"
    say "Found American Beauty"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "Found American Beauty\n", out.String())
}

// TestExecute_Has_Absent verifies that the 'has' operator returns false when
// the given title is not in the artist's collection, causing the
// otherwise-branch to execute.
//
// Language features demonstrated:
//   - 'has' returning false when the title is absent from the collection
//   - otherwise-branch selected when has-check yields false
//   - compile-time resolution means absent titles cost zero runtime branches
func TestExecute_Has_Absent(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["circle of friends"]
jerry: "Jerry Garcia"

["albums"]
jerry: { "Workingman's Dead" "American Beauty" "Europe 72" }

["jam"]
suppose jerry.albums has "Dark Side"
    say "Found it"
otherwise
    say "Not found"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "Not found\n", out.String())
}

// TestExecute_NameResolution verifies that the '.name' attribute on a person
// resolves to the display name declared in the "circle of friends" section.
//
// Language features demonstrated:
//   - ["circle of friends"] section mapping short keys to full display names
//   - 'person.name' attribute access in a say statement
//   - name string is interned as an LLVM global and passed to printf at runtime
func TestExecute_NameResolution(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["circle of friends"]
jerry: "Jerry Garcia"

["jam"]
say jerry.name
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "Jerry Garcia\n", out.String())
}

// TestExecute_MultipleArgs_SameLine verifies that a say statement with
// multiple arguments prints all of them on a single line with no separator,
// followed by exactly one trailing newline.
//
// The format string emitted by the compiler is "%s%s%s\n" (one specifier per
// argument, no spaces), so "Hello, " + jerry.name + "!" concatenate directly.
//
// Language features demonstrated:
//   - multi-argument say: say arg1 arg2 arg3
//   - mixing string literals and attribute references in a single say
//   - all arguments land on the same output line without intervening spaces
func TestExecute_MultipleArgs_SameLine(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["circle of friends"]
jerry: "Jerry Garcia"

["jam"]
say "Hello, " jerry.name "!"
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "Hello, Jerry Garcia!\n", out.String())
}

// TestExecute_Variable_From_Comparison verifies that the result of a
// comparison expression can be captured with 'becomes' and later used as a
// boolean condition. Here jerry.albumcount louder_than janis.albumcount yields
// copacetic (true), which is stored in x and then tested with
// 'vibes_like copacetic'.
//
// Language features demonstrated:
//   - storing a comparison result into a variable with 'becomes'
//   - using a comparison-derived variable as the condition of a suppose block
//   - 'vibes_like copacetic' testing a variable known to hold a comparison result
func TestExecute_Variable_From_Comparison(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["circle of friends"]
jerry: "Jerry Garcia"
janis: "Janis Joplin"

["albums"]
jerry: { "Workingman's Dead" "American Beauty" "Europe 72" }
janis: { "Kozmic Blues" "Pearl" }

["jam"]
x becomes jerry.albumcount louder_than janis.albumcount
suppose x vibes_like copacetic
    say "jerry wins"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out) // Pass the test buffer here
	require.NoError(t, err)
	assert.Equal(t, "jerry wins\n", out.String())
}

// TestExecute_CompleteProgram exercises all major Ripple language features
// together in a single realistic program. It reads like a real Ripple script
// and is the primary reference example for developers learning the language.
//
// Program sections:
//
//	["circle of friends"]
//	  Declares two artists — jerry (3 albums) and janis (2 albums) — with
//	  their full display names. These are used in name resolution and album
//	  count comparisons throughout the jam section.
//
//	["albums"]
//	  Assigns literal title collections to each artist. The compiler uses
//	  these at compile time to resolve albumcount and has expressions.
//
//	["jam"] — statement blocks, each testing a different language feature:
//
//	  Block 1 — plain say:
//	    Prints a report header. Demonstrates the simplest say statement.
//
//	  Block 2 — louder_than:
//	    jerry.albumcount (3) louder_than janis.albumcount (2) → true.
//	    Prints "Jerry has more albums".
//
//	  Block 3 — quieter_than:
//	    janis.albumcount (2) quieter_than jerry.albumcount (3) → true.
//	    Prints "Janis has fewer albums".
//
//	  Block 4 — has, album present:
//	    jerry.albums has "American Beauty" → true (title is in the collection).
//	    Prints "Found American Beauty".
//
//	  Block 5 — has, album absent + otherwise:
//	    jerry.albums has "Dark Side" → false (title not in collection).
//	    Falls through to otherwise; prints "Dark Side not found".
//
//	  Block 6 — copacetic assignment + suppose/otherwise:
//	    vibe becomes copacetic, then suppose vibe vibes_like copacetic → true branch.
//	    Prints "Golden vibes detected"; the otherwise-branch is skipped.
//
//	  Block 7 — harshing_the_vibe_of:
//	    vibe (copacetic) harshing_the_vibe_of harsh → true (copacetic != harsh).
//	    Prints "Not muddy at all".
//
// Expected output lines (in order):
//
//	"--- Ripple Report ---"
//	"Jerry has more albums"
//	"Janis has fewer albums"
//	"Found American Beauty"
//	"Dark Side not found"
//	"Golden vibes detected"
//	"Not muddy at all"
func TestExecute_CompleteProgram(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["circle of friends"]
jerry: "Jerry Garcia"
janis: "Janis Joplin"

["albums"]
jerry: { "Workingman's Dead" "American Beauty" "Europe 72" }
janis: { "Kozmic Blues" "Pearl" }

["jam"]
say "--- Ripple Report ---"

suppose jerry.albumcount louder_than janis.albumcount
    say "Jerry has more albums"
enough

suppose janis.albumcount quieter_than jerry.albumcount
    say "Janis has fewer albums"
enough

suppose jerry.albums has "American Beauty"
    say "Found American Beauty"
enough

suppose jerry.albums has "Dark Side"
    say "Found Dark Side"
otherwise
    say "Dark Side not found"
enough

vibe becomes copacetic
suppose vibe vibes_like copacetic
    say "Golden vibes detected"
otherwise
    say "Muddy vibes"
enough

suppose vibe harshing_the_vibe_of harsh
    say "Not muddy at all"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out)
	require.NoError(t, err)

	assert.True(t, strings.Contains(out.String(), "--- Ripple Report ---"), "expected report header line")
	assert.True(t, strings.Contains(out.String(), "Jerry has more albums"), "expected louder_than result")
	assert.True(t, strings.Contains(out.String(), "Janis has fewer albums"), "expected quieter_than result")
	assert.True(t, strings.Contains(out.String(), "Found American Beauty"), "expected has-present result")
	assert.True(t, strings.Contains(out.String(), "Dark Side not found"), "expected has-absent otherwise result")
	assert.True(t, strings.Contains(out.String(), "Golden vibes detected"), "expected copacetic then-branch")
	assert.False(t, strings.Contains(out.String(), "Muddy vibes"), "expected copacetic otherwise-branch to be skipped")
	assert.True(t, strings.Contains(out.String(), "Not muddy at all"), "expected harshing_the_vibe_of result")
}

// TestExecute_And_BothTrue verifies that the 'and' operator evaluates to true
// when both operands are copacetic (true), causing the then-branch to execute.
//
// Language features demonstrated:
//   - 'and' keyword as the logical AND (&&) operator between two i1 booleans
//   - suppose condition using 'and' between two boolean variables
//   - then-body executes when both sides of 'and' are copacetic
func TestExecute_And_BothTrue(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["jam"]
a becomes copacetic
b becomes copacetic
suppose a and b
    say "both golden"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out)

	require.NoError(t, err)
	assert.Equal(t, "both golden\n", out.String())
}

// TestExecute_Or_OneFalse verifies that the 'or' operator evaluates to true
// when at least one operand is copacetic, causing the then-branch to execute
// even though the first variable is harsh (false).
//
// Language features demonstrated:
//   - 'or' keyword as the logical OR (||) operator between two i1 booleans
//   - suppose condition using 'or' between a harsh and a copacetic variable
//   - then-body executes when at least one side of 'or' is copacetic
func TestExecute_Or_OneFalse(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["jam"]
a becomes harsh
b becomes copacetic
suppose a or b
    say "at least one"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out)

	require.NoError(t, err)
	assert.Equal(t, "at least one\n", out.String())
}

// TestExecute_And_OneFalse verifies that the 'and' operator evaluates to false
// when one operand is harsh, causing the then-branch to be skipped entirely
// and producing no output.
//
// Language features demonstrated:
//   - 'and' short-circuits to false when either operand is harsh
//   - then-body is suppressed when 'and' condition evaluates to false
//   - program produces empty stdout when no say statement is reached
func TestExecute_And_OneFalse(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["jam"]
a becomes harsh
b becomes copacetic
suppose a and b
    say "should not print"
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out)
	require.NoError(t, err)
	assert.Equal(t, "", out.String())
}

func TestExecute_Comments(t *testing.T) {
	t.Parallel()
	skipIfNoClang(t)

	src := `
["jam"]
a becomes harsh
# a becomes copacetic
# b becomes harsh
b becomes copacetic
suppose a and b
    say "should not print" # nothing to see here
enough
`
	var out bytes.Buffer
	err := runner.Execute(src, &out)
	require.NoError(t, err)
	assert.Equal(t, "", out.String())
}
