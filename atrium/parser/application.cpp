#include "parser.h"

namespace Atrium {
	bool Parser::is_application() {
		std::size_t token_vector_index_at_entry = token_vector_index;
		
		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (! is_expression ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		while ( is_expression ());

		if (!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		print_production(token_vector_index_at_entry, "application");
		return true;
	}
}
