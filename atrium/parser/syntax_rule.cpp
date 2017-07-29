#include "parser.h"

namespace Atrium {
	// <syntax rule> --> (<pattern> <template>)
	bool Parser::is_syntax_rule() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_pattern()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_template()) {
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
