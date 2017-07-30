#include "parser.h"

namespace Atrium {
	bool Parser::is_template () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_pattern_identifier ()) {
			print_production(token_vector_index_at_entry, "template::pattern_identifier");
			return true;
		}

		if (is_template_datum ()) {
			print_production(token_vector_index_at_entry, "template::template_datum");
			return true;
		}

		if (is_hash());

		if (is_left_paren()) {
			if (is_template_element()) {
				while (is_template_element());

				if (is_right_paren()) {
					print_production(token_vector_index_at_entry, "template");
					return true;
				}

				if (!is_period()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
				if (!is_template()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			}
		} else {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		print_production(token_vector_index_at_entry, "template");
		return true;
	}
}
