#include "parser.h"

namespace Atrium {
	bool Parser::is_list () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_abbreviation ()) {
			return true;
		}

		if (current_token() != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		token_vector_index ++; 

		if (is_datum()) {
			while (is_datum());

			if (current_token() == ".") {
				token_vector_index ++;

				if (!is_datum()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			}
		}
		if (current_token() != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		return true;
	}
}
