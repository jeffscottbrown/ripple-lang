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
		{Name: "Whitespace", Pattern: `[\t\n\r ]+`},
	},
})

type Program struct {
	Sections []*Section `@@*`
}

type Section struct {
	Name       string       `"[" @String "]"`
	Entries    []*Entry     `@@*`
	Statements []*Statement `@@*`
}

type Entry struct {
	Key        string   `@Ident ":"`
	Value      string   ` ( @String `
	Collection []string ` | "{" @String* "}" ) `
}

type Statement struct {
	// The parentheses ( ) force Participle to backtrack if a branch fails.
	// We check Assignment first because it starts with a generic @Ident.
	Assignment  *Assignment  `  ( @@`
	Conditional *Conditional `  | @@`
	Print       *Print       `  | @@ )`
}

type Assignment struct {
	Target string      `@Ident "becomes"`
	Value  *Expression `@@`
}

type Print struct {
	Args []*Expression `"say" @@+`
}

type Conditional struct {
	Condition *Expression  `"suppose" @@`
	Body      []*Statement `@@*`
	Otherwise []*Statement `( "otherwise" @@* )?`
	End       string       ` "enough"`
}

type Expression struct {
	Left  *Term  `@@`
	Op    string `[ @( "louder_than" | "quieter_than" | "vibes_like" | "harshing_the_vibe_of" | "has" | "and" | "or" )`
	Right *Term  `  @@ ]`
}

type Term struct {
	Attr  *Attr   `  @@`
	Str   *string `| @String`
	Bool  *string `| @( "copacetic" | "harsh" )`
	Ident *string `| @Ident`
}

type Attr struct {
	Name string `@Ident "."`
	Prop string `@Ident`
}

var Parser = participle.MustBuild[Program](
	participle.Lexer(ripleLexer),
	participle.Unquote("String"),
	participle.UseLookahead(5),
	participle.Elide("Whitespace"),
)
