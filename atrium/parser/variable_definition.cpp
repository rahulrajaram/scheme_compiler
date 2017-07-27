#include "parser.h"

namespace Atrium {
	bool Parser::is_variable_definition () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (current_token () != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (current_token () != "define") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (current_token () == "(") {
			token_vector_index ++;

			if (! is_variable()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			while (is_variable());

			if (current_token () == ".") {
				token_vector_index ++;

				if (! is_variable()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
				token_vector_index ++;
			}

			if (current_token () !== ")") {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
			token_vector_index ++;

			if (! is_body()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (current_token () != ")") {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
			token_vector_index ++;
		}

		return true;
	}
}
