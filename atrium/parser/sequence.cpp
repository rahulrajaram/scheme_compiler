#include "parser.h"

namespace Atrium {
	bool Parser::is_sequence() {
		if (!is_expression()) {
			return false;
		}

		while (is_expression());

		return true;
	}
}
