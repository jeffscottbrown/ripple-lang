#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 66
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 46
#define ALIAS_COUNT 0
#define TOKEN_COUNT 24
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 14
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 21

enum ts_symbol_identifiers {
  sym_identifier = 1,
  anon_sym_LBRACK = 2,
  anon_sym_RBRACK = 3,
  anon_sym_COLON = 4,
  anon_sym_LBRACE = 5,
  anon_sym_RBRACE = 6,
  anon_sym_becomes = 7,
  anon_sym_suppose = 8,
  anon_sym_otherwise = 9,
  anon_sym_enough = 10,
  anon_sym_say = 11,
  anon_sym_snitch = 12,
  anon_sym_vibes_like = 13,
  anon_sym_harshing_the_vibe_of = 14,
  anon_sym_louder_than = 15,
  anon_sym_quieter_than = 16,
  anon_sym_has = 17,
  anon_sym_and = 18,
  anon_sym_or = 19,
  anon_sym_DOT = 20,
  anon_sym_copacetic = 21,
  anon_sym_harsh = 22,
  sym_string_literal = 23,
  sym_source_file = 24,
  sym_section = 25,
  sym_section_header = 26,
  sym_entry = 27,
  sym_collection = 28,
  sym_statement = 29,
  sym_assignment_statement = 30,
  sym_conditional_statement = 31,
  sym_say_statement = 32,
  sym_snitch_statement = 33,
  sym_expression = 34,
  sym_operator = 35,
  sym_term = 36,
  sym_attribute = 37,
  sym_boolean_literal = 38,
  aux_sym_source_file_repeat1 = 39,
  aux_sym_section_repeat1 = 40,
  aux_sym_section_header_repeat1 = 41,
  aux_sym_collection_repeat1 = 42,
  aux_sym_conditional_statement_repeat1 = 43,
  aux_sym_conditional_statement_repeat2 = 44,
  aux_sym_say_statement_repeat1 = 45,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_COLON] = ":",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_becomes] = "becomes",
  [anon_sym_suppose] = "suppose",
  [anon_sym_otherwise] = "otherwise",
  [anon_sym_enough] = "enough",
  [anon_sym_say] = "say",
  [anon_sym_snitch] = "snitch",
  [anon_sym_vibes_like] = "vibes_like",
  [anon_sym_harshing_the_vibe_of] = "harshing_the_vibe_of",
  [anon_sym_louder_than] = "louder_than",
  [anon_sym_quieter_than] = "quieter_than",
  [anon_sym_has] = "has",
  [anon_sym_and] = "and",
  [anon_sym_or] = "or",
  [anon_sym_DOT] = ".",
  [anon_sym_copacetic] = "copacetic",
  [anon_sym_harsh] = "harsh",
  [sym_string_literal] = "string_literal",
  [sym_source_file] = "source_file",
  [sym_section] = "section",
  [sym_section_header] = "section_header",
  [sym_entry] = "entry",
  [sym_collection] = "collection",
  [sym_statement] = "statement",
  [sym_assignment_statement] = "assignment_statement",
  [sym_conditional_statement] = "conditional_statement",
  [sym_say_statement] = "say_statement",
  [sym_snitch_statement] = "snitch_statement",
  [sym_expression] = "expression",
  [sym_operator] = "operator",
  [sym_term] = "term",
  [sym_attribute] = "attribute",
  [sym_boolean_literal] = "boolean_literal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_section_repeat1] = "section_repeat1",
  [aux_sym_section_header_repeat1] = "section_header_repeat1",
  [aux_sym_collection_repeat1] = "collection_repeat1",
  [aux_sym_conditional_statement_repeat1] = "conditional_statement_repeat1",
  [aux_sym_conditional_statement_repeat2] = "conditional_statement_repeat2",
  [aux_sym_say_statement_repeat1] = "say_statement_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_becomes] = anon_sym_becomes,
  [anon_sym_suppose] = anon_sym_suppose,
  [anon_sym_otherwise] = anon_sym_otherwise,
  [anon_sym_enough] = anon_sym_enough,
  [anon_sym_say] = anon_sym_say,
  [anon_sym_snitch] = anon_sym_snitch,
  [anon_sym_vibes_like] = anon_sym_vibes_like,
  [anon_sym_harshing_the_vibe_of] = anon_sym_harshing_the_vibe_of,
  [anon_sym_louder_than] = anon_sym_louder_than,
  [anon_sym_quieter_than] = anon_sym_quieter_than,
  [anon_sym_has] = anon_sym_has,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_or] = anon_sym_or,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_copacetic] = anon_sym_copacetic,
  [anon_sym_harsh] = anon_sym_harsh,
  [sym_string_literal] = sym_string_literal,
  [sym_source_file] = sym_source_file,
  [sym_section] = sym_section,
  [sym_section_header] = sym_section_header,
  [sym_entry] = sym_entry,
  [sym_collection] = sym_collection,
  [sym_statement] = sym_statement,
  [sym_assignment_statement] = sym_assignment_statement,
  [sym_conditional_statement] = sym_conditional_statement,
  [sym_say_statement] = sym_say_statement,
  [sym_snitch_statement] = sym_snitch_statement,
  [sym_expression] = sym_expression,
  [sym_operator] = sym_operator,
  [sym_term] = sym_term,
  [sym_attribute] = sym_attribute,
  [sym_boolean_literal] = sym_boolean_literal,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_section_repeat1] = aux_sym_section_repeat1,
  [aux_sym_section_header_repeat1] = aux_sym_section_header_repeat1,
  [aux_sym_collection_repeat1] = aux_sym_collection_repeat1,
  [aux_sym_conditional_statement_repeat1] = aux_sym_conditional_statement_repeat1,
  [aux_sym_conditional_statement_repeat2] = aux_sym_conditional_statement_repeat2,
  [aux_sym_say_statement_repeat1] = aux_sym_say_statement_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_becomes] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_suppose] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_otherwise] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enough] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_say] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_snitch] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vibes_like] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_harshing_the_vibe_of] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_louder_than] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_quieter_than] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_has] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_copacetic] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_harsh] = {
    .visible = true,
    .named = false,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_section] = {
    .visible = true,
    .named = true,
  },
  [sym_section_header] = {
    .visible = true,
    .named = true,
  },
  [sym_entry] = {
    .visible = true,
    .named = true,
  },
  [sym_collection] = {
    .visible = true,
    .named = true,
  },
  [sym_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_conditional_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_say_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_snitch_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_term] = {
    .visible = true,
    .named = true,
  },
  [sym_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_section_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_section_header_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_collection_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_conditional_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_conditional_statement_repeat2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_say_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_alternative = 1,
  field_argument = 2,
  field_body = 3,
  field_condition = 4,
  field_header = 5,
  field_item = 6,
  field_key = 7,
  field_left = 8,
  field_object = 9,
  field_operator = 10,
  field_property = 11,
  field_right = 12,
  field_target = 13,
  field_value = 14,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alternative] = "alternative",
  [field_argument] = "argument",
  [field_body] = "body",
  [field_condition] = "condition",
  [field_header] = "header",
  [field_item] = "item",
  [field_key] = "key",
  [field_left] = "left",
  [field_object] = "object",
  [field_operator] = "operator",
  [field_property] = "property",
  [field_right] = "right",
  [field_target] = "target",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 1},
  [6] = {.index = 5, .length = 1},
  [7] = {.index = 6, .length = 2},
  [8] = {.index = 8, .length = 2},
  [9] = {.index = 10, .length = 2},
  [10] = {.index = 12, .length = 2},
  [11] = {.index = 14, .length = 1},
  [12] = {.index = 15, .length = 2},
  [13] = {.index = 17, .length = 2},
  [14] = {.index = 19, .length = 3},
  [15] = {.index = 22, .length = 1},
  [16] = {.index = 23, .length = 2},
  [17] = {.index = 25, .length = 2},
  [18] = {.index = 27, .length = 1},
  [19] = {.index = 28, .length = 2},
  [20] = {.index = 30, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_header, 0},
  [1] =
    {field_left, 0},
  [2] =
    {field_argument, 0},
  [3] =
    {field_argument, 1, .inherited = true},
  [4] =
    {field_condition, 1},
  [5] =
    {field_body, 0},
  [6] =
    {field_argument, 0, .inherited = true},
    {field_argument, 1, .inherited = true},
  [8] =
    {field_key, 0},
    {field_value, 2},
  [10] =
    {field_target, 0},
    {field_value, 2},
  [12] =
    {field_object, 0},
    {field_property, 2},
  [14] =
    {field_alternative, 0},
  [15] =
    {field_body, 2, .inherited = true},
    {field_condition, 1},
  [17] =
    {field_body, 0, .inherited = true},
    {field_body, 1, .inherited = true},
  [19] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
  [22] =
    {field_item, 0},
  [23] =
    {field_alternative, 3, .inherited = true},
    {field_condition, 1},
  [25] =
    {field_alternative, 0, .inherited = true},
    {field_alternative, 1, .inherited = true},
  [27] =
    {field_item, 1, .inherited = true},
  [28] =
    {field_item, 0, .inherited = true},
    {field_item, 1, .inherited = true},
  [30] =
    {field_alternative, 4, .inherited = true},
    {field_body, 2, .inherited = true},
    {field_condition, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 2,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 3,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 4,
  [23] = 7,
  [24] = 24,
  [25] = 6,
  [26] = 26,
  [27] = 5,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 42,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 63,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(2);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '.') ADVANCE(8);
      if (lookahead == ':') ADVANCE(5);
      if (lookahead == '[') ADVANCE(3);
      if (lookahead == ']') ADVANCE(4);
      if (lookahead == '{') ADVANCE(6);
      if (lookahead == '}') ADVANCE(7);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(10);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(9);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_string_literal);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(10);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      ADVANCE_MAP(
        'a', 1,
        'b', 2,
        'c', 3,
        'e', 4,
        'h', 5,
        'l', 6,
        'o', 7,
        'q', 8,
        's', 9,
        'v', 10,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == 'n') ADVANCE(11);
      END_STATE();
    case 2:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 3:
      if (lookahead == 'o') ADVANCE(13);
      END_STATE();
    case 4:
      if (lookahead == 'n') ADVANCE(14);
      END_STATE();
    case 5:
      if (lookahead == 'a') ADVANCE(15);
      END_STATE();
    case 6:
      if (lookahead == 'o') ADVANCE(16);
      END_STATE();
    case 7:
      if (lookahead == 'r') ADVANCE(17);
      if (lookahead == 't') ADVANCE(18);
      END_STATE();
    case 8:
      if (lookahead == 'u') ADVANCE(19);
      END_STATE();
    case 9:
      if (lookahead == 'a') ADVANCE(20);
      if (lookahead == 'n') ADVANCE(21);
      if (lookahead == 'u') ADVANCE(22);
      END_STATE();
    case 10:
      if (lookahead == 'i') ADVANCE(23);
      END_STATE();
    case 11:
      if (lookahead == 'd') ADVANCE(24);
      END_STATE();
    case 12:
      if (lookahead == 'c') ADVANCE(25);
      END_STATE();
    case 13:
      if (lookahead == 'p') ADVANCE(26);
      END_STATE();
    case 14:
      if (lookahead == 'o') ADVANCE(27);
      END_STATE();
    case 15:
      if (lookahead == 'r') ADVANCE(28);
      if (lookahead == 's') ADVANCE(29);
      END_STATE();
    case 16:
      if (lookahead == 'u') ADVANCE(30);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 18:
      if (lookahead == 'h') ADVANCE(31);
      END_STATE();
    case 19:
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 20:
      if (lookahead == 'y') ADVANCE(33);
      END_STATE();
    case 21:
      if (lookahead == 'i') ADVANCE(34);
      END_STATE();
    case 22:
      if (lookahead == 'p') ADVANCE(35);
      END_STATE();
    case 23:
      if (lookahead == 'b') ADVANCE(36);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 25:
      if (lookahead == 'o') ADVANCE(37);
      END_STATE();
    case 26:
      if (lookahead == 'a') ADVANCE(38);
      END_STATE();
    case 27:
      if (lookahead == 'u') ADVANCE(39);
      END_STATE();
    case 28:
      if (lookahead == 's') ADVANCE(40);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_has);
      END_STATE();
    case 30:
      if (lookahead == 'd') ADVANCE(41);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(43);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_say);
      END_STATE();
    case 34:
      if (lookahead == 't') ADVANCE(44);
      END_STATE();
    case 35:
      if (lookahead == 'p') ADVANCE(45);
      END_STATE();
    case 36:
      if (lookahead == 'e') ADVANCE(46);
      END_STATE();
    case 37:
      if (lookahead == 'm') ADVANCE(47);
      END_STATE();
    case 38:
      if (lookahead == 'c') ADVANCE(48);
      END_STATE();
    case 39:
      if (lookahead == 'g') ADVANCE(49);
      END_STATE();
    case 40:
      if (lookahead == 'h') ADVANCE(50);
      END_STATE();
    case 41:
      if (lookahead == 'e') ADVANCE(51);
      END_STATE();
    case 42:
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 43:
      if (lookahead == 't') ADVANCE(53);
      END_STATE();
    case 44:
      if (lookahead == 'c') ADVANCE(54);
      END_STATE();
    case 45:
      if (lookahead == 'o') ADVANCE(55);
      END_STATE();
    case 46:
      if (lookahead == 's') ADVANCE(56);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(57);
      END_STATE();
    case 48:
      if (lookahead == 'e') ADVANCE(58);
      END_STATE();
    case 49:
      if (lookahead == 'h') ADVANCE(59);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_harsh);
      if (lookahead == 'i') ADVANCE(60);
      END_STATE();
    case 51:
      if (lookahead == 'r') ADVANCE(61);
      END_STATE();
    case 52:
      if (lookahead == 'w') ADVANCE(62);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(63);
      END_STATE();
    case 54:
      if (lookahead == 'h') ADVANCE(64);
      END_STATE();
    case 55:
      if (lookahead == 's') ADVANCE(65);
      END_STATE();
    case 56:
      if (lookahead == '_') ADVANCE(66);
      END_STATE();
    case 57:
      if (lookahead == 's') ADVANCE(67);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(68);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_enough);
      END_STATE();
    case 60:
      if (lookahead == 'n') ADVANCE(69);
      END_STATE();
    case 61:
      if (lookahead == '_') ADVANCE(70);
      END_STATE();
    case 62:
      if (lookahead == 'i') ADVANCE(71);
      END_STATE();
    case 63:
      if (lookahead == 'r') ADVANCE(72);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_snitch);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(73);
      END_STATE();
    case 66:
      if (lookahead == 'l') ADVANCE(74);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_becomes);
      END_STATE();
    case 68:
      if (lookahead == 'i') ADVANCE(75);
      END_STATE();
    case 69:
      if (lookahead == 'g') ADVANCE(76);
      END_STATE();
    case 70:
      if (lookahead == 't') ADVANCE(77);
      END_STATE();
    case 71:
      if (lookahead == 's') ADVANCE(78);
      END_STATE();
    case 72:
      if (lookahead == '_') ADVANCE(79);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_suppose);
      END_STATE();
    case 74:
      if (lookahead == 'i') ADVANCE(80);
      END_STATE();
    case 75:
      if (lookahead == 'c') ADVANCE(81);
      END_STATE();
    case 76:
      if (lookahead == '_') ADVANCE(82);
      END_STATE();
    case 77:
      if (lookahead == 'h') ADVANCE(83);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(84);
      END_STATE();
    case 79:
      if (lookahead == 't') ADVANCE(85);
      END_STATE();
    case 80:
      if (lookahead == 'k') ADVANCE(86);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_copacetic);
      END_STATE();
    case 82:
      if (lookahead == 't') ADVANCE(87);
      END_STATE();
    case 83:
      if (lookahead == 'a') ADVANCE(88);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_otherwise);
      END_STATE();
    case 85:
      if (lookahead == 'h') ADVANCE(89);
      END_STATE();
    case 86:
      if (lookahead == 'e') ADVANCE(90);
      END_STATE();
    case 87:
      if (lookahead == 'h') ADVANCE(91);
      END_STATE();
    case 88:
      if (lookahead == 'n') ADVANCE(92);
      END_STATE();
    case 89:
      if (lookahead == 'a') ADVANCE(93);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_vibes_like);
      END_STATE();
    case 91:
      if (lookahead == 'e') ADVANCE(94);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_louder_than);
      END_STATE();
    case 93:
      if (lookahead == 'n') ADVANCE(95);
      END_STATE();
    case 94:
      if (lookahead == '_') ADVANCE(96);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_quieter_than);
      END_STATE();
    case 96:
      if (lookahead == 'v') ADVANCE(97);
      END_STATE();
    case 97:
      if (lookahead == 'i') ADVANCE(98);
      END_STATE();
    case 98:
      if (lookahead == 'b') ADVANCE(99);
      END_STATE();
    case 99:
      if (lookahead == 'e') ADVANCE(100);
      END_STATE();
    case 100:
      if (lookahead == '_') ADVANCE(101);
      END_STATE();
    case 101:
      if (lookahead == 'o') ADVANCE(102);
      END_STATE();
    case 102:
      if (lookahead == 'f') ADVANCE(103);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_harshing_the_vibe_of);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_becomes] = ACTIONS(1),
    [anon_sym_suppose] = ACTIONS(1),
    [anon_sym_otherwise] = ACTIONS(1),
    [anon_sym_enough] = ACTIONS(1),
    [anon_sym_say] = ACTIONS(1),
    [anon_sym_snitch] = ACTIONS(1),
    [anon_sym_vibes_like] = ACTIONS(1),
    [anon_sym_harshing_the_vibe_of] = ACTIONS(1),
    [anon_sym_louder_than] = ACTIONS(1),
    [anon_sym_quieter_than] = ACTIONS(1),
    [anon_sym_has] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_or] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_copacetic] = ACTIONS(1),
    [anon_sym_harsh] = ACTIONS(1),
    [sym_string_literal] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(64),
    [sym_section] = STATE(51),
    [sym_section_header] = STATE(12),
    [aux_sym_source_file_repeat1] = STATE(51),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    STATE(43), 1,
      sym_operator,
    ACTIONS(7), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(11), 7,
      anon_sym_vibes_like,
      anon_sym_harshing_the_vibe_of,
      anon_sym_louder_than,
      anon_sym_quieter_than,
      anon_sym_has,
      anon_sym_and,
      anon_sym_or,
    ACTIONS(9), 8,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [28] = 3,
    ACTIONS(17), 1,
      anon_sym_DOT,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 15,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_vibes_like,
      anon_sym_harshing_the_vibe_of,
      anon_sym_louder_than,
      anon_sym_quieter_than,
      anon_sym_has,
      anon_sym_and,
      anon_sym_or,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [54] = 2,
    ACTIONS(19), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(21), 15,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_vibes_like,
      anon_sym_harshing_the_vibe_of,
      anon_sym_louder_than,
      anon_sym_quieter_than,
      anon_sym_has,
      anon_sym_and,
      anon_sym_or,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [77] = 2,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 15,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_vibes_like,
      anon_sym_harshing_the_vibe_of,
      anon_sym_louder_than,
      anon_sym_quieter_than,
      anon_sym_has,
      anon_sym_and,
      anon_sym_or,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [100] = 2,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(25), 15,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_vibes_like,
      anon_sym_harshing_the_vibe_of,
      anon_sym_louder_than,
      anon_sym_quieter_than,
      anon_sym_has,
      anon_sym_and,
      anon_sym_or,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [123] = 2,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 15,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_vibes_like,
      anon_sym_harshing_the_vibe_of,
      anon_sym_louder_than,
      anon_sym_quieter_than,
      anon_sym_has,
      anon_sym_and,
      anon_sym_or,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [146] = 10,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(37), 1,
      sym_string_literal,
    STATE(2), 1,
      sym_term,
    STATE(5), 1,
      sym_attribute,
    STATE(7), 1,
      sym_boolean_literal,
    STATE(8), 1,
      aux_sym_say_statement_repeat1,
    STATE(19), 1,
      sym_expression,
    ACTIONS(27), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(34), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
    ACTIONS(32), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
  [183] = 10,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(2), 1,
      sym_term,
    STATE(5), 1,
      sym_attribute,
    STATE(7), 1,
      sym_boolean_literal,
    STATE(8), 1,
      aux_sym_say_statement_repeat1,
    STATE(19), 1,
      sym_expression,
    ACTIONS(40), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
    ACTIONS(44), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
  [220] = 10,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(2), 1,
      sym_term,
    STATE(5), 1,
      sym_attribute,
    STATE(7), 1,
      sym_boolean_literal,
    STATE(8), 1,
      aux_sym_say_statement_repeat1,
    STATE(19), 1,
      sym_expression,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
    ACTIONS(50), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(52), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
  [257] = 4,
    STATE(42), 1,
      sym_operator,
    ACTIONS(7), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(9), 6,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
    ACTIONS(11), 7,
      anon_sym_vibes_like,
      anon_sym_harshing_the_vibe_of,
      anon_sym_louder_than,
      anon_sym_quieter_than,
      anon_sym_has,
      anon_sym_and,
      anon_sym_or,
  [282] = 7,
    ACTIONS(56), 1,
      sym_identifier,
    ACTIONS(58), 1,
      anon_sym_suppose,
    ACTIONS(60), 1,
      anon_sym_say,
    ACTIONS(62), 1,
      anon_sym_snitch,
    ACTIONS(54), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    STATE(14), 3,
      sym_entry,
      sym_statement,
      aux_sym_section_repeat1,
    STATE(39), 4,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
      sym_snitch_statement,
  [310] = 7,
    ACTIONS(66), 1,
      sym_identifier,
    ACTIONS(69), 1,
      anon_sym_suppose,
    ACTIONS(72), 1,
      anon_sym_say,
    ACTIONS(75), 1,
      anon_sym_snitch,
    ACTIONS(64), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    STATE(13), 3,
      sym_entry,
      sym_statement,
      aux_sym_section_repeat1,
    STATE(39), 4,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
      sym_snitch_statement,
  [338] = 7,
    ACTIONS(56), 1,
      sym_identifier,
    ACTIONS(58), 1,
      anon_sym_suppose,
    ACTIONS(60), 1,
      anon_sym_say,
    ACTIONS(62), 1,
      anon_sym_snitch,
    ACTIONS(78), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    STATE(13), 3,
      sym_entry,
      sym_statement,
      aux_sym_section_repeat1,
    STATE(39), 4,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
      sym_snitch_statement,
  [366] = 9,
    ACTIONS(58), 1,
      anon_sym_suppose,
    ACTIONS(60), 1,
      anon_sym_say,
    ACTIONS(62), 1,
      anon_sym_snitch,
    ACTIONS(80), 1,
      sym_identifier,
    ACTIONS(82), 1,
      anon_sym_otherwise,
    ACTIONS(84), 1,
      anon_sym_enough,
    STATE(17), 1,
      aux_sym_conditional_statement_repeat1,
    STATE(44), 1,
      sym_statement,
    STATE(39), 4,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
      sym_snitch_statement,
  [397] = 8,
    ACTIONS(86), 1,
      sym_identifier,
    ACTIONS(89), 1,
      anon_sym_suppose,
    ACTIONS(94), 1,
      anon_sym_say,
    ACTIONS(97), 1,
      anon_sym_snitch,
    STATE(16), 1,
      aux_sym_conditional_statement_repeat1,
    STATE(44), 1,
      sym_statement,
    ACTIONS(92), 2,
      anon_sym_otherwise,
      anon_sym_enough,
    STATE(39), 4,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
      sym_snitch_statement,
  [426] = 9,
    ACTIONS(58), 1,
      anon_sym_suppose,
    ACTIONS(60), 1,
      anon_sym_say,
    ACTIONS(62), 1,
      anon_sym_snitch,
    ACTIONS(80), 1,
      sym_identifier,
    ACTIONS(100), 1,
      anon_sym_otherwise,
    ACTIONS(102), 1,
      anon_sym_enough,
    STATE(16), 1,
      aux_sym_conditional_statement_repeat1,
    STATE(44), 1,
      sym_statement,
    STATE(39), 4,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
      sym_snitch_statement,
  [457] = 3,
    ACTIONS(104), 1,
      anon_sym_DOT,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 8,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [476] = 2,
    ACTIONS(106), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(108), 8,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [492] = 2,
    ACTIONS(110), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(112), 8,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [508] = 8,
    ACTIONS(58), 1,
      anon_sym_suppose,
    ACTIONS(60), 1,
      anon_sym_say,
    ACTIONS(62), 1,
      anon_sym_snitch,
    ACTIONS(80), 1,
      sym_identifier,
    ACTIONS(114), 1,
      anon_sym_enough,
    STATE(24), 1,
      aux_sym_conditional_statement_repeat2,
    STATE(50), 1,
      sym_statement,
    STATE(39), 4,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
      sym_snitch_statement,
  [536] = 2,
    ACTIONS(19), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(21), 8,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [552] = 2,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 8,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [568] = 8,
    ACTIONS(58), 1,
      anon_sym_suppose,
    ACTIONS(60), 1,
      anon_sym_say,
    ACTIONS(62), 1,
      anon_sym_snitch,
    ACTIONS(80), 1,
      sym_identifier,
    ACTIONS(116), 1,
      anon_sym_enough,
    STATE(29), 1,
      aux_sym_conditional_statement_repeat2,
    STATE(50), 1,
      sym_statement,
    STATE(39), 4,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
      sym_snitch_statement,
  [596] = 2,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(25), 8,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [612] = 8,
    ACTIONS(58), 1,
      anon_sym_suppose,
    ACTIONS(60), 1,
      anon_sym_say,
    ACTIONS(62), 1,
      anon_sym_snitch,
    ACTIONS(80), 1,
      sym_identifier,
    ACTIONS(118), 1,
      anon_sym_enough,
    STATE(29), 1,
      aux_sym_conditional_statement_repeat2,
    STATE(50), 1,
      sym_statement,
    STATE(39), 4,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
      sym_snitch_statement,
  [640] = 2,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 8,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [656] = 8,
    ACTIONS(58), 1,
      anon_sym_suppose,
    ACTIONS(60), 1,
      anon_sym_say,
    ACTIONS(62), 1,
      anon_sym_snitch,
    ACTIONS(80), 1,
      sym_identifier,
    ACTIONS(120), 1,
      anon_sym_enough,
    STATE(26), 1,
      aux_sym_conditional_statement_repeat2,
    STATE(50), 1,
      sym_statement,
    STATE(39), 4,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
      sym_snitch_statement,
  [684] = 8,
    ACTIONS(122), 1,
      sym_identifier,
    ACTIONS(125), 1,
      anon_sym_suppose,
    ACTIONS(128), 1,
      anon_sym_enough,
    ACTIONS(130), 1,
      anon_sym_say,
    ACTIONS(133), 1,
      anon_sym_snitch,
    STATE(29), 1,
      aux_sym_conditional_statement_repeat2,
    STATE(50), 1,
      sym_statement,
    STATE(39), 4,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
      sym_snitch_statement,
  [712] = 8,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(2), 1,
      sym_term,
    STATE(5), 1,
      sym_attribute,
    STATE(7), 1,
      sym_boolean_literal,
    STATE(9), 1,
      aux_sym_say_statement_repeat1,
    STATE(19), 1,
      sym_expression,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
  [738] = 8,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(2), 1,
      sym_term,
    STATE(5), 1,
      sym_attribute,
    STATE(7), 1,
      sym_boolean_literal,
    STATE(10), 1,
      aux_sym_say_statement_repeat1,
    STATE(19), 1,
      sym_expression,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
  [764] = 7,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(5), 1,
      sym_attribute,
    STATE(7), 1,
      sym_boolean_literal,
    STATE(11), 1,
      sym_term,
    STATE(35), 1,
      sym_expression,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
  [787] = 2,
    ACTIONS(136), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(138), 6,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [800] = 7,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(5), 1,
      sym_attribute,
    STATE(7), 1,
      sym_boolean_literal,
    STATE(11), 1,
      sym_term,
    STATE(15), 1,
      sym_expression,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
  [823] = 2,
    ACTIONS(140), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(142), 6,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [836] = 2,
    ACTIONS(144), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(146), 6,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [849] = 2,
    ACTIONS(148), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(150), 6,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [862] = 2,
    ACTIONS(152), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(154), 6,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [875] = 2,
    ACTIONS(156), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(158), 6,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [888] = 2,
    ACTIONS(160), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(162), 6,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [901] = 2,
    ACTIONS(164), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(166), 6,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [914] = 6,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(5), 1,
      sym_attribute,
    STATE(7), 1,
      sym_boolean_literal,
    STATE(20), 1,
      sym_term,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
  [934] = 6,
    ACTIONS(168), 1,
      sym_identifier,
    ACTIONS(172), 1,
      sym_string_literal,
    STATE(20), 1,
      sym_term,
    STATE(23), 1,
      sym_boolean_literal,
    STATE(27), 1,
      sym_attribute,
    ACTIONS(170), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
  [954] = 1,
    ACTIONS(174), 6,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [963] = 2,
    ACTIONS(176), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(178), 4,
      anon_sym_suppose,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [974] = 2,
    ACTIONS(180), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(182), 4,
      anon_sym_suppose,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [985] = 2,
    ACTIONS(184), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(186), 4,
      anon_sym_suppose,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [996] = 2,
    ACTIONS(188), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(190), 4,
      anon_sym_suppose,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [1007] = 4,
    ACTIONS(192), 1,
      ts_builtin_sym_end,
    ACTIONS(194), 1,
      anon_sym_LBRACK,
    STATE(12), 1,
      sym_section_header,
    STATE(49), 2,
      sym_section,
      aux_sym_source_file_repeat1,
  [1021] = 1,
    ACTIONS(197), 5,
      anon_sym_suppose,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_snitch,
      sym_identifier,
  [1029] = 4,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(199), 1,
      ts_builtin_sym_end,
    STATE(12), 1,
      sym_section_header,
    STATE(49), 2,
      sym_section,
      aux_sym_source_file_repeat1,
  [1043] = 2,
    ACTIONS(203), 1,
      sym_string_literal,
    ACTIONS(201), 3,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [1052] = 3,
    ACTIONS(205), 1,
      anon_sym_RBRACE,
    ACTIONS(207), 1,
      sym_string_literal,
    STATE(55), 1,
      aux_sym_collection_repeat1,
  [1062] = 3,
    ACTIONS(207), 1,
      sym_string_literal,
    ACTIONS(209), 1,
      anon_sym_RBRACE,
    STATE(53), 1,
      aux_sym_collection_repeat1,
  [1072] = 3,
    ACTIONS(211), 1,
      anon_sym_RBRACE,
    ACTIONS(213), 1,
      sym_string_literal,
    STATE(55), 1,
      aux_sym_collection_repeat1,
  [1082] = 3,
    ACTIONS(216), 1,
      anon_sym_LBRACE,
    ACTIONS(218), 1,
      sym_string_literal,
    STATE(46), 1,
      sym_collection,
  [1092] = 3,
    ACTIONS(220), 1,
      sym_identifier,
    ACTIONS(223), 1,
      anon_sym_RBRACK,
    STATE(57), 1,
      aux_sym_section_header_repeat1,
  [1102] = 3,
    ACTIONS(225), 1,
      sym_identifier,
    ACTIONS(227), 1,
      anon_sym_RBRACK,
    STATE(57), 1,
      aux_sym_section_header_repeat1,
  [1112] = 2,
    ACTIONS(229), 1,
      sym_identifier,
    STATE(58), 1,
      aux_sym_section_header_repeat1,
  [1119] = 1,
    ACTIONS(231), 2,
      anon_sym_RBRACE,
      sym_string_literal,
  [1124] = 2,
    ACTIONS(233), 1,
      anon_sym_COLON,
    ACTIONS(235), 1,
      anon_sym_becomes,
  [1131] = 1,
    ACTIONS(235), 1,
      anon_sym_becomes,
  [1135] = 1,
    ACTIONS(237), 1,
      sym_identifier,
  [1139] = 1,
    ACTIONS(239), 1,
      ts_builtin_sym_end,
  [1143] = 1,
    ACTIONS(241), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 28,
  [SMALL_STATE(4)] = 54,
  [SMALL_STATE(5)] = 77,
  [SMALL_STATE(6)] = 100,
  [SMALL_STATE(7)] = 123,
  [SMALL_STATE(8)] = 146,
  [SMALL_STATE(9)] = 183,
  [SMALL_STATE(10)] = 220,
  [SMALL_STATE(11)] = 257,
  [SMALL_STATE(12)] = 282,
  [SMALL_STATE(13)] = 310,
  [SMALL_STATE(14)] = 338,
  [SMALL_STATE(15)] = 366,
  [SMALL_STATE(16)] = 397,
  [SMALL_STATE(17)] = 426,
  [SMALL_STATE(18)] = 457,
  [SMALL_STATE(19)] = 476,
  [SMALL_STATE(20)] = 492,
  [SMALL_STATE(21)] = 508,
  [SMALL_STATE(22)] = 536,
  [SMALL_STATE(23)] = 552,
  [SMALL_STATE(24)] = 568,
  [SMALL_STATE(25)] = 596,
  [SMALL_STATE(26)] = 612,
  [SMALL_STATE(27)] = 640,
  [SMALL_STATE(28)] = 656,
  [SMALL_STATE(29)] = 684,
  [SMALL_STATE(30)] = 712,
  [SMALL_STATE(31)] = 738,
  [SMALL_STATE(32)] = 764,
  [SMALL_STATE(33)] = 787,
  [SMALL_STATE(34)] = 800,
  [SMALL_STATE(35)] = 823,
  [SMALL_STATE(36)] = 836,
  [SMALL_STATE(37)] = 849,
  [SMALL_STATE(38)] = 862,
  [SMALL_STATE(39)] = 875,
  [SMALL_STATE(40)] = 888,
  [SMALL_STATE(41)] = 901,
  [SMALL_STATE(42)] = 914,
  [SMALL_STATE(43)] = 934,
  [SMALL_STATE(44)] = 954,
  [SMALL_STATE(45)] = 963,
  [SMALL_STATE(46)] = 974,
  [SMALL_STATE(47)] = 985,
  [SMALL_STATE(48)] = 996,
  [SMALL_STATE(49)] = 1007,
  [SMALL_STATE(50)] = 1021,
  [SMALL_STATE(51)] = 1029,
  [SMALL_STATE(52)] = 1043,
  [SMALL_STATE(53)] = 1052,
  [SMALL_STATE(54)] = 1062,
  [SMALL_STATE(55)] = 1072,
  [SMALL_STATE(56)] = 1082,
  [SMALL_STATE(57)] = 1092,
  [SMALL_STATE(58)] = 1102,
  [SMALL_STATE(59)] = 1112,
  [SMALL_STATE(60)] = 1119,
  [SMALL_STATE(61)] = 1124,
  [SMALL_STATE(62)] = 1131,
  [SMALL_STATE(63)] = 1135,
  [SMALL_STATE(64)] = 1139,
  [SMALL_STATE(65)] = 1143,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1, 0, 2),
  [9] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1, 0, 2),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term, 1, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_term, 1, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3, 0, 10),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3, 0, 10),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean_literal, 1, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_say_statement_repeat1, 2, 0, 7),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_say_statement_repeat1, 2, 0, 7), SHIFT_REPEAT(3),
  [32] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_say_statement_repeat1, 2, 0, 7),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_say_statement_repeat1, 2, 0, 7), SHIFT_REPEAT(6),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_say_statement_repeat1, 2, 0, 7), SHIFT_REPEAT(7),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_snitch_statement, 2, 0, 4),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_snitch_statement, 2, 0, 4),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_say_statement, 2, 0, 4),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_say_statement, 2, 0, 4),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 1, 0, 1),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_section_repeat1, 2, 0, 0),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_section_repeat1, 2, 0, 0), SHIFT_REPEAT(61),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_section_repeat1, 2, 0, 0), SHIFT_REPEAT(34),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_section_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_section_repeat1, 2, 0, 0), SHIFT_REPEAT(30),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 2, 0, 1),
  [80] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [82] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [84] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [86] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat1, 2, 0, 13), SHIFT_REPEAT(62),
  [89] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat1, 2, 0, 13), SHIFT_REPEAT(34),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat1, 2, 0, 13),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat1, 2, 0, 13), SHIFT_REPEAT(31),
  [97] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat1, 2, 0, 13), SHIFT_REPEAT(30),
  [100] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [102] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [104] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_say_statement_repeat1, 1, 0, 3),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_say_statement_repeat1, 1, 0, 3),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 3, 0, 14),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 3, 0, 14),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [120] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [122] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat2, 2, 0, 17), SHIFT_REPEAT(62),
  [125] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat2, 2, 0, 17), SHIFT_REPEAT(34),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat2, 2, 0, 17),
  [130] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat2, 2, 0, 17), SHIFT_REPEAT(31),
  [133] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat2, 2, 0, 17), SHIFT_REPEAT(30),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 6, 0, 20),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 6, 0, 20),
  [140] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_statement, 3, 0, 9),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignment_statement, 3, 0, 9),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 3, 0, 5),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 3, 0, 5),
  [148] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 4, 0, 5),
  [150] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 4, 0, 5),
  [152] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 5, 0, 12),
  [154] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 5, 0, 12),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1, 0, 0),
  [158] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 1, 0, 0),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 4, 0, 12),
  [162] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 4, 0, 12),
  [164] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 5, 0, 16),
  [166] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 5, 0, 16),
  [168] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [170] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [172] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat1, 1, 0, 6),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_collection, 3, 0, 18),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_collection, 3, 0, 18),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entry, 3, 0, 8),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entry, 3, 0, 8),
  [184] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_header, 3, 0, 0),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section_header, 3, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_collection, 2, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_collection, 2, 0, 0),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [194] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(59),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat2, 1, 0, 11),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator, 1, 0, 0),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator, 1, 0, 0),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_collection_repeat1, 2, 0, 19),
  [213] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_collection_repeat1, 2, 0, 19), SHIFT_REPEAT(60),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [220] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_section_header_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [223] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_section_header_repeat1, 2, 0, 0),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [231] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_collection_repeat1, 1, 0, 15),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [239] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_ripple(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
