#include "token.h"

namespace Atrium {
	bool Token::is_real_2() {
		if (starts_with_prefix("+") || starts_with_prefix("-")) {
			if (Token(token.substr(1)).is_ureal_2()) {
				return true;
			}

			return false;
		}

		return is_ureal_2();
	}

	bool Token::is_real_8() {
		if (starts_with_prefix("+") || starts_with_prefix("-")) {
			if (Token(token.substr(1)).is_ureal_8()) {
				return true;
			}

			return false;
		}

		return is_ureal_16();
	}

	bool Token::is_real_10() {
		if (starts_with_prefix("+") || starts_with_prefix("-")) {
			if (Token(token.substr(1)).is_ureal_10()) {
				return true;
			}

			return false;
		}

		return is_ureal_10();
	}

	bool Token::is_real_16() {
		if (starts_with_prefix("+") || starts_with_prefix("-")) {
			if (Token(token.substr(1)).is_ureal_16()) {
				return true;
			}

			return false;
		}

		return is_ureal_16();
	}
}
