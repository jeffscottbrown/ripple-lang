package codegen

import (
	"fmt"
	"runtime"
	"strings"

	"github.com/jeffscottbrown/ripple-lang/internal/ast"
)

func (c *Compiler) emitStatements(stmts []*ast.Statement) {
	for _, stmt := range stmts {
		switch {
		case stmt.Print != nil:
			c.emitOutput(stmt.Print.Args, false)
		case stmt.Snitch != nil:
			c.emitOutput(stmt.Snitch.Args, true)
		case stmt.Assignment != nil:
			val := c.emitExpression(stmt.Assignment.Value)
			c.vars[stmt.Assignment.Target] = true
			fmt.Fprintf(&c.fn, "  %%%s = alloca i1, align 1\n", stmt.Assignment.Target)
			fmt.Fprintf(&c.fn, "  store i1 %s, i1* %%%s, align 1\n", val.v, stmt.Assignment.Target)
		case stmt.Conditional != nil:
			c.emitConditional(stmt.Conditional)
		}
	}
}

func (c *Compiler) emitOutput(expressions []*ast.Expression, isStderr bool) {
	var args []typedVal
	for _, expr := range expressions {
		args = append(args, c.emitTerm(expr.Left))
	}

	var fmtBuf strings.Builder
	for _, a := range args {
		if a.t == "i8*" {
			fmtBuf.WriteString("%s")
		} else {
			fmtBuf.WriteString("%d")
		}
	}
	fmtBuf.WriteString("\\0A\\00")
	fmtStr := fmtBuf.String()

	fmtName, fmtSize := c.internString(fmtStr)
	fmtTmp := c.nextTmp()
	fmt.Fprintf(&c.fn, "  %%%s = getelementptr inbounds [%d x i8], [%d x i8]* @%s, i32 0, i32 0\n",
		fmtTmp, fmtSize, fmtSize, fmtName)

	if isStderr {
		symbol := "@stderr"
		if runtime.GOOS == targetOSDarwin {
			symbol = "@__stderrp"
		}
		errPtr := c.nextTmp()
		fmt.Fprintf(&c.fn, "  %%%s = load i8*, i8** %s, align 8\n", errPtr, symbol)
		fmt.Fprintf(&c.fn, "  call i32 (i8*, i8*, ...) @fprintf(i8* %%%s, i8* %%%s", errPtr, fmtTmp)
	} else {
		fmt.Fprintf(&c.fn, "  call i32 (i8*, ...) @printf(i8* %%%s", fmtTmp)
	}

	for _, a := range args {
		fmt.Fprintf(&c.fn, ", %s %s", a.t, a.v)
	}
	c.fn.WriteString(")\n")

	if !isStderr {
		fmt.Fprintf(&c.fn, "  call i32 @fflush(i8* null)\n")
	}
}

func (c *Compiler) emitConditional(cond *ast.Conditional) {
	labelIdx := c.tmpIdx
	c.tmpIdx++

	res := c.emitExpression(cond.Condition)
	thenLabel := fmt.Sprintf("then.%d", labelIdx)
	elseLabel := fmt.Sprintf("else.%d", labelIdx)
	mergeLabel := fmt.Sprintf("merge.%d", labelIdx)

	if len(cond.Otherwise) > 0 {
		fmt.Fprintf(&c.fn, "  br i1 %s, label %%%s, label %%%s\n", res.v, thenLabel, elseLabel)
	} else {
		fmt.Fprintf(&c.fn, "  br i1 %s, label %%%s, label %%%s\n", res.v, thenLabel, mergeLabel)
	}

	fmt.Fprintf(&c.fn, "%s:\n", thenLabel)
	c.emitStatements(cond.Body)
	fmt.Fprintf(&c.fn, "  br label %%%s\n", mergeLabel)

	if len(cond.Otherwise) > 0 {
		fmt.Fprintf(&c.fn, "%s:\n", elseLabel)
		c.emitStatements(cond.Otherwise)
		fmt.Fprintf(&c.fn, "  br label %%%s\n", mergeLabel)
	}
	fmt.Fprintf(&c.fn, "%s:\n", mergeLabel)
}

func (c *Compiler) emitExpression(expr *ast.Expression) typedVal {
	left := c.emitTerm(expr.Left)
	if expr.Op == "" {
		return left
	}
	right := c.emitTerm(expr.Right)
	tmp := c.nextTmp()

	switch expr.Op {
	case "louder_than":
		fmt.Fprintf(&c.fn, "  %%%s = icmp sgt %s %s, %s\n", tmp, left.t, left.v, right.v)
	case "quieter_than":
		fmt.Fprintf(&c.fn, "  %%%s = icmp slt %s %s, %s\n", tmp, left.t, left.v, right.v)
	case "vibes_like":
		fmt.Fprintf(&c.fn, "  %%%s = icmp eq %s %s, %s\n", tmp, left.t, left.v, right.v)
	case "harshing_the_vibe_of":
		fmt.Fprintf(&c.fn, "  %%%s = icmp ne %s %s, %s\n", tmp, left.t, left.v, right.v)
	case "and":
		fmt.Fprintf(&c.fn, "  %%%s = and i1 %s, %s\n", tmp, left.v, right.v)
	case "or":
		fmt.Fprintf(&c.fn, "  %%%s = or i1 %s, %s\n", tmp, left.v, right.v)
	case "has":
		var artist string
		// Safety check: is Left an Attr (jerry.albums)?
		if expr.Left.Attr != nil {
			artist = expr.Left.Attr.Name
		} else if expr.Left.Ident != nil {
			// Or is it a direct Ident (jerry)?
			artist = *expr.Left.Ident
		}

		// Safety check: is Right a string literal ("A")?
		if artist != "" && expr.Right != nil && expr.Right.Str != nil {
			target := *expr.Right.Str
			list := c.albums[artist]
			found := "0"
			for _, album := range list {
				if album == target {
					found = "1"
					break
				}
			}
			return typedVal{"i1", found}
		}
		// If the structure is weird, don't panic, just return false (harsh)
		return typedVal{"i1", "0"}
	}
	return typedVal{"i1", "%" + tmp}
}

func (c *Compiler) emitTerm(term *ast.Term) typedVal {
	switch {
	case term.Str != nil:
		name, size := c.internString(*term.Str + "\\00")
		tmp := c.nextTmp()
		fmt.Fprintf(&c.fn, "  %%%s = getelementptr inbounds [%d x i8], [%d x i8]* @%s, i32 0, i32 0\n",
			tmp, size, size, name)
		return typedVal{"i8*", "%" + tmp}
	case term.Bool != nil:
		val := "0"
		if *term.Bool == "copacetic" {
			val = "1"
		}
		return typedVal{"i1", val}
	case term.Ident != nil:
		tmp := c.nextTmp()
		fmt.Fprintf(&c.fn, "  %%%s = load i1, i1* %%%s, align 1\n", tmp, *term.Ident)
		return typedVal{"i1", "%" + tmp}
	case term.Attr != nil:
		if term.Attr.Prop == "name" {
			val := c.names[term.Attr.Name]
			name, size := c.internString(val + "\\00")
			tmp := c.nextTmp()
			fmt.Fprintf(&c.fn, "  %%%s = getelementptr inbounds [%d x i8], [%d x i8]* @%s, i32 0, i32 0\n",
				tmp, size, size, name)
			return typedVal{"i8*", "%" + tmp}
		}
		if term.Attr.Prop == "albumcount" {
			count := len(c.albums[term.Attr.Name])
			return typedVal{"i32", fmt.Sprintf("%d", count)}
		}
	}
	return typedVal{"i32", "0"}
}
