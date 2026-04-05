; ── Section headers ──────────────────────────────────────────────────────────
; [circle of friends]  sections are the top-level structural unit.
; Highlight the bracketed name like a module/namespace.

(section_header "[" @punctuation.bracket)
(section_header "]" @punctuation.bracket)
(section_header (string_literal) @module)

; ── Control-flow keywords ────────────────────────────────────────────────────

"suppose"   @keyword.control
"otherwise" @keyword.control
"enough"    @keyword.control

; ── Other keywords ───────────────────────────────────────────────────────────

"becomes" @keyword
"say"     @keyword
"snitch"  @keyword

; ── Operators (all keyword-based in Ripple) ──────────────────────────────────

(operator) @keyword.operator

; ── Boolean literals ─────────────────────────────────────────────────────────

(boolean_literal "copacetic" @constant.builtin)
(boolean_literal "harsh"     @constant.builtin)

; ── String literals ──────────────────────────────────────────────────────────

(string_literal) @string

; ── Attribute access  (person.name, person.albumcount) ───────────────────────

(attribute
  object:   (identifier) @variable
  "."       @punctuation.delimiter
  property: (identifier) @property)

; ── Assignment targets ───────────────────────────────────────────────────────

(assignment_statement
  target: (identifier) @variable)

; ── Data-section entry keys ──────────────────────────────────────────────────
; Highlight  jerry: "…"  and  jerry: { … }  key identifiers distinctly so
; developers can quickly scan the data sections.

(entry
  key: (identifier) @variable.special)

; ── Collection delimiters ────────────────────────────────────────────────────

(collection "{" @punctuation.bracket)
(collection "}" @punctuation.bracket)

; ── Fall-through ─────────────────────────────────────────────────────────────
; Any identifier not captured by a more specific rule above (e.g. a bare
; variable reference on the right-hand side of `becomes`) gets the generic
; variable colour.

(identifier) @variable
