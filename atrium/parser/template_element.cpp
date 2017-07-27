#include "parser.h"

namespace Atrium {
	bool Parser::is_template_element () {
		if (! is_template ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		is_ellipsis ();

		return true;
	}
}
