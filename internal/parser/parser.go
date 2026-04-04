package parser

import (
	"github.com/jeffscottbrown/ripple-lang/internal/ast"
)

func Parse(input string) (*ast.Program, error) {
	return ast.Parser.ParseString("", input)
}
