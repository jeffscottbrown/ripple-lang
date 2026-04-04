# Ripple — Zed Extension

Zed editor support for the [Ripple](https://github.com/jeffscottbrown/ripple-lang) programming language. The extension provides syntax highlighting, bracket auto-close, smart indentation, and document outline navigation for `.ripple` files — all powered by a Tree-sitter grammar.

---

## Features

- **Syntax highlighting** — sections, keywords (`suppose`, `otherwise`, `enough`, `becomes`, `say`), operators, string literals, booleans (`golden` / `muddy`), attribute access, and collection delimiters
- **Bracket matching & auto-close** — `[…]`, `{…}`, and `"…"`
- **Auto-indent** — inside `suppose … enough` and `suppose … otherwise … enough` blocks
- **Document outline** — every `["section name"]` and top-level assignment appears in the Outline panel (`Cmd+Shift+O` / `Ctrl+Shift+O`)
- **Word completion** — keyword-based completions from the current document via Zed's built-in engine

---

## Setup

### Mode A — Dev extension (recommended for local development)

This mode works immediately from your local checkout — no publishing required.

**Prerequisites:** Zed, Node.js ≥ 18, npm

1. Generate the Tree-sitter parser:

   ```sh
   cd editors/zed/grammars/ripple
   npm install
   npx tree-sitter generate
   ```

   This produces `editors/zed/grammars/ripple/src/parser.c`, which Zed compiles on first load.

2. Find the **absolute path** to the `editors/zed/` directory in your checkout (e.g. `/Users/you/projects/ripple-lang/editors/zed`).

3. Open Zed settings (`Cmd+,` / `Ctrl+,`) and add the `dev_extensions` key:

   ```json
   {
     "dev_extensions": ["/absolute/path/to/ripple-lang/editors/zed"]
   }
   ```

4. Restart Zed. Open any `.ripple` file — syntax highlighting is active.

---

### Mode B — Installed extension (after grammar is published to GitHub)

Once the grammar is committed and pushed to GitHub, pin the extension to a specific commit for reproducible builds.

1. Replace `"HEAD"` with the actual commit SHA in `extension.toml`:

   ```toml
   [grammars.ripple]
   repository = "https://github.com/jeffscottbrown/ripple-lang"
   commit = "<actual-sha>"
   path = "editors/zed/grammars/ripple"
   ```

2. In Zed, open **Extensions** → **Install Dev Extension** and select the `editors/zed/` directory.

---

## Snippets

Ripple has no language server yet, so completions are word-based (sourced from the current document). For snippet-style completions, add the following to `~/.config/zed/snippets.json`:

```json
{
  "suppose": {
    "prefix": "suppose",
    "body": ["suppose ${1:condition}", "\t${2:say \"…\"}", "enough"],
    "description": "Ripple conditional block"
  },
  "suppose-otherwise": {
    "prefix": "suppose-oth",
    "body": [
      "suppose ${1:condition}",
      "\t${2:say \"…\"}",
      "otherwise",
      "\t${3:say \"…\"}",
      "enough"
    ],
    "description": "Ripple if/else block"
  },
  "becomes": {
    "prefix": "becomes",
    "body": ["${1:name} becomes ${2:golden}"],
    "description": "Ripple boolean assignment"
  }
}
```

All Ripple keywords are also surfaced as completions automatically once the grammar is active.

---

## Troubleshooting

| Symptom | Fix |
|---|---|
| No highlighting after adding dev extension | Run `npx tree-sitter generate` — `editors/zed/grammars/ripple/src/parser.c` must exist before Zed can compile the grammar |
| `tree-sitter generate` fails | Verify Node.js ≥ 18 is installed and that `npm install` completed without errors |
| Extension not recognised by Zed | Check that the path in `dev_extensions` is **absolute** and points to `editors/zed/` — not to the repo root or to `ripple-lang/` |
| Grammar compile errors in Zed | Re-run `npx tree-sitter generate` after any edits to `grammar.js`, then restart Zed |
| Outline panel is empty | Confirm the file is saved with a `.ripple` extension so Zed applies the correct language configuration |

---

## Extension structure

```
editors/zed/
├── extension.toml                  # Zed extension manifest
├── grammars/
│   └── ripple/
│       ├── grammar.js              # Tree-sitter grammar source
│       └── package.json            # npm package (tree-sitter-cli)
└── languages/
    └── ripple/
        ├── config.toml             # File association, brackets, indent rules
        ├── highlights.scm          # Syntax highlighting queries
        ├── brackets.scm            # Bracket-matching queries
        ├── indents.scm             # Auto-indent queries
        └── outline.scm             # Document outline queries
```
