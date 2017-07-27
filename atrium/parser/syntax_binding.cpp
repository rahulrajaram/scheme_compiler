#include "parser.h"

namespace Atrium {
	bool Parser::is_syntax_binding() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (current_token () != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (! is_keyword()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (! is_transformer_expression ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (current_token () != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		return true;
	}
}
