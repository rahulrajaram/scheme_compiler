#include "parser.h"

namespace Atrium {
	bool Parser::is_abbreviation () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (current_token_type() != "ABBREVIATION_PREFIX") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (! is_datum()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
