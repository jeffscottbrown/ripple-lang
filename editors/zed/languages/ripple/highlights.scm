; ── Section headers (make these VERY obvious for debugging) ───────────────────

(section_header "[" @punctuation.bracket)
(section_header "]" @punctuation.bracket)

; highlight section names strongly so they stand out
(section_header (identifier) @keyword)

; ── Control-flow keywords ────────────────────────────────────────────────────

"suppose"   @keyword.control
"otherwise" @keyword.control
"enough"    @keyword.control

; ── Other keywords ───────────────────────────────────────────────────────────

"becomes" @keyword
"say"     @keyword
"snitch"  @keyword

; ── Operators ────────────────────────────────────────────────────────────────

(operator) @keyword.operator

; ── Boolean literals ─────────────────────────────────────────────────────────

(boolean_literal "copacetic" @constant.builtin)
(boolean_literal "harsh"     @constant.builtin)

; ── String literals ──────────────────────────────────────────────────────────
; keep these, but they should NOT override section headers now

(string_literal) @string

; ── Attribute access ─────────────────────────────────────────────────────────

(attribute
  object:   (identifier) @variable
  "."       @punctuation.delimiter
  property: (identifier) @property)

; ── Assignment targets ───────────────────────────────────────────────────────

(assignment_statement
  target: (identifier) @variable)

; ── Data-section entry keys ──────────────────────────────────────────────────

(entry
  key: (identifier) @variable.special)

; ── Collection delimiters ────────────────────────────────────────────────────

(collection "{" @punctuation.bracket)
(collection "}" @punctuation.bracket)

; ── Generic identifiers LAST (so they don't override header styling) ─────────

(identifier) @variable
