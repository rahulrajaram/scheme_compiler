#include "parser.h"

namespace Atrium {
	bool Parser::is_formals() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_variable ()) {
			token_vector_index ++; 
			return true;
		}

		if (current_token() != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++; 

		if (! is_expression ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (is_variable ()) {
			token_vector_index ++; 
			return true;
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
