#include "parser.h"

namespace Atrium {
	bool Parser::is_constant() {
		if (is_boolean()) {
			print_production(token_vector_index, "boolean");
			return true;
		}

		if (is_number()) {
			print_production(token_vector_index, "number");
			return true;
		}

		if (is_character()) {
			print_production(token_vector_index, "character");
			return true;
		}

		if (is_string()) {
			print_production(token_vector_index, "string");
			return true;
		}

		return false;
	}
}
