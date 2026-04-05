package ast

import (
	"github.com/alecthomas/participle/v2"
	"github.com/alecthomas/participle/v2/lexer"
)

var ripleLexer = lexer.MustStateful(lexer.Rules{
	"Root": {
		{Name: "String", Pattern: `"[^"]*"`},
		{Name: "Punct", Pattern: `[[\]{}.:]`},
		{Name: "Keyword", Pattern: `(?:becomes|suppose|say|otherwise|enough|harshing_the_vibe_of|copacetic|harsh|vibes_like|louder_than|quieter_than|has|and|or)\b`},
		{Name: "Ident", Pattern: `[a-zA-Z_][a-zA-Z0-9_]*`},
		{Name: "Newline", Pattern: `\r?\n`},     // Capture Newlines
		{Name: "Whitespace", Pattern: `[ \t]+`}, // Only tabs and spaces
	},
})

type Program struct {
	Sections []*Section `Newline* @@* Newline*` // Allow wrapping newlines
}

type Section struct {
	Name       string       `"[" @String "]" Newline*`
	Entries    []*Entry     `( @@ Newline* )*` // Allow newlines between entries
	Statements []*Statement `( @@ Newline* )*`
}

type Entry struct {
	Pos   lexer.Position
	Key   string `@Ident ":"`
	Value string ` ( @String `
	// Use Newline* to allow albums to be listed on multiple lines
	Collection []string ` | "{" Newline* @String* (Newline* @String)* Newline* "}" ) `
}

type Statement struct {
	// Revert to simple @@ tags.
	// We will use UseLookahead(5) in MustBuild to handle the ambiguity.
	Assignment  *Assignment  `  @@`
	Conditional *Conditional `| @@`
	Print       *Print       `| @@`
}

type Assignment struct {
	Target string      `@Ident "becomes"`
	Value  *Expression `@@`
}

type Print struct {
	Args []*Expression `"say" @@+`
}
type Conditional struct {
	Condition *Expression  `"suppose" @@ Newline*` // Newline after condition
	Body      []*Statement `( @@ Newline* )*`
	Otherwise []*Statement `( "otherwise" Newline* ( @@ Newline* )* )?`
	End       string       `"enough"`
}

type Expression struct {
	Left  *Term  `@@`
	Op    string `[ @( "louder_than" | "quieter_than" | "vibes_like" | "harshing_the_vibe_of" | "has" | "and" | "or" )`
	Right *Term  `  @@ ]`
}

type Term struct {
	Pos   lexer.Position
	Attr  *Attr   `  @@`
	Str   *string `| @String`
	Bool  *string `| @( "copacetic" | "harsh" )`
	Ident *string `| @Ident`
}

type Attr struct {
	Pos  lexer.Position
	Name string `@Ident "."`
	Prop string `@Ident`
}

var Parser = participle.MustBuild[Program](
	participle.Lexer(ripleLexer),
	participle.Unquote("String"),
	participle.UseLookahead(5),
	participle.Elide("Whitespace"),
)
