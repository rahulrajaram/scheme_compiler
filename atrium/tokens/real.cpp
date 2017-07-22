#include "token.h"

namespace Atrium {
	bool Token::is_real(bool (Token::*is_ureal_method)()) {
		if (starts_with_prefix("+") || starts_with_prefix("-")) {
			Token presumable_ureal_r_pair = Token(token.substr(1));

			if (((&presumable_ureal_r_pair)->*is_ureal_method)()) {
				return true;
			}

			return false;
		}

		return (this->*is_ureal_method)();
	}

	bool Token::is_real_2() {
		return is_real(&Token::is_ureal_2);
	}

	bool Token::is_real_8() {
		return is_real(&Token::is_ureal_8);
	}

	bool Token::is_real_10() {
		return is_real(&Token::is_ureal_10);
	}

	bool Token::is_real_16() {
		return is_real(&Token::is_ureal_16);
	}
}
