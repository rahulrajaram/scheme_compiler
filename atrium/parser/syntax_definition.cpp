#include "parser.h"

namespace Atrium {
	bool Parser::is_syntax_definition() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_define_syntax()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_keyword()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_transformer_expression ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
