# Ripple

> *"Reach out your hand if your cup be empty…"*

[![fmt](https://github.com/jeffscottbrown/ripple-lang/actions/workflows/fmt.yml/badge.svg)](https://github.com/jeffscottbrown/ripple-lang/actions/workflows/fmt.yml)
[![vet](https://github.com/jeffscottbrown/ripple-lang/actions/workflows/vet.yml/badge.svg)](https://github.com/jeffscottbrown/ripple-lang/actions/workflows/vet.yml)
[![lint](https://github.com/jeffscottbrown/ripple-lang/actions/workflows/lint.yml/badge.svg)](https://github.com/jeffscottbrown/ripple-lang/actions/workflows/lint.yml)
[![test](https://github.com/jeffscottbrown/ripple-lang/actions/workflows/test.yml/badge.svg)](https://github.com/jeffscottbrown/ripple-lang/actions/workflows/test.yml)
[![Go Report Card](https://goreportcard.com/badge/github.com/jeffscottbrown/ripple-lang)](https://goreportcard.com/report/github.com/jeffscottbrown/ripple-lang)

Ripple is a hippie lingo-themed programming language that compiles to LLVM IR. You write programs in plain, expressive language — sections of friends, albums, and a jam — and Ripple turns them into native code via a hand-written compiler backed by LLVM and `clang`.

---

## Quick Start

**Requirements:** Go, clang

```sh
# 1. Build the compiler
make build

# 2. Run the demo program
make run

# 3. Inspect the generated LLVM IR
make ir

# 4. Run the test suite
make test

# 5. Or run any .ripple file directly:
./ripple-lang demo.ripple            # compile and run
./ripple-lang -v demo.ripple         # print LLVM IR instead of running
./ripple-lang -o myapp demo.ripple   # compile to a standalone binary named 'myapp'
```

---

## Program Structure

Every Ripple program is made up of **sections**. A section begins with its name in square brackets:

```sh
["section name"]
```

There are three conventional sections, written in order:

| Section | Purpose |
|---|---|
| `["circle of friends"]` | Declare named people |
| `["albums"]` | Assign album collections to people |
| `["jam"]` | The executable logic |

---

## Data Sections

### `["circle of friends"]`

Declare the people your program knows about. Each entry maps an identifier to a display name string.

```sh
["circle of friends"]
jerry: "Jerry Garcia"
janis: "Janis Joplin"
grace: "Grace Slick"
```

### `["albums"]`

Assign a collection of album titles to a person. Albums are listed inside `{ }`, one per line, as quoted strings.

```sh
["albums"]
jerry: {
    "Cats Under The Stars"
    "Blues For Allah"
    "Terrapin Station"
}
janis: {
    "Big Brother And The Holding Company"
    "Cheap Thrills"
}
grace: {
    "Surrealistic Pillow"
}
```

---

## The Jam Section

`["jam"]` is where the program runs. It supports variable assignment, printing, and conditionals.

### Printing — `say`

Print one or more values on a single line to standard output (`stdout`). Multiple values are concatenated with no separator.

```sh
say "Hello, world"
say jerry.name " has " jerry.albumcount " albums"
```

### Error Logging — `snitch`

Print a message to standard error (`stderr`). This is used for flagging when the vibe is off or providing diagnostic info that shouldn't interfere with the main output.

```sh
snitch "The drummer is late"
```

### Assignment — `becomes`

Assign a boolean literal or the result of a comparison to a variable.

```sh
is_good becomes copacetic
has_more becomes jerry.albumcount louder_than janis.albumcount
```

### Conditionals — `suppose … enough`

Test a condition and run a block of statements when it holds. Close every conditional with `enough`.

```sh
suppose is_good vibes_like copacetic
    say "feeling good"
enough
```

### Conditionals — `suppose … otherwise … enough`

Add an `otherwise` branch for the case when the condition does not hold.

```sh
suppose jerry.albumcount louder_than janis.albumcount
    say jerry.name " wins"
otherwise
    say janis.name " wins"
enough
```

Conditions can be a direct comparison expression or a variable holding a boolean value. Combine conditions with `and` and `or`:

```sh
suppose jerry.albums has "Terrapin Station" and grace.albumcount louder_than janis.albumcount
    say "both things are true"
enough
```

---

## Values

| Value | Description |
|---|---|
| `copacetic` | Boolean true |
| `harsh` | Boolean false |
| `"string literal"` | A double-quoted string |
| `person.name` | The display name from `["circle of friends"]` |
| `person.albumcount` | The number of albums the person has |
| `person.albums` | The album collection (used with the `has` operator) |

---

## Operators

| Operator | Meaning | Example |
|---|---|---|
| `vibes_like` | Equal | `mood vibes_like copacetic` |
| `harshing_the_vibe_of` | Not equal | `mood harshing_the_vibe_of harsh` |
| `louder_than` | Greater than | `jerry.albumcount louder_than janis.albumcount` |
| `quieter_than` | Less than | `janis.albumcount quieter_than jerry.albumcount` |
| `has` | Collection membership | `jerry.albums has "Terrapin Station"` |
| `and` | Logical AND | `a vibes_like copacetic and b vibes_like copacetic` |
| `or` | Logical OR | `a vibes_like copacetic or b vibes_like copacetic` |

## Line Level Comments
The hash symbol (#) is used to designate code that is
intended to be ignored by the compiler and is included
for other readers of the source code.


```sh
# this will indicate who has more albums
suppose jerry.albumcount louder_than janis.albumcount
    say jerry.name " wins" # this is a comment
otherwise
    say janis.name " wins"
enough
```

### Keyword Reference

`becomes` `say` `snitch` `suppose` `otherwise` `enough` `copacetic` `harsh` `vibes_like` `harshing_the_vibe_of` `louder_than` `quieter_than` `has` `and` `or`

---

## Complete Example

**`demo.ripple`**

```sh
["circle of friends"]
jerry: "Jerry Garcia"
janis: "Janis Joplin"
grace: "Grace Slick"

["albums"]
jerry: {
    "Cats Under The Stars"
    "Blues For Allah"
    "Terrapin Station"
}
janis: {
    "Big Brother And The Holding Company"
    "Cheap Thrills"
}
grace: {
    "Surrealistic Pillow"
}

["jam"]
suppose jerry.albumcount quieter_than 1
    snitch "Warning: Jerry has no albums recorded."
enough

suppose jerry.albumcount louder_than janis.albumcount
    say jerry.name " has more albums than " janis.name
otherwise
    say jerry.name " does not have more albums than " janis.name
enough

suppose janis.albums has "Surrealistic Pillow"
    say janis.name " made the pillow"
otherwise
    say janis.name " did not make the pillow"
enough

jerry_has_more becomes jerry.albumcount louder_than grace.albumcount

suppose jerry_has_more vibes_like copacetic
    say jerry.name " has more albums than " grace.name
enough

suppose jerry_has_more vibes_like harsh
    say jerry.name " had fewer albums than " grace.name
enough

grace_has_more becomes grace.albumcount louder_than janis.albumcount

suppose grace_has_more vibes_like copacetic
    say grace.name " has more albums than " janis.name
otherwise
    say grace.name " had fewer albums than " janis.name
enough
```

**Expected output:**

```
Jerry Garcia has more albums than Janis Joplin
Janis Joplin did not make the pillow
Jerry Garcia has more albums than Grace Slick
Grace Slick had fewer albums than Janis Joplin
```

---

## Project Layout

```
ripple-lang/
├── cmd/
│   └── ripple/
│       └── main.go          # Entry point
├── editors/
│   └── zed/                 # Zed editor extension (see below)
├── internal/
│   ├── ast/
│   │   └── grammar.go       # AST node types and participle grammar
│   ├── codegen/
│   │   ├── compiler.go      # LLVM IR code generation
│   │   └── compiler_test.go # Compiler tests
│   ├── parser/
│   │   └── parser.go        # Parses source into an AST
│   └── runner/
│       └── runner.go        # Invokes clang to link and execute IR
├── demo.ripple              # Demo program
└── Makefile
```

---

## Running the Tests

```sh
make test          # run the test suite
make check         # fmt-check + vet + test (recommended before committing)
```

Individual test targets:

```sh
make test-verbose  # verbose test output
make test-race     # run tests with the race detector
make vet           # run go vet
make fmt           # format all Go source files
```

---

## Zed Editor Support

The `editors/zed/` directory contains a first-class Zed extension for Ripple.

- **Syntax highlighting** — sections, keywords, operators, string literals, booleans, attribute access, and collection delimiters.
- **Bracket matching & auto-close** — `[…]`, `{…}`, and `"…"`
- **Auto-indent** — inside `suppose … enough` blocks

---

> *"Let there be songs to fill the air."*
