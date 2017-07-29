#include "parser.h"

namespace Atrium {
	bool Parser::is_pattern_identifier () {
		if (!is_identifier()) {
			return false;
		}

		if (!is_ellipsis()) {
			return true;
		}

		return false;
	}
}
