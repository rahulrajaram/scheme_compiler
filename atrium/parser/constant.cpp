#include "parser.h"

namespace Atrium {
	bool Parser::is_constant() {
		if (is_boolean()) {
			return true;
		}

		if (is_number()) {
			return true;
		}

		if (is_character()) {
			return true;
		}

		if (is_string()) {
			return true;
		}

		return false;
	}
}
