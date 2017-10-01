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

		// symbols are essentially identifiers
		if (is_identifier()) {
			print_production(token_vector_index, "identifier");
			return true;
		}

		if (is_list ()) {
			print_production(token_vector_index, "list");
			return true;
		}

		if (is_vector ()) {
			print_production(token_vector_index, "vector");
			return true;
		};

		// syntax.txt does not list this production rule, but I
		// this is meaningful. Consider:
		//
		// 		'("yolo" (if (> 1 2) #t #f))
		if (is_expression ()) {
			return true;
		};

		return false;
	}
}
