package parser_test

import (
	"testing"

	"github.com/jeffscottbrown/ripple-lang/internal/parser"
	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
)

func TestParse_ThreeSections(t *testing.T) {
	code := `["circle of friends"]
["albums"]
["jam"]`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 3)

	// Check typed sections instead of a generic Name field
	assert.NotNil(t, prog.Sections[0].Friends)
	assert.Equal(t, "circle of friends", prog.Sections[0].Friends.Name)

	assert.NotNil(t, prog.Sections[1].Albums)
	assert.Equal(t, "albums", prog.Sections[1].Albums.Name)

	assert.NotNil(t, prog.Sections[2].Jam)
	assert.Equal(t, "jam", prog.Sections[2].Jam.Name)
}

func TestParse_Entry_SimpleValue(t *testing.T) {
	code := `["circle of friends"]
jerry: "Jerry Garcia"`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	friends := prog.Sections[0].Friends
	require.NotNil(t, friends)
	require.Len(t, friends.Entries, 1)

	entry := friends.Entries[0]
	assert.Equal(t, "jerry", entry.Key)
	assert.Equal(t, "Jerry Garcia", entry.Value)
}

func TestParse_Entry_Collection(t *testing.T) {
	code := `["albums"]
jerry: { "A" "B" "C" }`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 1)

	albums := prog.Sections[0].Albums
	require.NotNil(t, albums)
	require.Len(t, albums.Entries, 1)

	entry := albums.Entries[0]
	assert.Equal(t, "jerry", entry.Key)
	assert.Equal(t, []string{"A", "B", "C"}, entry.Collection)
}

func TestParse_Statement_Assignment_Copacetic(t *testing.T) {
	code := `["jam"]
vibe becomes copacetic`

	prog, err := parser.Parse(code)
	require.NoError(t, err)

	jam := prog.Sections[0].Jam
	require.NotNil(t, jam)
	require.Len(t, jam.Statements, 1)

	a := jam.Statements[0].Assignment
	require.NotNil(t, a)
	assert.Equal(t, "vibe", a.Target)
	assert.Equal(t, "copacetic", *a.Value.Left.Bool)
}

func TestParse_ComplexProgram(t *testing.T) {
	code := `["circle of friends"]
jerry: "Jerry Garcia"

["albums"]
jerry: { "American Beauty" }

["jam"]
say "hello"`

	prog, err := parser.Parse(code)
	require.NoError(t, err)
	require.Len(t, prog.Sections, 3)

	// Section 0: Friends
	friends := prog.Sections[0].Friends
	require.NotNil(t, friends)
	assert.Equal(t, "jerry", friends.Entries[0].Key)

	// Section 1: Albums
	albums := prog.Sections[1].Albums
	require.NotNil(t, albums)
	assert.Equal(t, "jerry", albums.Entries[0].Key)

	// Section 2: Jam
	jam := prog.Sections[2].Jam
	require.NotNil(t, jam)
	require.Len(t, jam.Statements, 1)
	assert.NotNil(t, jam.Statements[0].Print)
}
