#include "parser.h"

namespace Atrium {
	bool Parser::is_body() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		std::size_t token_vector_index_at_start_of_loop = token_vector_index;
		while (is_definition ()) {
			token_vector_index_at_start_of_loop = token_vector_index;
		}

		if (! is_expression ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		while (is_expression ());

		return true;
	}
}
