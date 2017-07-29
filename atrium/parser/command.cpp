#include "parser.h"

namespace Atrium {
	// <do result> --> <sequence> | <empty>
	bool Parser::is_command() {
		std::size_t token_vector_index_at_entry = token_vector_index;
		if (!is_expression()) {
			return false;
		}

		print_production(token_vector_index_at_entry, "command");
		return true;
	}
}
