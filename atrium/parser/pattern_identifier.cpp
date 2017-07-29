#include "parser.h"

namespace Atrium {
	bool Parser::is_pattern_identifier () {
		if (!is_identifier()) {
			return false;
		}

		if (!is_ellipsis()) {
			print_production(token_vector_index, "pattern_identifier");
			return true;
		}

		return false;
	}
}
