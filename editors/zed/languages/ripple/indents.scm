; Ripple indentation rules for Zed
;
; After "suppose <condition>", the body statements should be indented one level.
; "otherwise" dedents back to the suppose level, then re-indents its own body.
; "enough" dedents back to the suppose level.
;
; Collections also indent their contents.

; Opening a conditional block
(conditional_statement
  "suppose" @indent)

; "otherwise" closes the then-body and opens the else-body
(conditional_statement
  "otherwise" @dedent @indent)

; "enough" closes whichever body was open
(conditional_statement
  "enough" @dedent)

; Indent inside album collections
(collection
  "{" @indent
  "}" @outdent)
