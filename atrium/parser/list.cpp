#include "parser.h"

namespace Atrium {
	bool Parser::is_list () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_abbreviation ()) {
			print_production(token_vector_index_at_entry, "list::abbreviation");
			return true;
		}

		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (is_datum()) {
			while (is_datum());

			if (is_right_paren()) {
				print_production(token_vector_index_at_entry, "list::datum");
				return true;
			}

			if (!is_period()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (!is_datum()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
		}
		if (!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		print_production(token_vector_index_at_entry, "list");
		return true;
	}
}
