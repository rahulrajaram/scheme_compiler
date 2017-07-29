#include "parser.h"

namespace Atrium {
	bool Parser::is_datum () {
		if (is_constant()) {
			print_production(token_vector_index, "constant");
			return true;
		}

		if (is_symbol()) {
			print_production(token_vector_index, "symbol");
			return true;
		}

		if (is_list ()) {
			print_production(token_vector_index, "list");
			return true;
		}

		while (is_vector ()) {
			print_production(token_vector_index, "vector");
			return true;
		};

		return false;
	}
}
