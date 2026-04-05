package runner

import (
	"bytes"
	"fmt"
	"io"
	"os"
	"os/exec"
	"path/filepath"
	"runtime"
	"strings"

	"github.com/jeffscottbrown/ripple-lang/internal/codegen"
	"github.com/jeffscottbrown/ripple-lang/internal/parser"
)

// Compile parses source as a Ripple program and returns the LLVM IR text.
func Compile(source string) (string, error) {
	prog, err := parser.Parse(source)
	if err != nil {
		return "", fmt.Errorf("parse: %w", err)
	}
	return codegen.New().Compile(prog)
}

// Execute now takes a writer for stdout.
func Execute(source string, stdout io.Writer) error {
	ir, err := Compile(source)
	if err != nil {
		return err
	}

	tmpDir, err := os.MkdirTemp("", "ripple-*")
	if err != nil {
		return fmt.Errorf("temp dir: %w", err)
	}
	defer os.RemoveAll(tmpDir)

	irFile := filepath.Join(tmpDir, "out.ll")
	binFile := filepath.Join(tmpDir, "out")

	if err := os.WriteFile(irFile, []byte(ir), 0644); err != nil {
		return fmt.Errorf("write IR: %w", err)
	}

	clangCmd := exec.Command("clang", clangArgs(irFile, binFile)...)
	if err := clangCmd.Run(); err != nil {
		return fmt.Errorf("compile error: %w", err)
	}

	runCmd := exec.Command(binFile)
	runCmd.Stdout = stdout    // Pipe binary stdout to our passed-in writer
	runCmd.Stderr = os.Stderr // Keep snitches going to stderr

	return runCmd.Run()
}

// clangArgs builds the argument list for clang, adding the macOS SDK sysroot
// when running on Darwin so the linker can locate libSystem.
func clangArgs(irFile, binFile string) []string {
	args := []string{"-Wno-override-module"}
	if runtime.GOOS == "darwin" {
		if out, err := exec.Command("xcrun", "--show-sdk-path").Output(); err == nil {
			args = append(args, "-isysroot", strings.TrimSpace(string(out)))
		}
	}
	return append(args, irFile, "-o", binFile)
}

// Build parses source, generates IR, and uses clang to create an executable at destPath.
func Build(source string, destPath string) error {
	ir, err := Compile(source)
	if err != nil {
		return err
	}

	// Create a temporary directory for the intermediate .ll file
	tmpDir, err := os.MkdirTemp("", "ripple-build-*")
	if err != nil {
		return fmt.Errorf("temp dir: %w", err)
	}
	defer os.RemoveAll(tmpDir)

	irFile := filepath.Join(tmpDir, "out.ll")
	if err := os.WriteFile(irFile, []byte(ir), 0644); err != nil {
		return fmt.Errorf("write IR: %w", err)
	}

	// Run clang to produce the binary at the requested destination
	clangCmd := exec.Command("clang", clangArgs(irFile, destPath)...)
	var clangStderr bytes.Buffer
	clangCmd.Stderr = &clangStderr

	if err := clangCmd.Run(); err != nil {
		return fmt.Errorf("compile: %w\n%s", err, clangStderr.String())
	}

	return nil
}
