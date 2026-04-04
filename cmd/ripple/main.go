package main

import (
	"flag"
	"fmt"
	"os"

	"github.com/jeffscottbrown/ripple-lang/internal/runner"
)

func main() {
	verbose := flag.Bool("v", false, "Print generated LLVM IR instead of running")
	flag.Parse()

	if flag.NArg() < 1 {
		fmt.Fprintln(os.Stderr, "Usage: ripple [-v] <file.ripple>")
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

	output, err := runner.Execute(string(content))
	if err != nil {
		fmt.Fprintln(os.Stderr, err)
		os.Exit(1)
	}
	fmt.Print(output)
}
