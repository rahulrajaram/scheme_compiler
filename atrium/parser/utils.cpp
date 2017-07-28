#include "token.h"

namespace Atrium {
	bool Parser::is_terminal (const std::string& terminal) {
		if (current_token () != terminal) {
			return false;
		}
		token_vector_index ++;

		return true;
	}

	bool Parser::is_left_paren () {
		return is_terminal("(");
	}

	bool Parser::is_right_paren () {
		return is_terminal(")");
	}

	bool Parser::is_cond () {
		return is_terminal("cond");
	}

	bool Parser::is_else () {
		return is_terminal("else");
	}

	bool Parser::is_and () {
		return is_terminal("and");
	}

	bool Parser::is_or () {
		return is_terminal("or");
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
	
	bool Parser::is_begin () {
		return is_terminal("begin");
	}
		
	bool Parser::is_do () {
		return is_terminal("do");
	}

	bool Parser::is_delay () {
		return is_terminal("delay");
	}

	bool Parser::is_equal_arrow () {
		return is_terminal("=>");
	}

	bool Parser::is_case () {
		return is_terminal("case");
	}
}
