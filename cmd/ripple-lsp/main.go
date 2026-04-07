package main

import (
	"log"

	"github.com/tliron/commonlog"
	_ "github.com/tliron/commonlog/simple"
	"github.com/tliron/glsp/server"

	"github.com/jeffscottbrown/ripple-lang/internal/lsp"
)

const lsName = "ripple-lsp"

var version = "0.0.1"

func main() {
	commonlog.Configure(1, nil)

	handler := lsp.NewHandler(lsName, version)

	s := server.NewServer(handler, lsName, false)
	if err := s.RunStdio(); err != nil {
		log.Fatal(err)
	}
}
