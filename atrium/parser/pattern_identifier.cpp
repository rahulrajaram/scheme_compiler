#include "parser.h"

namespace Atrium {
	bool Parser::is_pattern_identifier () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_ellipsis()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_identifier()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		print_production(token_vector_index, "pattern_identifier");
		return true;
	}
}
