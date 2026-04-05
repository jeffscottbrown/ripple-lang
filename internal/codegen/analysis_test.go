package codegen_test

import (
	"testing"

	"github.com/jeffscottbrown/ripple-lang/internal/codegen"
	"github.com/jeffscottbrown/ripple-lang/internal/parser"
	"github.com/stretchr/testify/assert"
	"github.com/stretchr/testify/require"
)

func TestCompiler_Analysis(t *testing.T) {
	tests := []struct {
		name     string
		code     string
		wantErr  error
		contains string
	}{
		{
			name: "Unknown Artist",
			code: `["jam"]
                   say bob.name`,
			contains: "artist is not in your circle of friends",
		},
		{
			name: "Invalid Property",
			code: `["circle of friends"]
                   jerry: "Jerry"
                   ["jam"]
                   say jerry.height`,
			contains: "artist does not have that property",
		},
		{
			name: "Undefined Variable",
			code: `["jam"]
                   suppose is_cool
                   say "yes"
                   enough`,
			contains: "variable or artist not defined",
		},
		{
			name: "Usage Before Assignment",
			code: `["jam"]
                   say vibe
                   vibe becomes copacetic`,
			contains: "variable or artist not defined: vibe",
		},
		{
			name: "Duplicate Section",
			code: `["jam"]
                   say "hi"
                   ["jam"]
                   say "bye"`,
			contains: "duplicate section: [jam]",
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			prog, err := parser.Parse(tt.code)
			require.NoError(t, err)

			_, err = codegen.New().Compile(prog)
			assert.Error(t, err)
			assert.ErrorContains(t, err, tt.contains)
		})
	}
}
