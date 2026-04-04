#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 63
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 43
#define ALIAS_COUNT 0
#define TOKEN_COUNT 23
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 15
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 22

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
  anon_sym_vibes_like = 12,
  anon_sym_harshing_the_vibe_of = 13,
  anon_sym_louder_than = 14,
  anon_sym_quieter_than = 15,
  anon_sym_has = 16,
  anon_sym_and = 17,
  anon_sym_or = 18,
  anon_sym_DOT = 19,
  anon_sym_copacetic = 20,
  anon_sym_harsh = 21,
  sym_string_literal = 22,
  sym_source_file = 23,
  sym_section = 24,
  sym_section_header = 25,
  sym_entry = 26,
  sym_collection = 27,
  sym_statement = 28,
  sym_assignment_statement = 29,
  sym_conditional_statement = 30,
  sym_say_statement = 31,
  sym_expression = 32,
  sym_operator = 33,
  sym_term = 34,
  sym_attribute = 35,
  sym_boolean_literal = 36,
  aux_sym_source_file_repeat1 = 37,
  aux_sym_section_repeat1 = 38,
  aux_sym_collection_repeat1 = 39,
  aux_sym_conditional_statement_repeat1 = 40,
  aux_sym_conditional_statement_repeat2 = 41,
  aux_sym_say_statement_repeat1 = 42,
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
  [sym_expression] = "expression",
  [sym_operator] = "operator",
  [sym_term] = "term",
  [sym_attribute] = "attribute",
  [sym_boolean_literal] = "boolean_literal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_section_repeat1] = "section_repeat1",
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
  [sym_expression] = sym_expression,
  [sym_operator] = sym_operator,
  [sym_term] = sym_term,
  [sym_attribute] = sym_attribute,
  [sym_boolean_literal] = sym_boolean_literal,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_section_repeat1] = aux_sym_section_repeat1,
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
  field_name = 9,
  field_object = 10,
  field_operator = 11,
  field_property = 12,
  field_right = 13,
  field_target = 14,
  field_value = 15,
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
  [field_name] = "name",
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
  [7] = {.index = 6, .length = 1},
  [8] = {.index = 7, .length = 2},
  [9] = {.index = 9, .length = 2},
  [10] = {.index = 11, .length = 2},
  [11] = {.index = 13, .length = 2},
  [12] = {.index = 15, .length = 1},
  [13] = {.index = 16, .length = 2},
  [14] = {.index = 18, .length = 2},
  [15] = {.index = 20, .length = 3},
  [16] = {.index = 23, .length = 1},
  [17] = {.index = 24, .length = 2},
  [18] = {.index = 26, .length = 2},
  [19] = {.index = 28, .length = 1},
  [20] = {.index = 29, .length = 2},
  [21] = {.index = 31, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_header, 0},
  [1] =
    {field_name, 1},
  [2] =
    {field_left, 0},
  [3] =
    {field_argument, 0},
  [4] =
    {field_argument, 1, .inherited = true},
  [5] =
    {field_condition, 1},
  [6] =
    {field_body, 0},
  [7] =
    {field_argument, 0, .inherited = true},
    {field_argument, 1, .inherited = true},
  [9] =
    {field_key, 0},
    {field_value, 2},
  [11] =
    {field_target, 0},
    {field_value, 2},
  [13] =
    {field_object, 0},
    {field_property, 2},
  [15] =
    {field_alternative, 0},
  [16] =
    {field_body, 2, .inherited = true},
    {field_condition, 1},
  [18] =
    {field_body, 0, .inherited = true},
    {field_body, 1, .inherited = true},
  [20] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
  [23] =
    {field_item, 0},
  [24] =
    {field_alternative, 3, .inherited = true},
    {field_condition, 1},
  [26] =
    {field_alternative, 0, .inherited = true},
    {field_alternative, 1, .inherited = true},
  [28] =
    {field_item, 1, .inherited = true},
  [29] =
    {field_item, 0, .inherited = true},
    {field_item, 1, .inherited = true},
  [31] =
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
  [10] = 2,
  [11] = 11,
  [12] = 12,
  [13] = 3,
  [14] = 14,
  [15] = 15,
  [16] = 6,
  [17] = 7,
  [18] = 18,
  [19] = 5,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 4,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 33,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
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
  [62] = 59,
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
      if (lookahead == 'u') ADVANCE(21);
      END_STATE();
    case 10:
      if (lookahead == 'i') ADVANCE(22);
      END_STATE();
    case 11:
      if (lookahead == 'd') ADVANCE(23);
      END_STATE();
    case 12:
      if (lookahead == 'c') ADVANCE(24);
      END_STATE();
    case 13:
      if (lookahead == 'p') ADVANCE(25);
      END_STATE();
    case 14:
      if (lookahead == 'o') ADVANCE(26);
      END_STATE();
    case 15:
      if (lookahead == 'r') ADVANCE(27);
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 16:
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 18:
      if (lookahead == 'h') ADVANCE(30);
      END_STATE();
    case 19:
      if (lookahead == 'i') ADVANCE(31);
      END_STATE();
    case 20:
      if (lookahead == 'y') ADVANCE(32);
      END_STATE();
    case 21:
      if (lookahead == 'p') ADVANCE(33);
      END_STATE();
    case 22:
      if (lookahead == 'b') ADVANCE(34);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 24:
      if (lookahead == 'o') ADVANCE(35);
      END_STATE();
    case 25:
      if (lookahead == 'a') ADVANCE(36);
      END_STATE();
    case 26:
      if (lookahead == 'u') ADVANCE(37);
      END_STATE();
    case 27:
      if (lookahead == 's') ADVANCE(38);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_has);
      END_STATE();
    case 29:
      if (lookahead == 'd') ADVANCE(39);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(40);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_say);
      END_STATE();
    case 33:
      if (lookahead == 'p') ADVANCE(42);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(43);
      END_STATE();
    case 35:
      if (lookahead == 'm') ADVANCE(44);
      END_STATE();
    case 36:
      if (lookahead == 'c') ADVANCE(45);
      END_STATE();
    case 37:
      if (lookahead == 'g') ADVANCE(46);
      END_STATE();
    case 38:
      if (lookahead == 'h') ADVANCE(47);
      END_STATE();
    case 39:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 40:
      if (lookahead == 'r') ADVANCE(49);
      END_STATE();
    case 41:
      if (lookahead == 't') ADVANCE(50);
      END_STATE();
    case 42:
      if (lookahead == 'o') ADVANCE(51);
      END_STATE();
    case 43:
      if (lookahead == 's') ADVANCE(52);
      END_STATE();
    case 44:
      if (lookahead == 'e') ADVANCE(53);
      END_STATE();
    case 45:
      if (lookahead == 'e') ADVANCE(54);
      END_STATE();
    case 46:
      if (lookahead == 'h') ADVANCE(55);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_harsh);
      if (lookahead == 'i') ADVANCE(56);
      END_STATE();
    case 48:
      if (lookahead == 'r') ADVANCE(57);
      END_STATE();
    case 49:
      if (lookahead == 'w') ADVANCE(58);
      END_STATE();
    case 50:
      if (lookahead == 'e') ADVANCE(59);
      END_STATE();
    case 51:
      if (lookahead == 's') ADVANCE(60);
      END_STATE();
    case 52:
      if (lookahead == '_') ADVANCE(61);
      END_STATE();
    case 53:
      if (lookahead == 's') ADVANCE(62);
      END_STATE();
    case 54:
      if (lookahead == 't') ADVANCE(63);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_enough);
      END_STATE();
    case 56:
      if (lookahead == 'n') ADVANCE(64);
      END_STATE();
    case 57:
      if (lookahead == '_') ADVANCE(65);
      END_STATE();
    case 58:
      if (lookahead == 'i') ADVANCE(66);
      END_STATE();
    case 59:
      if (lookahead == 'r') ADVANCE(67);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(68);
      END_STATE();
    case 61:
      if (lookahead == 'l') ADVANCE(69);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_becomes);
      END_STATE();
    case 63:
      if (lookahead == 'i') ADVANCE(70);
      END_STATE();
    case 64:
      if (lookahead == 'g') ADVANCE(71);
      END_STATE();
    case 65:
      if (lookahead == 't') ADVANCE(72);
      END_STATE();
    case 66:
      if (lookahead == 's') ADVANCE(73);
      END_STATE();
    case 67:
      if (lookahead == '_') ADVANCE(74);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_suppose);
      END_STATE();
    case 69:
      if (lookahead == 'i') ADVANCE(75);
      END_STATE();
    case 70:
      if (lookahead == 'c') ADVANCE(76);
      END_STATE();
    case 71:
      if (lookahead == '_') ADVANCE(77);
      END_STATE();
    case 72:
      if (lookahead == 'h') ADVANCE(78);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(79);
      END_STATE();
    case 74:
      if (lookahead == 't') ADVANCE(80);
      END_STATE();
    case 75:
      if (lookahead == 'k') ADVANCE(81);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_copacetic);
      END_STATE();
    case 77:
      if (lookahead == 't') ADVANCE(82);
      END_STATE();
    case 78:
      if (lookahead == 'a') ADVANCE(83);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_otherwise);
      END_STATE();
    case 80:
      if (lookahead == 'h') ADVANCE(84);
      END_STATE();
    case 81:
      if (lookahead == 'e') ADVANCE(85);
      END_STATE();
    case 82:
      if (lookahead == 'h') ADVANCE(86);
      END_STATE();
    case 83:
      if (lookahead == 'n') ADVANCE(87);
      END_STATE();
    case 84:
      if (lookahead == 'a') ADVANCE(88);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_vibes_like);
      END_STATE();
    case 86:
      if (lookahead == 'e') ADVANCE(89);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_louder_than);
      END_STATE();
    case 88:
      if (lookahead == 'n') ADVANCE(90);
      END_STATE();
    case 89:
      if (lookahead == '_') ADVANCE(91);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_quieter_than);
      END_STATE();
    case 91:
      if (lookahead == 'v') ADVANCE(92);
      END_STATE();
    case 92:
      if (lookahead == 'i') ADVANCE(93);
      END_STATE();
    case 93:
      if (lookahead == 'b') ADVANCE(94);
      END_STATE();
    case 94:
      if (lookahead == 'e') ADVANCE(95);
      END_STATE();
    case 95:
      if (lookahead == '_') ADVANCE(96);
      END_STATE();
    case 96:
      if (lookahead == 'o') ADVANCE(97);
      END_STATE();
    case 97:
      if (lookahead == 'f') ADVANCE(98);
      END_STATE();
    case 98:
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
    [sym_source_file] = STATE(61),
    [sym_section] = STATE(48),
    [sym_section_header] = STATE(11),
    [aux_sym_source_file_repeat1] = STATE(48),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(5),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    STATE(35), 1,
      sym_operator,
    ACTIONS(7), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(9), 7,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
    ACTIONS(11), 7,
      anon_sym_vibes_like,
      anon_sym_harshing_the_vibe_of,
      anon_sym_louder_than,
      anon_sym_quieter_than,
      anon_sym_has,
      anon_sym_and,
      anon_sym_or,
  [27] = 3,
    ACTIONS(17), 1,
      anon_sym_DOT,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 14,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
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
  [52] = 2,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 14,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
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
  [74] = 2,
    ACTIONS(19), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(21), 14,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
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
  [96] = 2,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 14,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
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
  [118] = 2,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(25), 14,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
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
  [140] = 10,
    ACTIONS(29), 1,
      sym_identifier,
    ACTIONS(37), 1,
      sym_string_literal,
    STATE(2), 1,
      sym_term,
    STATE(4), 1,
      sym_boolean_literal,
    STATE(6), 1,
      sym_attribute,
    STATE(8), 1,
      aux_sym_say_statement_repeat1,
    STATE(20), 1,
      sym_expression,
    ACTIONS(27), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(34), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
    ACTIONS(32), 4,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
  [176] = 10,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(2), 1,
      sym_term,
    STATE(4), 1,
      sym_boolean_literal,
    STATE(6), 1,
      sym_attribute,
    STATE(8), 1,
      aux_sym_say_statement_repeat1,
    STATE(20), 1,
      sym_expression,
    ACTIONS(40), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
    ACTIONS(44), 4,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
  [212] = 4,
    STATE(33), 1,
      sym_operator,
    ACTIONS(7), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(9), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      sym_identifier,
    ACTIONS(11), 7,
      anon_sym_vibes_like,
      anon_sym_harshing_the_vibe_of,
      anon_sym_louder_than,
      anon_sym_quieter_than,
      anon_sym_has,
      anon_sym_and,
      anon_sym_or,
  [236] = 6,
    ACTIONS(52), 1,
      sym_identifier,
    ACTIONS(54), 1,
      anon_sym_suppose,
    ACTIONS(56), 1,
      anon_sym_say,
    ACTIONS(50), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    STATE(14), 3,
      sym_entry,
      sym_statement,
      aux_sym_section_repeat1,
    STATE(37), 3,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
  [260] = 6,
    ACTIONS(60), 1,
      sym_identifier,
    ACTIONS(63), 1,
      anon_sym_suppose,
    ACTIONS(66), 1,
      anon_sym_say,
    ACTIONS(58), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    STATE(12), 3,
      sym_entry,
      sym_statement,
      aux_sym_section_repeat1,
    STATE(37), 3,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
  [284] = 3,
    ACTIONS(69), 1,
      anon_sym_DOT,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 7,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [302] = 6,
    ACTIONS(52), 1,
      sym_identifier,
    ACTIONS(54), 1,
      anon_sym_suppose,
    ACTIONS(56), 1,
      anon_sym_say,
    ACTIONS(71), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    STATE(12), 3,
      sym_entry,
      sym_statement,
      aux_sym_section_repeat1,
    STATE(37), 3,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
  [326] = 8,
    ACTIONS(54), 1,
      anon_sym_suppose,
    ACTIONS(56), 1,
      anon_sym_say,
    ACTIONS(73), 1,
      sym_identifier,
    ACTIONS(75), 1,
      anon_sym_otherwise,
    ACTIONS(77), 1,
      anon_sym_enough,
    STATE(22), 1,
      aux_sym_conditional_statement_repeat1,
    STATE(42), 1,
      sym_statement,
    STATE(37), 3,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
  [353] = 2,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 7,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [368] = 2,
    ACTIONS(23), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(25), 7,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [383] = 8,
    ACTIONS(54), 1,
      anon_sym_suppose,
    ACTIONS(56), 1,
      anon_sym_say,
    ACTIONS(73), 1,
      sym_identifier,
    ACTIONS(79), 1,
      anon_sym_otherwise,
    ACTIONS(81), 1,
      anon_sym_enough,
    STATE(15), 1,
      aux_sym_conditional_statement_repeat1,
    STATE(42), 1,
      sym_statement,
    STATE(37), 3,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
  [410] = 2,
    ACTIONS(19), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(21), 7,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [425] = 2,
    ACTIONS(83), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(85), 7,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [440] = 2,
    ACTIONS(87), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(89), 7,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [455] = 7,
    ACTIONS(91), 1,
      sym_identifier,
    ACTIONS(94), 1,
      anon_sym_suppose,
    ACTIONS(99), 1,
      anon_sym_say,
    STATE(22), 1,
      aux_sym_conditional_statement_repeat1,
    STATE(42), 1,
      sym_statement,
    ACTIONS(97), 2,
      anon_sym_otherwise,
      anon_sym_enough,
    STATE(37), 3,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
  [480] = 2,
    ACTIONS(13), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_string_literal,
    ACTIONS(15), 7,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [495] = 8,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(2), 1,
      sym_term,
    STATE(4), 1,
      sym_boolean_literal,
    STATE(6), 1,
      sym_attribute,
    STATE(9), 1,
      aux_sym_say_statement_repeat1,
    STATE(20), 1,
      sym_expression,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
  [521] = 7,
    ACTIONS(54), 1,
      anon_sym_suppose,
    ACTIONS(56), 1,
      anon_sym_say,
    ACTIONS(73), 1,
      sym_identifier,
    ACTIONS(102), 1,
      anon_sym_enough,
    STATE(29), 1,
      aux_sym_conditional_statement_repeat2,
    STATE(49), 1,
      sym_statement,
    STATE(37), 3,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
  [545] = 7,
    ACTIONS(54), 1,
      anon_sym_suppose,
    ACTIONS(56), 1,
      anon_sym_say,
    ACTIONS(73), 1,
      sym_identifier,
    ACTIONS(104), 1,
      anon_sym_enough,
    STATE(28), 1,
      aux_sym_conditional_statement_repeat2,
    STATE(49), 1,
      sym_statement,
    STATE(37), 3,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
  [569] = 7,
    ACTIONS(54), 1,
      anon_sym_suppose,
    ACTIONS(56), 1,
      anon_sym_say,
    ACTIONS(73), 1,
      sym_identifier,
    ACTIONS(106), 1,
      anon_sym_enough,
    STATE(25), 1,
      aux_sym_conditional_statement_repeat2,
    STATE(49), 1,
      sym_statement,
    STATE(37), 3,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
  [593] = 7,
    ACTIONS(54), 1,
      anon_sym_suppose,
    ACTIONS(56), 1,
      anon_sym_say,
    ACTIONS(73), 1,
      sym_identifier,
    ACTIONS(108), 1,
      anon_sym_enough,
    STATE(29), 1,
      aux_sym_conditional_statement_repeat2,
    STATE(49), 1,
      sym_statement,
    STATE(37), 3,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
  [617] = 7,
    ACTIONS(110), 1,
      sym_identifier,
    ACTIONS(113), 1,
      anon_sym_suppose,
    ACTIONS(116), 1,
      anon_sym_enough,
    ACTIONS(118), 1,
      anon_sym_say,
    STATE(29), 1,
      aux_sym_conditional_statement_repeat2,
    STATE(49), 1,
      sym_statement,
    STATE(37), 3,
      sym_assignment_statement,
      sym_conditional_statement,
      sym_say_statement,
  [641] = 7,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(4), 1,
      sym_boolean_literal,
    STATE(6), 1,
      sym_attribute,
    STATE(10), 1,
      sym_term,
    STATE(34), 1,
      sym_expression,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
  [664] = 7,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(4), 1,
      sym_boolean_literal,
    STATE(6), 1,
      sym_attribute,
    STATE(10), 1,
      sym_term,
    STATE(18), 1,
      sym_expression,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
  [687] = 2,
    ACTIONS(121), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(123), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      sym_identifier,
  [699] = 6,
    ACTIONS(42), 1,
      sym_identifier,
    ACTIONS(48), 1,
      sym_string_literal,
    STATE(4), 1,
      sym_boolean_literal,
    STATE(6), 1,
      sym_attribute,
    STATE(21), 1,
      sym_term,
    ACTIONS(46), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
  [719] = 2,
    ACTIONS(125), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(127), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      sym_identifier,
  [731] = 6,
    ACTIONS(129), 1,
      sym_identifier,
    ACTIONS(133), 1,
      sym_string_literal,
    STATE(16), 1,
      sym_attribute,
    STATE(21), 1,
      sym_term,
    STATE(23), 1,
      sym_boolean_literal,
    ACTIONS(131), 2,
      anon_sym_copacetic,
      anon_sym_harsh,
  [751] = 2,
    ACTIONS(135), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(137), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      sym_identifier,
  [763] = 2,
    ACTIONS(139), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(141), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      sym_identifier,
  [775] = 2,
    ACTIONS(143), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(145), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      sym_identifier,
  [787] = 2,
    ACTIONS(147), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(149), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      sym_identifier,
  [799] = 2,
    ACTIONS(151), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(153), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      sym_identifier,
  [811] = 2,
    ACTIONS(155), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(157), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      sym_identifier,
  [823] = 1,
    ACTIONS(159), 5,
      anon_sym_suppose,
      anon_sym_otherwise,
      anon_sym_enough,
      anon_sym_say,
      sym_identifier,
  [831] = 2,
    ACTIONS(161), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(163), 3,
      anon_sym_suppose,
      anon_sym_say,
      sym_identifier,
  [841] = 2,
    ACTIONS(165), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(167), 3,
      anon_sym_suppose,
      anon_sym_say,
      sym_identifier,
  [851] = 2,
    ACTIONS(169), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(171), 3,
      anon_sym_suppose,
      anon_sym_say,
      sym_identifier,
  [861] = 2,
    ACTIONS(173), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
    ACTIONS(175), 3,
      anon_sym_suppose,
      anon_sym_say,
      sym_identifier,
  [871] = 4,
    ACTIONS(177), 1,
      ts_builtin_sym_end,
    ACTIONS(179), 1,
      anon_sym_LBRACK,
    STATE(11), 1,
      sym_section_header,
    STATE(47), 2,
      sym_section,
      aux_sym_source_file_repeat1,
  [885] = 4,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(182), 1,
      ts_builtin_sym_end,
    STATE(11), 1,
      sym_section_header,
    STATE(47), 2,
      sym_section,
      aux_sym_source_file_repeat1,
  [899] = 1,
    ACTIONS(184), 4,
      anon_sym_suppose,
      anon_sym_enough,
      anon_sym_say,
      sym_identifier,
  [906] = 2,
    ACTIONS(188), 1,
      sym_string_literal,
    ACTIONS(186), 3,
      anon_sym_copacetic,
      anon_sym_harsh,
      sym_identifier,
  [915] = 3,
    ACTIONS(190), 1,
      anon_sym_RBRACE,
    ACTIONS(192), 1,
      sym_string_literal,
    STATE(52), 1,
      aux_sym_collection_repeat1,
  [925] = 3,
    ACTIONS(192), 1,
      sym_string_literal,
    ACTIONS(194), 1,
      anon_sym_RBRACE,
    STATE(53), 1,
      aux_sym_collection_repeat1,
  [935] = 3,
    ACTIONS(196), 1,
      anon_sym_RBRACE,
    ACTIONS(198), 1,
      sym_string_literal,
    STATE(53), 1,
      aux_sym_collection_repeat1,
  [945] = 3,
    ACTIONS(201), 1,
      anon_sym_LBRACE,
    ACTIONS(203), 1,
      sym_string_literal,
    STATE(43), 1,
      sym_collection,
  [955] = 1,
    ACTIONS(205), 2,
      anon_sym_RBRACE,
      sym_string_literal,
  [960] = 2,
    ACTIONS(207), 1,
      anon_sym_COLON,
    ACTIONS(209), 1,
      anon_sym_becomes,
  [967] = 1,
    ACTIONS(211), 1,
      sym_string_literal,
  [971] = 1,
    ACTIONS(209), 1,
      anon_sym_becomes,
  [975] = 1,
    ACTIONS(213), 1,
      sym_identifier,
  [979] = 1,
    ACTIONS(215), 1,
      anon_sym_RBRACK,
  [983] = 1,
    ACTIONS(217), 1,
      ts_builtin_sym_end,
  [987] = 1,
    ACTIONS(219), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 27,
  [SMALL_STATE(4)] = 52,
  [SMALL_STATE(5)] = 74,
  [SMALL_STATE(6)] = 96,
  [SMALL_STATE(7)] = 118,
  [SMALL_STATE(8)] = 140,
  [SMALL_STATE(9)] = 176,
  [SMALL_STATE(10)] = 212,
  [SMALL_STATE(11)] = 236,
  [SMALL_STATE(12)] = 260,
  [SMALL_STATE(13)] = 284,
  [SMALL_STATE(14)] = 302,
  [SMALL_STATE(15)] = 326,
  [SMALL_STATE(16)] = 353,
  [SMALL_STATE(17)] = 368,
  [SMALL_STATE(18)] = 383,
  [SMALL_STATE(19)] = 410,
  [SMALL_STATE(20)] = 425,
  [SMALL_STATE(21)] = 440,
  [SMALL_STATE(22)] = 455,
  [SMALL_STATE(23)] = 480,
  [SMALL_STATE(24)] = 495,
  [SMALL_STATE(25)] = 521,
  [SMALL_STATE(26)] = 545,
  [SMALL_STATE(27)] = 569,
  [SMALL_STATE(28)] = 593,
  [SMALL_STATE(29)] = 617,
  [SMALL_STATE(30)] = 641,
  [SMALL_STATE(31)] = 664,
  [SMALL_STATE(32)] = 687,
  [SMALL_STATE(33)] = 699,
  [SMALL_STATE(34)] = 719,
  [SMALL_STATE(35)] = 731,
  [SMALL_STATE(36)] = 751,
  [SMALL_STATE(37)] = 763,
  [SMALL_STATE(38)] = 775,
  [SMALL_STATE(39)] = 787,
  [SMALL_STATE(40)] = 799,
  [SMALL_STATE(41)] = 811,
  [SMALL_STATE(42)] = 823,
  [SMALL_STATE(43)] = 831,
  [SMALL_STATE(44)] = 841,
  [SMALL_STATE(45)] = 851,
  [SMALL_STATE(46)] = 861,
  [SMALL_STATE(47)] = 871,
  [SMALL_STATE(48)] = 885,
  [SMALL_STATE(49)] = 899,
  [SMALL_STATE(50)] = 906,
  [SMALL_STATE(51)] = 915,
  [SMALL_STATE(52)] = 925,
  [SMALL_STATE(53)] = 935,
  [SMALL_STATE(54)] = 945,
  [SMALL_STATE(55)] = 955,
  [SMALL_STATE(56)] = 960,
  [SMALL_STATE(57)] = 967,
  [SMALL_STATE(58)] = 971,
  [SMALL_STATE(59)] = 975,
  [SMALL_STATE(60)] = 979,
  [SMALL_STATE(61)] = 983,
  [SMALL_STATE(62)] = 987,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [7] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1, 0, 3),
  [9] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1, 0, 3),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_term, 1, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_term, 1, 0, 0),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attribute, 3, 0, 11),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attribute, 3, 0, 11),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean_literal, 1, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_say_statement_repeat1, 2, 0, 8),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_say_statement_repeat1, 2, 0, 8), SHIFT_REPEAT(3),
  [32] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_say_statement_repeat1, 2, 0, 8),
  [34] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_say_statement_repeat1, 2, 0, 8), SHIFT_REPEAT(7),
  [37] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_say_statement_repeat1, 2, 0, 8), SHIFT_REPEAT(4),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_say_statement, 2, 0, 5),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [44] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_say_statement, 2, 0, 5),
  [46] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 1, 0, 1),
  [52] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [54] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_section_repeat1, 2, 0, 0),
  [60] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_section_repeat1, 2, 0, 0), SHIFT_REPEAT(56),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_section_repeat1, 2, 0, 0), SHIFT_REPEAT(31),
  [66] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_section_repeat1, 2, 0, 0), SHIFT_REPEAT(24),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section, 2, 0, 1),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(58),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_say_statement_repeat1, 1, 0, 4),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_say_statement_repeat1, 1, 0, 4),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 3, 0, 15),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 3, 0, 15),
  [91] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat1, 2, 0, 14), SHIFT_REPEAT(58),
  [94] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat1, 2, 0, 14), SHIFT_REPEAT(31),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat1, 2, 0, 14),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat1, 2, 0, 14), SHIFT_REPEAT(24),
  [102] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [104] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [106] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [108] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [110] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat2, 2, 0, 18), SHIFT_REPEAT(58),
  [113] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat2, 2, 0, 18), SHIFT_REPEAT(31),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat2, 2, 0, 18),
  [118] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat2, 2, 0, 18), SHIFT_REPEAT(24),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 5, 0, 13),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 5, 0, 13),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_statement, 3, 0, 10),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignment_statement, 3, 0, 10),
  [129] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 4, 0, 6),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 4, 0, 6),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement, 1, 0, 0),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_statement, 1, 0, 0),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 5, 0, 17),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 5, 0, 17),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 4, 0, 13),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 4, 0, 13),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 3, 0, 6),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 3, 0, 6),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_conditional_statement, 6, 0, 21),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_conditional_statement, 6, 0, 21),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat1, 1, 0, 7),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entry, 3, 0, 9),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entry, 3, 0, 9),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_collection, 2, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_collection, 2, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_collection, 3, 0, 19),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_collection, 3, 0, 19),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_section_header, 3, 0, 2),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_section_header, 3, 0, 2),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [179] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(57),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_conditional_statement_repeat2, 1, 0, 12),
  [186] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator, 1, 0, 0),
  [188] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator, 1, 0, 0),
  [190] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [192] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_collection_repeat1, 2, 0, 20),
  [198] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_collection_repeat1, 2, 0, 20), SHIFT_REPEAT(55),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_collection_repeat1, 1, 0, 16),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [217] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
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
