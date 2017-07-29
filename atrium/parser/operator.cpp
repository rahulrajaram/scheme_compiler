#include "parser.h"

namespace Atrium {
	bool Parser::is_operator() {
		if (!is_expression()) {
			return false;
		}

		print_production(token_vector_index, "operator");
		return true;
	}
}
