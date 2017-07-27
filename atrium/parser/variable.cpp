#include "parser.h"

namespace Atrium {
	bool Parser::is_variable() {
		if (current_token_type() != "IDENTIFIER" ()) {
			return false;
		}
		token_vector_index ++;

		return true;
	}
}
