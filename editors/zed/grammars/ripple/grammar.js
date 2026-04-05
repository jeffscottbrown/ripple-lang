/**
 * @file grammar.js — Tree-sitter grammar for the Ripple programming language.
 */

module.exports = grammar({
  name: "ripple",

  word: ($) => $.identifier,

  extras: ($) => [/\s+/],

  conflicts: ($) => [[$.entry, $.assignment_statement]],

  rules: {
    // ── Top-level ─────────────────────────────────────────────────────────────

    source_file: ($) => repeat($.section),

    // ── Section ───────────────────────────────────────────────────────────────

    section: ($) =>
      seq(
        field("header", $.section_header),
        repeat(choice($.entry, $.statement)),
      ),

    /** "[" identifier+ "]"  —  e.g.  [circle of friends], [albums], [jam] */
    section_header: ($) => seq("[", repeat1($.identifier), "]"),

    // ── Entries ───────────────────────────────────────────────────────────────

    entry: ($) =>
      seq(
        field("key", $.identifier),
        ":",
        field("value", choice($.string_literal, $.collection)),
      ),

    collection: ($) => seq("{", repeat(field("item", $.string_literal)), "}"),

    // ── Statements ────────────────────────────────────────────────────────────

    statement: ($) =>
      choice(
        $.assignment_statement,
        $.conditional_statement,
        $.say_statement,
        $.snitch_statement,
      ),

    assignment_statement: ($) =>
      seq(
        field("target", $.identifier),
        "becomes",
        field("value", $.expression),
      ),

    conditional_statement: ($) =>
      seq(
        "suppose",
        field("condition", $.expression),
        repeat(field("body", $.statement)),
        optional(seq("otherwise", repeat(field("alternative", $.statement)))),
        "enough",
      ),

    say_statement: ($) =>
      prec.right(seq("say", repeat1(field("argument", $.expression)))),

    snitch_statement: ($) =>
      prec.right(seq("snitch", repeat1(field("argument", $.expression)))),

    // ── Expressions ───────────────────────────────────────────────────────────

    expression: ($) =>
      seq(
        field("left", $.term),
        optional(seq(field("operator", $.operator), field("right", $.term))),
      ),

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

    term: ($) =>
      choice(
        prec(1, $.attribute),
        $.string_literal,
        $.boolean_literal,
        $.identifier,
      ),

    attribute: ($) =>
      seq(field("object", $.identifier), ".", field("property", $.identifier)),

    boolean_literal: ($) => choice("copacetic", "harsh"),

    // ── Tokens ────────────────────────────────────────────────────────────────

    string_literal: (_) => /"[^"]*"/,

    identifier: (_) => /[a-zA-Z_][a-zA-Z0-9_]*/,
  },
});
