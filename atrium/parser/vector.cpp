#include "parser.h"

namespace Atrium {
	bool Parser::is_vector () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (current_token() != "#") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (current_token() != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		while (is_datum ());

		if (current_token() != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		return true;
	}
}
