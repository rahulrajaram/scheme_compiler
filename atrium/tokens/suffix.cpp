#include "token.h"

namespace Atrium {
	bool Token::is_suffix() {
		if (token.empty()) {
			return true;
		}

		if (is_exponent()) {
			return true;
		}

		return false;
	}
}
