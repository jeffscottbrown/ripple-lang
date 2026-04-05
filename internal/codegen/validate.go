package codegen

import (
	"fmt"

	"github.com/jeffscottbrown/ripple-lang/internal/ast"
)

func (c *Compiler) validateStatements(stmts []*ast.Statement, localVars map[string]bool) error {
	for _, stmt := range stmts {
		switch {
		case stmt.Assignment != nil:
			if err := c.validateExpr(stmt.Assignment.Value, localVars); err != nil {
				return err
			}
			localVars[stmt.Assignment.Target] = true
		case stmt.Print != nil:
			for _, arg := range stmt.Print.Args {
				if err := c.validateExpr(arg, localVars); err != nil {
					return err
				}
			}
		case stmt.Conditional != nil:
			// Check condition
			if err := c.validateExpr(stmt.Conditional.Condition, localVars); err != nil {
				return err
			}
			// Scope check: We create a copy of localVars so variables
			// defined inside a block don't leak out (standard scoping).
			innerVars := make(map[string]bool)
			for k, v := range localVars {
				innerVars[k] = v
			}

			if err := c.validateStatements(stmt.Conditional.Body, innerVars); err != nil {
				return err
			}
			if err := c.validateStatements(stmt.Conditional.Otherwise, innerVars); err != nil {
				return err
			}
		}
	}
	return nil
}

func (c *Compiler) validateExpr(e *ast.Expression, localVars map[string]bool) error {
	if err := c.validateTerm(e.Left, localVars); err != nil {
		return err
	}
	if e.Right != nil {
		return c.validateTerm(e.Right, localVars)
	}
	return nil
}

func (c *Compiler) validateTerm(t *ast.Term, localVars map[string]bool) error {
	if t.Ident != nil {
		name := *t.Ident
		_, isVar := localVars[name]
		_, isArtist := c.names[name]
		if !isVar && !isArtist {
			return fmt.Errorf("%w: %s", ErrUndefined, name)
		}
	}
	if t.Attr != nil {
		if _, exists := c.names[t.Attr.Name]; !exists {
			return fmt.Errorf("%w: %s", ErrUnknownArtist, t.Attr.Name)
		}
		// Ripple only supports 'name', 'albums', and 'albumcount'
		validProps := map[string]bool{"name": true, "albumcount": true, "albums": true}
		if !validProps[t.Attr.Prop] {
			return fmt.Errorf("%w: %s", ErrInvalidProperty, t.Attr.Prop)
		}
	}
	return nil
}
