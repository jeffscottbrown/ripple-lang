package codegen

import (
	"fmt"

	"github.com/jeffscottbrown/ripple-lang/internal/ast"
	"github.com/llir/llvm/ir"
	"github.com/llir/llvm/ir/constant"
	"github.com/llir/llvm/ir/enum"
	"github.com/llir/llvm/ir/types"
	"github.com/llir/llvm/ir/value"
)

// nolint:ireturn
func (c *Compiler) emitStatements(stmts []*ast.Statement, block *ir.Block) *ir.Block {
	currentBlock := block
	for _, stmt := range stmts {
		switch {
		case stmt.Print != nil:
			c.emitOutput(stmt.Print.Args, false, currentBlock)
		case stmt.Snitch != nil:
			c.emitOutput(stmt.Snitch.Args, true, currentBlock)
		case stmt.Assignment != nil:
			val := c.emitExpression(stmt.Assignment.Value, currentBlock)
			alloc, exists := c.vars[stmt.Assignment.Target]
			if !exists {
				alloc = c.entry.NewAlloca(types.I1)
				c.vars[stmt.Assignment.Target] = alloc
			}
			currentBlock.NewStore(val, alloc)
		case stmt.Conditional != nil:
			currentBlock = c.emitConditional(stmt.Conditional, currentBlock)
		}
	}
	return currentBlock
}

func (c *Compiler) emitOutput(expressions []*ast.Expression, isStderr bool, block *ir.Block) {
	format := ""
	var args []value.Value
	for _, expr := range expressions {
		val := c.emitTerm(expr.Left, block)
		args = append(args, val)
		if val.Type().Equal(types.I8Ptr) {
			format += "%s"
		} else {
			format += "%d"
		}
	}
	format += "\x0A\x00"

	content := constant.NewCharArrayFromString(format)
	cType := types.NewArray(uint64(len(format)), types.I8)
	fmtStr := c.module.NewGlobalDef("", content)
	fmtPtr := block.NewGetElementPtr(cType, fmtStr, constant.NewInt(types.I32, 0), constant.NewInt(types.I32, 0))

	if isStderr {
		stderrStream := block.NewLoad(types.I8Ptr, c.stderr)
		callArgs := append([]value.Value{stderrStream, fmtPtr}, args...)
		block.NewCall(c.fprintf, callArgs...)
	} else {
		callArgs := append([]value.Value{fmtPtr}, args...)
		block.NewCall(c.printf, callArgs...)
		block.NewCall(c.fflush, constant.NewNull(types.I8Ptr))
	}
}

// nolint:ireturn
func (c *Compiler) emitExpression(expr *ast.Expression, block *ir.Block) value.Value {
	if expr.Op == "has" {
		artist := ""
		if expr.Left.Attr != nil {
			artist = expr.Left.Attr.Name
		} else if expr.Left.Ident != nil {
			artist = *expr.Left.Ident
		}

		if artist != "" && expr.Right != nil && expr.Right.Str != nil {
			target := *expr.Right.Str
			list := c.albums[artist]
			for _, album := range list {
				if album == target {
					return constant.NewInt(types.I1, 1)
				}
			}
		}
		return constant.NewInt(types.I1, 0)
	}

	left := c.emitTerm(expr.Left, block)
	if expr.Op == "" {
		return left
	}
	right := c.emitTerm(expr.Right, block)

	switch expr.Op {
	case "louder_than":
		return block.NewICmp(enum.IPredSGT, left, right)
	case "quieter_than":
		return block.NewICmp(enum.IPredSLT, left, right)
	case "vibes_like":
		return block.NewICmp(enum.IPredEQ, left, right)
	case "harshing_the_vibe_of":
		return block.NewICmp(enum.IPredNE, left, right)
	case "and":
		return block.NewAnd(left, right)
	case "or":
		return block.NewOr(left, right)
	}
	return constant.NewInt(types.I1, 0)
}

// nolint:ireturn
func (c *Compiler) emitTerm(term *ast.Term, block *ir.Block) value.Value {
	switch {
	case term.Str != nil:
		s := *term.Str + "\x00"
		cType := types.NewArray(uint64(len(s)), types.I8)
		strGlobal := c.module.NewGlobalDef("", constant.NewCharArrayFromString(s))
		return block.NewGetElementPtr(cType, strGlobal, constant.NewInt(types.I32, 0), constant.NewInt(types.I32, 0))
	case term.Bool != nil:
		var val int64
		if *term.Bool == "copacetic" {
			val = 1
		}
		return constant.NewInt(types.I1, val)
	case term.Ident != nil:
		if alloc, ok := c.vars[*term.Ident]; ok {
			return block.NewLoad(types.I1, alloc)
		}
	case term.Attr != nil:
		switch term.Attr.Prop {
		case "name":
			val := c.names[term.Attr.Name] + "\x00"
			cType := types.NewArray(uint64(len(val)), types.I8)
			strGlobal := c.module.NewGlobalDef("", constant.NewCharArrayFromString(val))
			return block.NewGetElementPtr(cType, strGlobal, constant.NewInt(types.I32, 0), constant.NewInt(types.I32, 0))
		case "albumcount":
			return constant.NewInt(types.I32, int64(len(c.albums[term.Attr.Name])))
		}
	}
	return constant.NewInt(types.I32, 0)
}

func (c *Compiler) emitConditional(cond *ast.Conditional, block *ir.Block) *ir.Block {
	i := c.blockIdx
	c.blockIdx++

	thenBlock := c.main.NewBlock(fmt.Sprintf("then.%d", i))
	mergeBlock := c.main.NewBlock(fmt.Sprintf("merge.%d", i))

	condVal := c.emitExpression(cond.Condition, block)

	if len(cond.Otherwise) > 0 {
		elseBlock := c.main.NewBlock(fmt.Sprintf("else.%d", i))
		block.NewCondBr(condVal, thenBlock, elseBlock)

		lastElse := c.emitStatements(cond.Otherwise, elseBlock)
		if lastElse.Term == nil {
			lastElse.NewBr(mergeBlock)
		}
	} else {
		block.NewCondBr(condVal, thenBlock, mergeBlock)
	}

	lastThen := c.emitStatements(cond.Body, thenBlock)
	if lastThen.Term == nil {
		lastThen.NewBr(mergeBlock)
	}

	return mergeBlock
}
