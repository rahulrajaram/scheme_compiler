#include "parser.h"

namespace Atrium {
	bool Parser::is_keyword() {
		if (!is_syntactic_keyword()) {
			return false;
		}

		print_production(token_vector_index, "iteration_spec");
		return true;
	}
}
