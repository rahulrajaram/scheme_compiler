#include "parser.h"

namespace Atrium {
	bool Parser::is_terminal (const std::string& terminal) {
		if (token_vector_index >= token_vector.size()) {
			return false;
		}

		if ((current_token()) != terminal) {
			return false;
		}
		token_vector_index ++;

		return true;
	}

	bool Parser::is_terminal_type (const std::string& terminal_type) {
		if (token_vector_index >= token_vector.size()) {
			return false;
		}

		if ((current_token_type()) != terminal_type) {
			return false;
		}
		token_vector_index ++;

		return true;
	}

	bool Parser::is_abbreviation_prefix () {
		return is_terminal_type("ABBREVIATION_PREFIX");
	}
	bool Parser::is_and () {
		return is_terminal("and");
	}
	bool Parser::is_begin () {
		return is_terminal("begin");
	}
	bool Parser::is_boolean () {
		return is_terminal_type("BOOLEAN");
	}
	bool Parser::is_case () {
		return is_terminal("case");
	}
	bool Parser::is_character () {
		return is_terminal_type("CHARACTER");
	}
	bool Parser::is_cond () {
		return is_terminal("cond");
	}		
	bool Parser::is_define() {
		return is_terminal("define");
	}
	bool Parser::is_define_syntax () {
		return is_terminal("define-syntax");
	}
	bool Parser::is_delay () {
		return is_terminal("delay");
	}
	bool Parser::is_do () {
		return is_terminal("do");
	}
	bool Parser::is_ellipsis () {
		return is_terminal("...");
	}
	bool Parser::is_else () {
		return is_terminal("else");
	}
	bool Parser::is_equal_arrow () {
		return is_terminal("=>");
	}
	bool Parser::is_hash () {
		return is_terminal("#");
	}
	bool Parser::is_identifier () {
		return is_terminal_type("IDENTIFIER");
	}
	bool Parser::is_if () {
		return is_terminal("if");
	}
	bool Parser::is_lambda () {
		return is_terminal("lambda");
	}
	bool Parser::is_left_paren () {
		return is_terminal("(");
	}
	bool Parser::is_let () {
		return is_terminal("let");
	}
	bool Parser::is_let_star () {
		return is_terminal("let*");
	}
	bool Parser::is_letrec () {
		return is_terminal("letrec");
	}
	bool Parser::is_let_syntax () {
		return is_terminal("let-syntax");
	}
	bool Parser::is_letrec_syntax () {
		return is_terminal("letrec-syntax");
	}
	bool Parser::is_number () {
		return is_terminal_type("NUMBER");
	}
	bool Parser::is_or () {
		return is_terminal("or");
	}
	bool Parser::is_period () {
		return is_terminal("#");
	}
	bool Parser::is_quote () {
		return is_terminal("quote");
	}
	bool Parser::is_right_paren () {
		return is_terminal(")");
	}
	bool Parser::is_set_bang () {
		return is_terminal("set!");
	}
	bool Parser::is_single_quote () {
		return is_terminal("'");
	}
	bool Parser::is_string () {
		return is_terminal_type("STRING");
	}
	bool Parser::is_symbol () {
		return is_terminal_type("SYMBOL");
	}
	bool Parser::is_syntax_rules () {
		return is_terminal("syntax-rules");
	}
}
