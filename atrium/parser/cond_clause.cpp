#include "parser.h"

namespace Atrium {
	bool Parser::is_cond_clause() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (is_sequence()) {
		} else if (is_test()) {
			if (is_equal_arrow()) {
				if (!is_expression()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			}
		} else {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
