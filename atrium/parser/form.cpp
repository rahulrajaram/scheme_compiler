#include "parser.h"

namespace Atrium {
	bool Parser::is_form() {
		if (is_syntax_definition ()) {
			print_production(token_vector_index, "form::syntax_definition");
			return true;
		}

		if (is_expression ()) {
			print_production(token_vector_index, "form::expression");
			return true;
		}

		return false;
	}
}
