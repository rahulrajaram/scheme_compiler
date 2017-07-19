#include "token.h"

namespace Atrium {
	bool Token::is_real_2() {
		if (starts_with_prefix("+") || starts_with_prefix("-")) {
			Token possibly_ureal_2 = Token(token.substr(1));

			if (possibly_ureal_2.is_ureal_2()) {
				return true;
			}
		}

		return false;
	}

	bool Token::is_real_8() {
		if (starts_with_prefix("+") || starts_with_prefix("-")) {
			Token possibly_ureal_8 = Token(token.substr(1));

			if (possibly_ureal_8.is_ureal_8()) {
				return true;
			}
		}

		return false;
	}

	bool Token::is_real_10() {
		if (starts_with_prefix("+") || starts_with_prefix("-")) {
			Token possibly_ureal_10 = Token(token.substr(1));

			if (possibly_ureal_10.is_ureal_10()) {
				return true;
			}
		}

		return false;
	}

	bool Token::is_real_16() {
		if (starts_with_prefix("+") || starts_with_prefix("-")) {
			Token possibly_ureal_16 = Token(token.substr(1));

			if (possibly_ureal_16.is_ureal_16()) {
				return true;
			}
		}

		return false;
	}
}
