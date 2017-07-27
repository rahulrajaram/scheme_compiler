#include "parser.h"

namespace Atrium {
	bool Parser::is_pattern () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_pattern_identifier ()) {
			return true;
		}

		if (is_constant ()) {
			return true;
		}

		if (current_token () == "(") {
			token_vector_index ++;

			if (is_template_element()) {
				while (is_template_element());

				if (current_token == ".") {
					token_vector_index ++;

					if (!is_template_element()) {
						token_vector_index = token_vector_index_at_entry;
						return false;
					}

					return true;
				}

				if (current_token () != ")") {
						token_vector_index = token_vector_index_at_entry;
						return false;
				}
				token_vector_index ++;
			}

			return true;
		}

		if (current_token() != "#") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (current_token() != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		while(is_template_element());

		if (current_token() != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
