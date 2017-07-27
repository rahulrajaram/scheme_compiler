#include "parser.h"

namespace Atrium {
	bool Parser::is_ellipsis () {
		if (current_token() == "...") {
			token_vector_index ++;
			return true;
		}

		return false;
	}
}
