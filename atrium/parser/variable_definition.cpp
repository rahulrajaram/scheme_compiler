#include "parser.h"

namespace Atrium {
	bool Parser::is_variable_definition () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_define()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (is_left_paren()) {
			if (!is_variable()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			while (is_variable());

			if (is_period()) {
				if (!is_variable()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			}
			
			if(!is_right_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (!is_body()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
		} else if (is_variable()) {
			if (!is_expression()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
		} else {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if(!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
