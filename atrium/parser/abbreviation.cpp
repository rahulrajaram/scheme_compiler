#include "parser.h"

namespace Atrium {
	bool Parser::is_abbreviation () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (!is_abbreviation_prefix()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (! is_datum()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
