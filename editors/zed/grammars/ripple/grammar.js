/**
 * @file grammar.js — Tree-sitter grammar for the Ripple programming language.
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * LANGUAGE OVERVIEW
 * ─────────────────────────────────────────────────────────────────────────────
 * Ripple is an English-flavoured, data-and-scripting language structured
 * around named "sections".  A source file is a flat sequence of sections;
 * each section opens with a bracketed string header and is followed by zero
 * or more entries or executable statements.
 *
 * Three conventional sections are defined by the standard runtime:
 *
 *   ["circle of friends"]
 *       Key/value entries that map identifier keys to display-name strings.
 *       e.g.   jerry: "Jerry Garcia"
 *
 *   ["albums"]
 *       Key/collection entries that map identifier keys to sets of strings.
 *       e.g.   jerry: { "Cats Under The Stars"  "Blues For Allah" }
 *
 *   ["jam"]
 *       Executable statements — assignments, conditionals, and print calls.
 *       e.g.   suppose jerry.albumcount louder_than janis.albumcount
 *                  say jerry.name " has more albums than " janis.name
 *              enough
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * LEXICAL RULES
 * ─────────────────────────────────────────────────────────────────────────────
 * Keywords   : becomes  suppose  say  otherwise  enough
 *              copacetic  harsh  vibes_like  harshing_the_vibe_of  louder_than  quieter_than  has
 * Strings    : double-quoted, e.g. "Jerry Garcia" — no escape sequences
 * Identifiers: [a-zA-Z_][a-zA-Z0-9_]*  (keywords excluded via `word`)
 * Whitespace : insignificant everywhere (`extras`)
 * Comments   : none
 *
 * ─────────────────────────────────────────────────────────────────────────────
 * DISAMBIGUATION NOTES
 * ─────────────────────────────────────────────────────────────────────────────
 * 1. entry vs. assignment_statement
 *    Both begin with a bare identifier at the top of a section body.
 *    The second token resolves the ambiguity (":" → entry,
 *    "becomes" → assignment_statement), so a GLR conflict is declared and
 *    both parse paths are kept alive in parallel until that token arrives.
 *
 * 2. attribute vs. identifier inside term
 *    `attribute` (identifier "." identifier) shares the same leading
 *    identifier prefix with a lone `identifier` term.  Applying prec(1, …)
 *    to the `attribute` alternative inside `term` causes the dotted form to
 *    be preferred whenever a "." follows, consuming it eagerly before the
 *    bare-identifier fallback is considered.
 *
 * 3. say_statement argument greediness
 *    Because an `expression` can reduce to a bare identifier, the parser
 *    faces a shift-reduce conflict after each argument: should the next
 *    identifier extend the current `say` or open a new section item?
 *    Wrapping `say_statement` with prec.right(…) resolves this in favour of
 *    shifting (greedy argument collection), which matches the language
 *    semantics.
 */

module.exports = grammar({
  name: "ripple",

  // ── Lexer configuration ────────────────────────────────────────────────────

  /**
   * Declare `identifier` as the canonical "word" token.  Tree-sitter will
   * then ensure that every keyword listed above is reserved — i.e. it will
   * never be returned as an identifier even when adjacent to non-word chars.
   */
  word: ($) => $.identifier,

  /** Silently consume horizontal and vertical whitespace at every position. */
  extras: ($) => [/\s+/],

  // ── GLR conflicts ──────────────────────────────────────────────────────────

  /**
   * At the start of a section body, both `entry` and `assignment_statement`
   * begin with a bare identifier.  Declaring this conflict lets Tree-sitter's
   * GLR engine pursue both parses simultaneously until the disambiguating
   * second token (":" vs "becomes") arrives.
   */
  conflicts: ($) => [[$.entry, $.assignment_statement]],

  // ── Grammar rules ──────────────────────────────────────────────────────────

  rules: {
    // ── Top-level ─────────────────────────────────────────────────────────────

    /** A Ripple source file is an ordered sequence of zero or more sections. */
    source_file: ($) => repeat($.section),

    // ── Section ───────────────────────────────────────────────────────────────

    /**
     * A section consists of a header followed by any mix of entries and
     * statements.  The conventional sections use only one kind each, but the
     * grammar imposes no such restriction.
     */
    section: ($) =>
      seq(
        field("header", $.section_header),
        repeat(choice($.entry, $.statement)),
      ),

    /** "[" string_literal "]"  —  e.g.  ["circle of friends"] */
    section_header: ($) => seq("[", field("name", $.string_literal), "]"),

    // ── Entries ───────────────────────────────────────────────────────────────

    /**
     * A data entry: an identifier key followed by ":" and either a single
     * string value or a brace-enclosed collection of strings.
     *
     *   jerry: "Jerry Garcia"
     *   jerry: { "Cats Under The Stars"  "Blues For Allah" }
     */
    entry: ($) =>
      seq(
        field("key", $.identifier),
        ":",
        field("value", choice($.string_literal, $.collection)),
      ),

    /** A brace-delimited, whitespace-separated sequence of string literals. */
    collection: ($) => seq("{", repeat(field("item", $.string_literal)), "}"),

    // ── Statements ────────────────────────────────────────────────────────────

    /** Any single executable statement. */
    statement: ($) =>
      choice($.assignment_statement, $.conditional_statement, $.say_statement),

    /**
     * Bind the result of an expression to an identifier.
     *   jerry_has_more becomes jerry.albumcount groovier grace.albumcount
     */
    assignment_statement: ($) =>
      seq(
        field("target", $.identifier),
        "becomes",
        field("value", $.expression),
      ),

    /**
     * An if / optional-else conditional block.
     *
     *   suppose <condition>
     *       <body statements>*
     *   [otherwise
     *       <alternative statements>*]
     *   enough
     */
    conditional_statement: ($) =>
      seq(
        "suppose",
        field("condition", $.expression),
        repeat(field("body", $.statement)),
        optional(seq("otherwise", repeat(field("alternative", $.statement)))),
        "enough",
      ),

    /**
     * Print one or more expressions to output.
     *   say jerry.name " has more albums than " janis.name
     *
     * prec.right resolves the shift-reduce conflict that arises because a
     * bare identifier can be both an expression argument and the start of a
     * new section item — right-associativity prefers shifting (greedy).
     */
    say_statement: ($) =>
      prec.right(seq("say", repeat1(field("argument", $.expression)))),

    // ── Expressions ───────────────────────────────────────────────────────────

    /**
     * An expression is a term optionally combined with a binary operator and
     * a second term.  Ripple expressions are flat (no nesting or precedence
     * hierarchy), so a single optional operator pair is sufficient.
     *
     *   jerry.albumcount groovier janis.albumcount
     *   jerry_has_more is golden
     *   "Cheap Thrills"
     */
    expression: ($) =>
      seq(
        field("left", $.term),
        optional(seq(field("operator", $.operator), field("right", $.term))),
      ),

    /** One of the five infix comparison / membership operators. */
    operator: ($) =>
      choice(
        "vibes_like",
        "harshing_the_vibe_of",
        "louder_than",
        "quieter_than",
        "has",
        "and",
        "or",
      ),

    // ── Terms ─────────────────────────────────────────────────────────────────

    /**
     * A term is the atomic operand inside an expression.  `attribute` carries
     * prec(1) so that a leading identifier followed by "." is always consumed
     * as a dotted attribute reference rather than falling back to the bare
     * identifier alternative.
     */
    term: ($) =>
      choice(
        prec(1, $.attribute),
        $.string_literal,
        $.boolean_literal,
        $.identifier,
      ),

    /**
     * A dotted attribute reference: object.property
     *   jerry.name          — display name of the "jerry" friend entry
     *   jerry.albumcount    — number of albums in jerry's collection
     *   jerry.albums        — the album collection itself
     */
    attribute: ($) =>
      seq(field("object", $.identifier), ".", field("property", $.identifier)),

    /** Boolean literals — `copacetic` is true, `harsh` is false. */
    boolean_literal: ($) => choice("copacetic", "harsh"),

    // ── Primitive tokens ──────────────────────────────────────────────────────

    /**
     * A double-quoted string literal.  No escape sequences are recognised;
     * any character except a double-quote may appear inside the quotes.
     *   "Jerry Garcia"
     *   "Cats Under The Stars"
     */
    string_literal: (_) => /"[^"]*"/,

    /**
     * An identifier: a letter or underscore followed by any number of
     * letters, digits, or underscores.  Because `word` points here,
     * Tree-sitter automatically prevents every keyword from being returned
     * as an identifier.
     *   jerry   grace_has_more   albumcount
     */
    identifier: (_) => /[a-zA-Z_][a-zA-Z0-9_]*/,
  },
});
