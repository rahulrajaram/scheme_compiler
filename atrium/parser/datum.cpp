#include "parser.h"

namespace Atrium {
	bool Parser::is_datum () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_constant()) {
			return true;
		}

		if (is_symbol()) {
			return true;
		}

		if (is_list ()) {
			return true;
		}

		while (is_vector ()) {
			return true;
		};

		return false;
	}
}
