#include "parser.h"

namespace Atrium {
	bool Parser::is_template () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_pattern_identifier ()) {
			return true;
		}

		if (is_template_datum ()) {
			return true;
		}

		if (is_left_paren()) {
			if (is_template_element()) {
				while (is_template_element());

				if (is_right_paren()) {
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
		} else if (is_hash()) {
			while (is_template_element());
		} else {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
