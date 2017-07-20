#include "token.h"

namespace Atrium {
	bool Token::is_imag_2() {
		if (token == "i") {
			return true;
		}

		if (token[token.size() - 1] == 'i') {
			if (is_ureal_2()) {
				return true;
			}
		}

		return false;
	}

	bool Token::is_imag_8() {
		if (token == "i") {
			return true;
		}

		if (token[token.size() - 1] == 'i') {
			if (is_ureal_8()) {
				return true;
			}
		}

		return false;
	}

	bool Token::is_imag_10() {
		if (token == "i") {
			return true;
		}

		if (token[token.size() - 1] == 'i') {
			if (is_ureal_10()) {
				return true;
			}
		}

		return false;
	}

	bool Token::is_imag_16() {
		if (token == "i") {
			return true;
		}

		if (token[token.size() - 1] == 'i') {
			if (is_ureal_16()) {
				return true;
			}
		}

		return false;
	}
}
