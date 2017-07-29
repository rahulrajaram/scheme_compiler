#include "parser.h"

namespace Atrium {
	bool Parser::is_variable() {
		if (!is_identifier()) {
			return false;
		}

		print_production(token_vector_index, "variable");
		return true;
	}
}
