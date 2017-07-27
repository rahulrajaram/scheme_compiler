#include "parser.h"

namespace Atrium {
	bool Parser::is_application() {
		std::size_t token_vector_index_at_entry = token_vector_index;
		
		if (current_token() != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++; 

		if (! is_expression ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		while ( is_expression ());

		if (current_token() != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++; 

		return true;
	}
}
