package parser_test

import (
	"testing"

	"github.com/jeffscottbrown/ripple-lang/internal/parser"
	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
)

// TestParse_ThreeSections verifies that a program containing all three canonical
// section headers is parsed into exactly three Sections with the correct names.
func TestParse_ThreeSections(t *testing.T) {
	code := `["circle of friends"]
["albums"]
["jam"]`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 3)
	assert.Equal(t, "circle of friends", prog.Sections[0].Name)
	assert.Equal(t, "albums", prog.Sections[1].Name)
	assert.Equal(t, "jam", prog.Sections[2].Name)
}

// TestParse_Entry_SimpleValue verifies that a key-value entry with a quoted string
// produces an Entry with Key and Value set, and an empty Collection.
func TestParse_Entry_SimpleValue(t *testing.T) {
	code := `["circle of friends"]
jerry: "Jerry Garcia"`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)
	require.Len(t, prog.Sections[0].Entries, 1)

	entry := prog.Sections[0].Entries[0]
	assert.Equal(t, "jerry", entry.Key)
	assert.Equal(t, "Jerry Garcia", entry.Value)
	assert.Empty(t, entry.Collection)
}

// TestParse_Entry_Collection verifies that a brace-enclosed list of strings produces
// an Entry with the correct Collection slice and an empty Value.
func TestParse_Entry_Collection(t *testing.T) {
	code := `["albums"]
jerry: { "A" "B" "C" }`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)
	require.Len(t, prog.Sections[0].Entries, 1)

	entry := prog.Sections[0].Entries[0]
	assert.Equal(t, "jerry", entry.Key)
	assert.Empty(t, entry.Value)
	assert.Equal(t, []string{"A", "B", "C"}, entry.Collection)
}

// TestParse_Statement_Assignment_Copacetic verifies that "vibe becomes copacetic" produces
// an Assignment whose expression's Term carries Bool == "copacetic".
func TestParse_Statement_Assignment_Copacetic(t *testing.T) {
	code := `["jam"]
vibe becomes copacetic`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	stmts := prog.Sections[0].Statements
	require.Len(t, stmts, 1)

	a := stmts[0].Assignment
	require.NotNil(t, a)
	assert.Equal(t, "vibe", a.Target)
	require.NotNil(t, a.Value)
	require.NotNil(t, a.Value.Left)
	require.NotNil(t, a.Value.Left.Bool)
	assert.Equal(t, "copacetic", *a.Value.Left.Bool)
}

// TestParse_Statement_Assignment_Harsh verifies that "vibe becomes harsh" produces
// an Assignment whose expression's Term carries Bool == "harsh".
func TestParse_Statement_Assignment_Harsh(t *testing.T) {
	code := `["jam"]
vibe becomes harsh`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	stmts := prog.Sections[0].Statements
	require.Len(t, stmts, 1)

	a := stmts[0].Assignment
	require.NotNil(t, a)
	assert.Equal(t, "vibe", a.Target)
	require.NotNil(t, a.Value)
	require.NotNil(t, a.Value.Left)
	require.NotNil(t, a.Value.Left.Bool)
	assert.Equal(t, "harsh", *a.Value.Left.Bool)
}

// TestParse_Statement_Print_SingleLiteral verifies that "say "hello"" produces a
// Print statement with exactly one Str argument equal to "hello".
func TestParse_Statement_Print_SingleLiteral(t *testing.T) {
	code := `["jam"]
say "hello"`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	stmts := prog.Sections[0].Statements
	require.Len(t, stmts, 1)

	p := stmts[0].Print
	require.NotNil(t, p)
	require.Len(t, p.Args, 1)
	require.NotNil(t, p.Args[0])
	require.NotNil(t, p.Args[0].Left)
	require.NotNil(t, p.Args[0].Left.Str)
	assert.Equal(t, "hello", *p.Args[0].Left.Str)
}

// TestParse_Statement_Print_MultipleArgs verifies that "say "a" "b" "c"" produces a
// Print statement with three separate Str arguments in order.
func TestParse_Statement_Print_MultipleArgs(t *testing.T) {
	code := `["jam"]
say "a" "b" "c"`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	stmts := prog.Sections[0].Statements
	require.Len(t, stmts, 1)

	p := stmts[0].Print
	require.NotNil(t, p)
	require.Len(t, p.Args, 3)

	require.NotNil(t, p.Args[0].Left.Str)
	assert.Equal(t, "a", *p.Args[0].Left.Str)

	require.NotNil(t, p.Args[1].Left.Str)
	assert.Equal(t, "b", *p.Args[1].Left.Str)

	require.NotNil(t, p.Args[2].Left.Str)
	assert.Equal(t, "c", *p.Args[2].Left.Str)
}

// TestParse_Conditional_NoOtherwise verifies that a suppose…enough block with no
// otherwise branch produces a Conditional with a Body and a nil Otherwise slice.
func TestParse_Conditional_NoOtherwise(t *testing.T) {
	code := `["jam"]
suppose vibe vibes_like copacetic
  say "yes"
enough`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	stmts := prog.Sections[0].Statements
	require.Len(t, stmts, 1)

	c := stmts[0].Conditional
	require.NotNil(t, c)
	assert.Len(t, c.Body, 1)
	assert.Empty(t, c.Otherwise)
}

// TestParse_Conditional_WithOtherwise verifies that a suppose…otherwise…enough block
// produces a Conditional with a non-empty Otherwise slice.
func TestParse_Conditional_WithOtherwise(t *testing.T) {
	code := `["jam"]
suppose vibe vibes_like copacetic
  say "yes"
otherwise
  say "no"
enough`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	stmts := prog.Sections[0].Statements
	require.Len(t, stmts, 1)

	c := stmts[0].Conditional
	require.NotNil(t, c)
	assert.Len(t, c.Body, 1)
	require.Len(t, c.Otherwise, 1)

	// The otherwise branch should contain the print statement.
	otherwisePrint := c.Otherwise[0].Print
	require.NotNil(t, otherwisePrint)
	require.Len(t, otherwisePrint.Args, 1)
	require.NotNil(t, otherwisePrint.Args[0].Left.Str)
	assert.Equal(t, "no", *otherwisePrint.Args[0].Left.Str)
}

// TestParse_Operator_VibesLike verifies that the "vibes_like" keyword between two terms
// produces an Expression with Op == "vibes_like".
func TestParse_Operator_VibesLike(t *testing.T) {
	code := `["jam"]
suppose vibe vibes_like copacetic
  say "yes"
enough`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	c := prog.Sections[0].Statements[0].Conditional
	require.NotNil(t, c)
	require.NotNil(t, c.Condition)
	assert.Equal(t, "vibes_like", c.Condition.Op)
	require.NotNil(t, c.Condition.Left)
	require.NotNil(t, c.Condition.Left.Ident)
	assert.Equal(t, "vibe", *c.Condition.Left.Ident)
	require.NotNil(t, c.Condition.Right)
	require.NotNil(t, c.Condition.Right.Bool)
	assert.Equal(t, "copacetic", *c.Condition.Right.Bool)
}

// TestParse_Operator_HarshingTheVibeOf verifies that the "harshing_the_vibe_of" keyword
// between two terms produces an Expression with Op == "harshing_the_vibe_of".
func TestParse_Operator_HarshingTheVibeOf(t *testing.T) {
	code := `["jam"]
suppose vibe harshing_the_vibe_of copacetic
  say "no"
enough`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	c := prog.Sections[0].Statements[0].Conditional
	require.NotNil(t, c)
	require.NotNil(t, c.Condition)
	assert.Equal(t, "harshing_the_vibe_of", c.Condition.Op)
	require.NotNil(t, c.Condition.Left)
	require.NotNil(t, c.Condition.Left.Ident)
	assert.Equal(t, "vibe", *c.Condition.Left.Ident)
	require.NotNil(t, c.Condition.Right)
	require.NotNil(t, c.Condition.Right.Bool)
	assert.Equal(t, "copacetic", *c.Condition.Right.Bool)
}

// TestParse_Operator_LouderThan verifies that the "louder_than" keyword between two ident
// terms produces an Expression with Op == "louder_than" and correctly bound operands.
func TestParse_Operator_LouderThan(t *testing.T) {
	code := `["jam"]
suppose x louder_than y
  say "big"
enough`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	c := prog.Sections[0].Statements[0].Conditional
	require.NotNil(t, c)
	require.NotNil(t, c.Condition)
	assert.Equal(t, "louder_than", c.Condition.Op)

	require.NotNil(t, c.Condition.Left)
	require.NotNil(t, c.Condition.Left.Ident)
	assert.Equal(t, "x", *c.Condition.Left.Ident)

	require.NotNil(t, c.Condition.Right)
	require.NotNil(t, c.Condition.Right.Ident)
	assert.Equal(t, "y", *c.Condition.Right.Ident)
}

// TestParse_Operator_QuieterThan verifies that the "quieter_than" keyword between two ident
// terms produces an Expression with Op == "quieter_than" and correctly bound operands.
func TestParse_Operator_QuieterThan(t *testing.T) {
	code := `["jam"]
suppose x quieter_than y
  say "small"
enough`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	c := prog.Sections[0].Statements[0].Conditional
	require.NotNil(t, c)
	require.NotNil(t, c.Condition)
	assert.Equal(t, "quieter_than", c.Condition.Op)

	require.NotNil(t, c.Condition.Left)
	require.NotNil(t, c.Condition.Left.Ident)
	assert.Equal(t, "x", *c.Condition.Left.Ident)

	require.NotNil(t, c.Condition.Right)
	require.NotNil(t, c.Condition.Right.Ident)
	assert.Equal(t, "y", *c.Condition.Right.Ident)
}

// TestParse_Operator_Has verifies that the "has" keyword in a collection-membership
// check produces Op == "has", with an Attr on the left and a Str on the right.
func TestParse_Operator_Has(t *testing.T) {
	code := `["jam"]
suppose jerry.albums has "X"
  say "found"
enough`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	c := prog.Sections[0].Statements[0].Conditional
	require.NotNil(t, c)
	require.NotNil(t, c.Condition)
	assert.Equal(t, "has", c.Condition.Op)

	require.NotNil(t, c.Condition.Left)
	require.NotNil(t, c.Condition.Left.Attr)
	assert.Equal(t, "jerry", c.Condition.Left.Attr.Name)
	assert.Equal(t, "albums", c.Condition.Left.Attr.Prop)

	require.NotNil(t, c.Condition.Right)
	require.NotNil(t, c.Condition.Right.Str)
	assert.Equal(t, "X", *c.Condition.Right.Str)
}

// TestParse_AttrAccess_Name verifies that the dotted identifier "jerry.name" is
// parsed as an Attr term with Name == "jerry" and Prop == "name".
func TestParse_AttrAccess_Name(t *testing.T) {
	code := `["jam"]
result becomes jerry.name`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	stmts := prog.Sections[0].Statements
	require.Len(t, stmts, 1)

	a := stmts[0].Assignment
	require.NotNil(t, a)
	assert.Equal(t, "result", a.Target)
	require.NotNil(t, a.Value)
	require.NotNil(t, a.Value.Left)
	require.NotNil(t, a.Value.Left.Attr)
	assert.Equal(t, "jerry", a.Value.Left.Attr.Name)
	assert.Equal(t, "name", a.Value.Left.Attr.Prop)
}

// TestParse_AttrAccess_Albumcount verifies that the dotted identifier "jerry.albumcount"
// is parsed as an Attr term with Name == "jerry" and Prop == "albumcount".
func TestParse_AttrAccess_Albumcount(t *testing.T) {
	code := `["jam"]
result becomes jerry.albumcount`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	stmts := prog.Sections[0].Statements
	require.Len(t, stmts, 1)

	a := stmts[0].Assignment
	require.NotNil(t, a)
	assert.Equal(t, "result", a.Target)
	require.NotNil(t, a.Value)
	require.NotNil(t, a.Value.Left)
	require.NotNil(t, a.Value.Left.Attr)
	assert.Equal(t, "jerry", a.Value.Left.Attr.Name)
	assert.Equal(t, "albumcount", a.Value.Left.Attr.Prop)
}

// TestParse_BooleanLiterals verifies that the keywords "copacetic" and "harsh" each parse
// as Term.Bool values of "copacetic" and "harsh" respectively across two assignments.
func TestParse_BooleanLiterals(t *testing.T) {
	code := `["jam"]
a becomes copacetic
b becomes harsh`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	stmts := prog.Sections[0].Statements
	require.Len(t, stmts, 2)

	copaceticAssign := stmts[0].Assignment
	require.NotNil(t, copaceticAssign)
	require.NotNil(t, copaceticAssign.Value)
	require.NotNil(t, copaceticAssign.Value.Left)
	require.NotNil(t, copaceticAssign.Value.Left.Bool)
	assert.Equal(t, "copacetic", *copaceticAssign.Value.Left.Bool)
	assert.Nil(t, copaceticAssign.Value.Left.Str)
	assert.Nil(t, copaceticAssign.Value.Left.Ident)
	assert.Nil(t, copaceticAssign.Value.Left.Attr)

	harshAssign := stmts[1].Assignment
	require.NotNil(t, harshAssign)
	require.NotNil(t, harshAssign.Value)
	require.NotNil(t, harshAssign.Value.Left)
	require.NotNil(t, harshAssign.Value.Left.Bool)
	assert.Equal(t, "harsh", *harshAssign.Value.Left.Bool)
	assert.Nil(t, harshAssign.Value.Left.Str)
	assert.Nil(t, harshAssign.Value.Left.Ident)
	assert.Nil(t, harshAssign.Value.Left.Attr)
}

// TestParse_ComplexProgram exercises a complete three-section program with string
// entries, a collection entry, an assignment, and a conditional with an otherwise
// branch. It asserts section count, jam statement count, and that the first jam
// statement is a Conditional.
func TestParse_ComplexProgram(t *testing.T) {
	code := `["circle of friends"]
jerry: "Jerry Garcia"
bob: "Bob Weir"

["albums"]
jerry: { "American Beauty" "Blues for Allah" "Workingman's Dead" }

["jam"]
suppose vibe vibes_like copacetic
  say "Smooth water"
otherwise
  say "Rough waves"
enough
vibe becomes copacetic`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 3)

	// "circle of friends" section: two named string entries.
	friends := prog.Sections[0]
	assert.Equal(t, "circle of friends", friends.Name)
	require.Len(t, friends.Entries, 2)
	assert.Equal(t, "jerry", friends.Entries[0].Key)
	assert.Equal(t, "Jerry Garcia", friends.Entries[0].Value)
	assert.Equal(t, "bob", friends.Entries[1].Key)
	assert.Equal(t, "Bob Weir", friends.Entries[1].Value)

	// "albums" section: one collection entry with three elements.
	albums := prog.Sections[1]
	assert.Equal(t, "albums", albums.Name)
	require.Len(t, albums.Entries, 1)
	assert.Equal(t, "jerry", albums.Entries[0].Key)
	assert.Equal(t, []string{"American Beauty", "Blues for Allah", "Workingman's Dead"}, albums.Entries[0].Collection)

	// "jam" section: two statements; first must be a Conditional.
	jam := prog.Sections[2]
	assert.Equal(t, "jam", jam.Name)
	require.Len(t, jam.Statements, 2)

	cond := jam.Statements[0].Conditional
	require.NotNil(t, cond, "first jam statement must be a Conditional")
	require.NotNil(t, cond.Condition)
	assert.Equal(t, "vibes_like", cond.Condition.Op)
	require.Len(t, cond.Body, 1)
	require.Len(t, cond.Otherwise, 1)

	bodyPrint := cond.Body[0].Print
	require.NotNil(t, bodyPrint)
	require.Len(t, bodyPrint.Args, 1)
	require.NotNil(t, bodyPrint.Args[0].Left.Str)
	assert.Equal(t, "Smooth water", *bodyPrint.Args[0].Left.Str)

	otherwisePrint := cond.Otherwise[0].Print
	require.NotNil(t, otherwisePrint)
	require.Len(t, otherwisePrint.Args, 1)
	require.NotNil(t, otherwisePrint.Args[0].Left.Str)
	assert.Equal(t, "Rough waves", *otherwisePrint.Args[0].Left.Str)

	// Second statement in jam is an Assignment.
	assign := jam.Statements[1].Assignment
	require.NotNil(t, assign, "second jam statement must be an Assignment")
	assert.Equal(t, "vibe", assign.Target)
	require.NotNil(t, assign.Value.Left.Bool)
	assert.Equal(t, "copacetic", *assign.Value.Left.Bool)
}
