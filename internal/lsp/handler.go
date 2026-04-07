package lsp

import (
	"regexp"
	"sort"

	"github.com/tliron/glsp"
	protocol "github.com/tliron/glsp/protocol_3_16"

	"github.com/jeffscottbrown/ripple-lang/internal/parser"
)

var identifierRE = regexp.MustCompile(`[A-Za-z_][A-Za-z0-9_]*`)

type state struct {
	documents map[string]string
	handler   protocol.Handler
	lsName    string
	version   string
}

func NewHandler(lsName, version string) *protocol.Handler {
	s := &state{
		documents: map[string]string{},
		lsName:    lsName,
		version:   version,
	}

	s.handler = protocol.Handler{
		Initialize:             s.initialize,
		Initialized:            s.initialized,
		Shutdown:               s.shutdown,
		SetTrace:               s.setTrace,
		TextDocumentDidOpen:    s.didOpen,
		TextDocumentDidChange:  s.didChange,
		TextDocumentDidClose:   s.didClose,
		TextDocumentCompletion: s.completion,
	}

	return &s.handler
}

func (s *state) initialize(ctx *glsp.Context, params *protocol.InitializeParams) (any, error) {
	capabilities := s.handler.CreateServerCapabilities()

	capabilities.TextDocumentSync = &protocol.TextDocumentSyncOptions{
		OpenClose: boolPtr(true),
		Change:    textDocumentSyncKindPtr(protocol.TextDocumentSyncKindFull),
	}

	capabilities.CompletionProvider = &protocol.CompletionOptions{}

	return protocol.InitializeResult{
		Capabilities: capabilities,
		ServerInfo: &protocol.InitializeResultServerInfo{
			Name:    s.lsName,
			Version: &s.version,
		},
	}, nil
}

func (s *state) initialized(ctx *glsp.Context, params *protocol.InitializedParams) error {
	return nil
}

func (s *state) shutdown(ctx *glsp.Context) error {
	protocol.SetTraceValue(protocol.TraceValueOff)
	return nil
}

func (s *state) setTrace(ctx *glsp.Context, params *protocol.SetTraceParams) error {
	protocol.SetTraceValue(params.Value)
	return nil
}

func (s *state) didOpen(ctx *glsp.Context, params *protocol.DidOpenTextDocumentParams) error {
	uri := params.TextDocument.URI
	s.documents[uri] = params.TextDocument.Text
	s.publishDiagnostics(ctx, params.TextDocument.URI, int(params.TextDocument.Version))
	return nil
}

func (s *state) didChange(ctx *glsp.Context, params *protocol.DidChangeTextDocumentParams) error {
	uri := params.TextDocument.URI

	if len(params.ContentChanges) > 0 {
		switch change := params.ContentChanges[0].(type) {
		case protocol.TextDocumentContentChangeEvent:
			s.documents[uri] = change.Text
		case map[string]any:
			if text, ok := change["text"].(string); ok {
				s.documents[uri] = text
			}
		}
	}

	s.publishDiagnostics(ctx, params.TextDocument.URI, int(params.TextDocument.Version))
	return nil
}

func (s *state) didClose(ctx *glsp.Context, params *protocol.DidCloseTextDocumentParams) error {
	uri := params.TextDocument.URI
	delete(s.documents, uri)

	ctx.Notify("textDocument/publishDiagnostics", protocol.PublishDiagnosticsParams{
		URI:         params.TextDocument.URI,
		Diagnostics: []protocol.Diagnostic{},
	})

	return nil
}

func (s *state) completion(ctx *glsp.Context, params *protocol.CompletionParams) (any, error) {
	uri := params.TextDocument.URI
	text := s.documents[uri]

	items := make([]protocol.CompletionItem, 0, 64)

	for _, kw := range []string{
		"becomes", "suppose", "otherwise", "enough", "say", "snitch",
	} {
		items = append(items, protocol.CompletionItem{
			Label: kw,
			Kind:  completionItemKindPtr(protocol.CompletionItemKindKeyword),
		})
	}

	for _, op := range []string{
		"louder_than", "quieter_than", "vibes_like",
		"harshing_the_vibe_of", "has", "and", "or",
		"copacetic", "harsh",
	} {
		items = append(items, protocol.CompletionItem{
			Label: op,
			Kind:  completionItemKindPtr(protocol.CompletionItemKindOperator),
		})
	}

	for _, ident := range extractIdentifiers(text) {
		items = append(items, protocol.CompletionItem{
			Label: ident,
			Kind:  completionItemKindPtr(protocol.CompletionItemKindVariable),
		})
	}

	return items, nil
}

func (s *state) publishDiagnostics(ctx *glsp.Context, uri protocol.DocumentUri, version int) {
	text := s.documents[uri]
	_, err := parser.Parse(text)

	diagnostics := []protocol.Diagnostic{}
	if err != nil {
		diagnostics = append(diagnostics, protocol.Diagnostic{
			Range: protocol.Range{
				Start: protocol.Position{Line: 0, Character: 0},
				End:   protocol.Position{Line: 0, Character: 1},
			},
			Severity: diagnosticSeverityPtr(protocol.DiagnosticSeverityError),
			Message:  err.Error(),
		})
	}

	v := protocol.UInteger(version)

	ctx.Notify("textDocument/publishDiagnostics", protocol.PublishDiagnosticsParams{
		URI:         uri,
		Version:     &v,
		Diagnostics: diagnostics,
	})
}

func extractIdentifiers(text string) []string {
	seen := map[string]struct{}{}
	for _, match := range identifierRE.FindAllString(text, -1) {
		seen[match] = struct{}{}
	}

	out := make([]string, 0, len(seen))
	for ident := range seen {
		out = append(out, ident)
	}
	sort.Strings(out)
	return out
}

func boolPtr(v bool) *bool {
	return &v
}

func textDocumentSyncKindPtr(v protocol.TextDocumentSyncKind) *protocol.TextDocumentSyncKind {
	return &v
}

func diagnosticSeverityPtr(v protocol.DiagnosticSeverity) *protocol.DiagnosticSeverity {
	return &v
}

func completionItemKindPtr(v protocol.CompletionItemKind) *protocol.CompletionItemKind {
	return &v
}
