#include "parser.h"

namespace Atrium {
	bool Parser::is_sequence() {
		std::size_t token_vector_index_at_entry = token_vector_index;
		if (!is_expression()) {
			return false;
		}

		while (is_expression());

		print_production(token_vector_index_at_entry, "sequence");
		return true;
	}
}
