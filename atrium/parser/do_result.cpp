#include "parser.h"

namespace Atrium {
	// <do result> --> <sequence> | <empty>
	bool Parser::is_do_result() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (!is_sequence()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
