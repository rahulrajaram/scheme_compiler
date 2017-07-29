#include "parser.h"

namespace Atrium {
	bool Parser::is_formals() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_variable ()) {
			return true;
		}

		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (is_variable ()) {
			while(is_variable());

			if (is_right_paren()) {
				return true;
			}

			if (!is_period()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (!is_variable ()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
		}

		if (!is_right_paren	()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
