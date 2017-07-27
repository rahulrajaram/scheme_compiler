#include "parser.h"

namespace Atrium {
	bool Parser::is_constant() {
		if (current_token_type() == "BOOLEAN") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "NUMBER") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "CHARACTER") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "STRING") {
			token_vector_index ++;
			return true;
		}

		return false;
	}
}
