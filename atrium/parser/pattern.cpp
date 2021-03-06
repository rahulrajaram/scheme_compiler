#include "parser.h"

namespace Atrium {
	bool Parser::is_pattern () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_pattern_identifier ()) {
			print_production(token_vector_index_at_entry, "pattern::pattern_identifier");
			return true;
		}

		if (is_constant ()) {
			print_production(token_vector_index_at_entry, "pattern::constant");
			return true;
		}

		/* 	| (<pattern>*)
     		| (<pattern>+ . <pattern>)
     		| (<pattern>+ <ellipsis>)
		*/
		if (is_left_paren()) {
			if (is_pattern()) {
				while (is_pattern());

				if (is_period()) {
					if (!is_pattern()) {
						token_vector_index = token_vector_index_at_entry;
						return false;
					}
				}

				if (is_ellipsis());
			}
		} else if (is_hash()) {
			// | #(<pattern>*)
			// | #(<pattern>* <pattern> <ellipsis>)
			if (!is_left_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (is_pattern()) {
				while (is_pattern());

				if (is_right_paren()) {
					print_production(token_vector_index_at_entry, "pattern::hash pattern");
					return true;
				}
				if (!is_ellipsis()) {
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

		print_production(token_vector_index_at_entry, "pattern");
		return true;
	}
}
