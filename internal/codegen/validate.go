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
		case stmt.Snitch != nil:
			for _, arg := range stmt.Snitch.Args {
				if err := c.validateExpr(arg, localVars); err != nil {
					return err
				}
			}
		case stmt.Conditional != nil:
			if err := c.validateExpr(stmt.Conditional.Condition, localVars); err != nil {
				return err
			}
			// Recursive calls for blocks
			if err := c.validateStatements(stmt.Conditional.Body, localVars); err != nil {
				return err
			}
			if err := c.validateStatements(stmt.Conditional.Otherwise, localVars); err != nil {
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
		// An identifier is valid if it's a local variable OR a known artist.
		_, isVar := localVars[*t.Ident]
		_, isArtist := c.names[*t.Ident]

		if !isVar && !isArtist {
			return fmt.Errorf("%w: %s", ErrUndefined, *t.Ident)
		}
	}
	if t.Attr != nil {
		if _, exists := c.names[t.Attr.Name]; !exists {
			return fmt.Errorf("%w: %s", ErrUnknownArtist, t.Attr.Name)
		}
		props := map[string]bool{"name": true, "albums": true, "albumcount": true}
		if !props[t.Attr.Prop] {
			return fmt.Errorf("%w: %s", ErrInvalidProperty, t.Attr.Prop)
		}
	}
	return nil
}
