#include "parser.h"

namespace Atrium {
	bool Parser::is_pattern_identifier () {
		if (current_token_type() == "IDENTIFIER") {
			if (current_token() != "...") {
				token_vector_index ++;
				return true;
			}
		}

		return false;
	}
}
