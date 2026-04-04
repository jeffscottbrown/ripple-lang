BIN      := ripple-lang
CMD      := ./cmd/ripple
PKG      := ./...
RIPPLE   := demo.ripple

.DEFAULT_GOAL := help

.PHONY: build
build:                      ## Compile the ripple binary
	go build -o $(BIN) $(CMD)

.PHONY: run
run: build                  ## Compile and execute demo.ripple
	./$(BIN) $(RIPPLE)

.PHONY: ir
ir: build                   ## Print the LLVM IR for demo.ripple
	./$(BIN) -v $(RIPPLE)

.PHONY: test
test:                       ## Run all tests
	go test $(PKG)

.PHONY: test-verbose
test-verbose:               ## Run all tests with verbose output
	go test -v $(PKG)

.PHONY: test-race
test-race:                  ## Run all tests with the race detector
	go test -race $(PKG)

.PHONY: vet
vet:                        ## Run go vet (structtag analyser disabled for participle grammar)
	go vet -structtag=false $(PKG)

.PHONY: fmt
fmt:                        ## Format all Go source files
	gofmt -w -s .

.PHONY: fmt-check
fmt-check:                  ## Check formatting without modifying files
	@test -z "$$(gofmt -l .)" || (echo "Unformatted files:"; gofmt -l .; exit 1)

.PHONY: lint
lint:                       ## Run golangci-lint (must be installed separately)
	golangci-lint run $(PKG)

.PHONY: tidy
tidy:                       ## Tidy and verify the module dependencies
	go mod tidy
	go mod verify

.PHONY: clean
clean:                      ## Remove the compiled binary
	rm -f $(BIN)

.PHONY: check
check: fmt-check vet lint test   ## Run all checks (formatting, vet, lint, tests)

.PHONY: ci
ci: tidy check              ## Full CI pipeline (tidy, fmt-check, vet, lint, test)

.PHONY: help
help:                       ## Show this help message
	@grep -E '^[a-zA-Z_-]+:.*##' $(MAKEFILE_LIST) \
	  | awk 'BEGIN {FS = ":.*##"}; {printf "  \033[36m%-16s\033[0m %s\n", $$1, $$2}'
