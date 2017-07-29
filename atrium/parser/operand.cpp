#include "parser.h"

namespace Atrium {
	bool Parser::is_operand() {
		if (!is_expression()) {
			return false;
		}

		print_production(token_vector_index, "operand");
		return true;
	}
}
