#include "parser.h"

namespace Atrium {
	// <binding spec> --> (<variable> <expression>)
	bool Parser::is_binding_spec() {
		std::size_t token_vector_index_at_entry = token_vector_index;
		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_variable()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_expression()) {
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
