#include "parser.h"

namespace Atrium {
	bool Parser::is_test() {
		if (!is_expression()) {
			return false;
		}

		print_production(token_vector_index, "test");
		return true;
	}
}
