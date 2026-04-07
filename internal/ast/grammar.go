package ast

import (
	"github.com/alecthomas/participle/v2"
	"github.com/alecthomas/participle/v2/lexer"
)

var ripleLexer = lexer.MustStateful(lexer.Rules{
	"Root": {
		{Name: "Comment", Pattern: `#[^\n\r]*`},
		{Name: "String", Pattern: `"[^"]*"`},
		{Name: "BracketPhrase", Pattern: `\[[a-zA-Z_][a-zA-Z0-9_]*(?:\s+[a-zA-Z_][a-zA-Z0-9_]*)*\]`},
		{Name: "Punct", Pattern: `[[\]{}.:]`},
		{Name: "Keyword", Pattern: `(?:becomes|suppose|say|snitch|otherwise|enough|harshing_the_vibe_of|copacetic|harsh|vibes_like|louder_than|quieter_than|has|and|or)\b`},
		{Name: "Ident", Pattern: `[a-zA-Z_][a-zA-Z0-9_]*`},
		{Name: "Newline", Pattern: `\r?\n`},
		{Name: "Whitespace", Pattern: `[ \t]+`},
	},
})

type Program struct {
	Sections []*Section `Newline* ( @@ Newline* )*`
}

type Section struct {
	Pos     lexer.Position
	Friends *CircleOfFriendsSection `@@`
	Albums  *AlbumsSection          `| @@`
	Jam     *JamSection             `| @@`
}

type JamSection struct {
	Pos        lexer.Position
	Name       JamPhrase    `@BracketPhrase Newline*`
	Statements []*Statement `( @@ Newline* )*`
}

type CircleOfFriendsSection struct {
	Pos     lexer.Position
	Name    FriendsPhrase  `@BracketPhrase Newline*`
	Entries []*FriendEntry `( @@ Newline* )*`
}

type AlbumsSection struct {
	Pos     lexer.Position
	Name    AlbumsPhrase  `@BracketPhrase Newline*`
	Entries []*AlbumEntry `( @@ Newline* )*`
}

type FriendEntry struct {
	Pos   lexer.Position
	Key   string `@Ident ":"`
	Value string `@String`
}

type AlbumEntry struct {
	Pos        lexer.Position
	Key        string   `@Ident ":"`
	Collection []string `"{" Newline* @String* (Newline* @String)* Newline* "}"`
}

type Statement struct {
	Pos         lexer.Position
	Assignment  *Assignment  `  @@`
	Conditional *Conditional `| @@`
	Print       *Print       `| @@`
	Snitch      *Snitch      `| @@`
}

type Assignment struct {
	Pos    lexer.Position
	Target string      `@Ident "becomes"`
	Value  *Expression `@@`
}

type Snitch struct {
	Pos  lexer.Position
	Args []*Expression `"snitch" @@+`
}

type Print struct {
	Pos  lexer.Position
	Args []*Expression `"say" @@+`
}

type Conditional struct {
	Pos       lexer.Position
	Condition *Expression  `"suppose" @@ Newline*`
	Body      []*Statement `( @@ Newline* )*`
	Otherwise []*Statement `( "otherwise" Newline* ( @@ Newline* )* )?`
	End       string       `"enough"`
}

type Expression struct {
	Pos   lexer.Position
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
	participle.Elide("Whitespace", "Comment"),
)
