#include "parser.h"

namespace Atrium {
	bool Parser::is_variable() {
		if (is_identifier()) {
			print_production(token_vector_index, "variable");
			return true;
		}

		// The token classifier is unable to distinguish between
		// alpha-numeric hex nubmbers and identifiers.
		// However, at this point in the execution of the program,
		// we would like to consider the tokens classified as
		// hex numbers as identifiers
		if (token_vector_index < token_vector.size() && token_vector[token_vector_index].is_identifier()) {
			token_vector_index ++;

			print_production(token_vector_index, "variable");
			return true;
		}

		return false;
	}
}
