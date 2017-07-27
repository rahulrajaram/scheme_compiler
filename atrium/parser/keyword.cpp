#include "parser.h"

namespace Atrium {
	bool Parser::is_keyword() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (! is_keyword()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
