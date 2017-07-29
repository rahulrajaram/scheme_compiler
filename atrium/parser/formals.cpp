#include "parser.h"

namespace Atrium {
	bool Parser::is_formals() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_variable ()) {
			print_production(token_vector_index_at_entry, "formals::expression");
			return true;
		}

		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (is_variable ()) {
			while(is_variable());

			if (is_right_paren()) {
			print_production(token_vector_index_at_entry, "formals::expression");
				return true;
			}

			if (!is_period()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (!is_variable ()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
		}

		if (!is_right_paren	()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		print_production(token_vector_index_at_entry, "formals");
		return true;
	}
}
