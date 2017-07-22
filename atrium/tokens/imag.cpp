#include "token.h"

namespace Atrium {
	bool Token::is_imag(bool (Token::*is_ureal_method)()) {
		if (token == "i") {
			return true;
		}

		if (token[token.size() - 1] == 'i') {
			Token possibly_ureal = Token(token.substr(0, token.length() - 1));
			if ((&possibly_ureal->*is_ureal_method)()) {
				return true;
			}
		}

		return false;
	}

	bool Token::is_imag_2() {
		return is_imag(&Token::is_ureal_2);
	}

	bool Token::is_imag_8() {
		return is_imag(&Token::is_ureal_8);
	}

	bool Token::is_imag_10() {
		return is_imag(&Token::is_ureal_10);
	}

	bool Token::is_imag_16() {
		return is_imag(&Token::is_ureal_16);
	}
}
