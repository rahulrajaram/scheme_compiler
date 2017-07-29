#include "parser.h"

namespace Atrium {
	bool Parser::is_template_element () {
		std::size_t token_vector_index_at_entry = token_vector_index;
		if (!is_template ()) {
			return false;
		}

		is_ellipsis ();

		print_production(token_vector_index_at_entry, "template_element");
		return true;
	}
}
