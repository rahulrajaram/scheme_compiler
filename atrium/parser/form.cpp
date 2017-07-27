#include "parser.h"

namespace Atrium {
	bool Parser::is_form() {
		if (is_syntax_definition ()) {
			return true;
		}

		if (is_expression ()) {
			return true;
		}

		return false;
	}
}
