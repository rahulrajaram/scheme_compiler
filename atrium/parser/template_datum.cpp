#include "parser.h"

namespace Atrium {
	bool Parser::is_template_datum () {
		if (!is_constant()) {
			return false;
		}

		print_production(token_vector_index, "template_datum");
		return true;
	}
}
