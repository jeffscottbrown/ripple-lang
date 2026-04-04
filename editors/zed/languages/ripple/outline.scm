; Ripple document outline for Zed
;
; Shows each section header and top-level assignment in the
; symbol navigation panel (cmd-shift-o / ctrl-shift-o).

; ── Sections ──────────────────────────────────────────────────────────────────

(section
  (section_header
    (string_literal) @name)) @item

; ── Top-level assignments ─────────────────────────────────────────────────────

(assignment_statement
  target: (identifier) @name) @item
