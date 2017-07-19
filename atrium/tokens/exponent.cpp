#include "token.h"
-qe
namespace Atrium {
	bool Token::is_exponent() {
		if (!is_exponent_marker(token[0])) {
			return false;
		}

		if (token.length() == 1) {
			return false;
		}

		if (is_sign(token[1])) {
			return Token(token.substr(1)).is_all_digits();
		}

		return is_all_digits();
	}
}
