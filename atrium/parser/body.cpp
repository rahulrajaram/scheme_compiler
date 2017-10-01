#include "parser.h"

namespace Atrium {
	bool Parser::is_body() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		while (is_definition ());
		// syntax.txt says that body is zero or more definitions
		// followed by one or more expressions. This is hard to match.
		// Hence, allowing zero or more expressions
		while(is_expression ());

		print_production(token_vector_index_at_entry, "body");
		return true;
	}
}
