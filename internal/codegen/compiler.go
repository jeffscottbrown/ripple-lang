package codegen

import (
	"errors"
	"fmt"
	"runtime"

	"github.com/jeffscottbrown/ripple-lang/internal/ast"
	"github.com/llir/llvm/ir"
	"github.com/llir/llvm/ir/constant"
	"github.com/llir/llvm/ir/types"
	"github.com/llir/llvm/ir/value"
)

// Static error definitions for Ripple semantics.
var (
	ErrDuplicateSection = errors.New("duplicate section")
	ErrUndefined        = errors.New("variable or artist not defined")
	ErrUnknownArtist    = errors.New("artist is not in your circle of friends")
	ErrInvalidProperty  = errors.New("artist does not have that property")
)

type Compiler struct {
	module *ir.Module
	main   *ir.Func
	entry  *ir.Block

	// Data storage from parsing phase
	names  map[string]string
	albums map[string][]string

	// Symbol table for LLVM IR objects
	vars map[string]*ir.InstAlloca

	// Standard Library Function Declarations
	printf  *ir.Func
	fprintf *ir.Func
	fflush  *ir.Func
	stderr  value.Value

	blockIdx int
}

func New() *Compiler {
	return &Compiler{
		names:  make(map[string]string),
		albums: make(map[string][]string),
		vars:   make(map[string]*ir.InstAlloca),
	}
}

func (c *Compiler) Compile(prog *ast.Program) (string, error) {
	c.reset()

	c.printf = c.module.NewFunc("printf", types.I32, ir.NewParam("format", types.I8Ptr))
	c.printf.Sig.Variadic = true

	c.fprintf = c.module.NewFunc("fprintf", types.I32, ir.NewParam("stream", types.I8Ptr), ir.NewParam("format", types.I8Ptr))
	c.fprintf.Sig.Variadic = true

	c.fflush = c.module.NewFunc("fflush", types.I32, ir.NewParam("stream", types.I8Ptr))

	if runtime.GOOS == "darwin" {
		c.stderr = c.module.NewGlobalDef("__stderrp", constant.NewUndef(types.I8Ptr))
	} else {
		c.stderr = c.module.NewGlobalDef("stderr", constant.NewUndef(types.I8Ptr))
	}

	// --- PHASE 1: DATA COLLECTION ---
	if err := c.collectData(prog); err != nil {
		return "", err
	}

	// --- PHASE 2: SEMANTIC VALIDATION ---
	for _, sec := range prog.Sections {
		if sec.Jam != nil {
			if err := c.validateStatements(sec.Jam.Statements, make(map[string]bool)); err != nil {
				return "", err
			}
		}
	}

	// --- PHASE 3: IR EMISSION ---
	c.main = c.module.NewFunc("main", types.I32)
	c.entry = c.main.NewBlock("entry")

	currentBlock := c.entry
	for _, sec := range prog.Sections {
		if sec.Jam != nil {
			currentBlock = c.emitStatements(sec.Jam.Statements, currentBlock)
		}
	}

	if currentBlock.Term == nil {
		currentBlock.NewRet(constant.NewInt(types.I32, 0))
	}

	return c.module.String(), nil
}

// collectData scans the AST for non-executable sections to build the environment.
func (c *Compiler) collectData(prog *ast.Program) error {
	seen := make(map[string]bool)
	for _, sec := range prog.Sections {
		var name string
		switch {
		case sec.Friends != nil:
			name = "circle of friends"
			if seen[name] {
				return fmt.Errorf("%w: [%s]", ErrDuplicateSection, name)
			}
			for _, e := range sec.Friends.Entries {
				c.names[e.Key] = e.Value
			}
		case sec.Albums != nil:
			name = "albums"
			if seen[name] {
				return fmt.Errorf("%w: [%s]", ErrDuplicateSection, name)
			}
			for _, e := range sec.Albums.Entries {
				c.albums[e.Key] = e.Collection
			}
		case sec.Jam != nil:
			name = "jam"
			if seen[name] {
				return fmt.Errorf("%w: [%s]", ErrDuplicateSection, name)
			}
		}
		seen[name] = true
	}
	return nil
}

func (c *Compiler) reset() {
	c.module = ir.NewModule()
	c.names = make(map[string]string)
	c.albums = make(map[string][]string)
	c.vars = make(map[string]*ir.InstAlloca)
}
