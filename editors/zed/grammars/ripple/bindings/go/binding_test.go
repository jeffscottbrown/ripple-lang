package tree_sitter_ripple_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-ripple"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_ripple.Language())
	if language == nil {
		t.Errorf("Error loading Ripple grammar")
	}
}
