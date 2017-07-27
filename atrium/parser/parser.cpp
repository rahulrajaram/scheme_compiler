#include "parser.h"

namespace Atrium {
	bool Parser::parse () {
		while (token_vector_index < token_vector.size()) {
			if (! is_form ()) {
				return false;
			}
		}

		return false;
	}

	std::string Parser::current_token() {
		return token_vector[token_vector_index].token;
	}

	std::string Parser::current_token_type () {
		return token_vector[token_vector_index].type;
	}
}
