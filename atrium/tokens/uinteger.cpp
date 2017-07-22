#include <string>

#include "token.h"

namespace Atrium {
	bool Token::is_uinteger(bool (Token::*is_digit_method)(char)) {
		std::pair<Token, Token> splits = split_around_pivot("#", true);

		if (!splits.first.token.length()) {
			return false;
		}

		for (auto c : splits.first.token) {
			if (! (this->*is_digit_method)(c)) {
				return false;
			}
		}

		for (auto c : splits.second.token) {
			if (c != '#') {
				return false;
			}
		}

		return true;
	}

	bool Token::is_uinteger_2() {
		return is_uinteger(&Token::is_digit_2);
	}

	bool Token::is_uinteger_8() {
		return is_uinteger(&Token::is_digit_8);
	}
	
	bool Token::is_uinteger_10() {
		return is_uinteger(&Token::is_digit_10);
	}

	bool Token::is_uinteger_16() {
		return is_uinteger(&Token::is_digit_16);
	}
}
