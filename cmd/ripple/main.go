package main

import (
	"flag"
	"fmt"
	"os"

	"github.com/jeffscottbrown/ripple-lang/internal/runner"
)

func main() {
	verbose := flag.Bool("v", false, "Print generated LLVM IR instead of running")
	// NEW: Flag for the output binary path
	outputFile := flag.String("o", "", "Compile to a binary file at the specified path")
	flag.Parse()

	if flag.NArg() < 1 {
		fmt.Fprintln(os.Stderr, "Usage: ripple [-v] [-o output] <file.ripple>")
		os.Exit(1)
	}

	content, err := os.ReadFile(flag.Arg(0))
	if err != nil {
		fmt.Fprintf(os.Stderr, "error reading file: %v\n", err)
		os.Exit(1)
	}

	if *verbose {
		ir, err := runner.Compile(string(content))
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
			os.Exit(1)
		}
		fmt.Print(ir)
		return
	}

	// NEW: Handle the output flag
	if *outputFile != "" {
		err := runner.Build(string(content), *outputFile)
		if err != nil {
			fmt.Fprintln(os.Stderr, err)
			os.Exit(1)
		}
		return
	}

	// In main.go
	err = runner.Execute(string(content), os.Stdout)
	if err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
	// No need to print 'output' here; it already happened in real-time!
}
