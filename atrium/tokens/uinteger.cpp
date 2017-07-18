#include <string>

namespace Atrium {
	bool Token::is_uinteger_2() {
		std::pair<Token, Token> splits = token.split_around_pivot("#", true);

		for (auto c : splits->first) {
			if (!is_digit(c)) {
				return false;
			}
		}

		for (auto c : splits->seconds) {
			if (c != '#') {
				return false;
			}
		}

		return true;
	}

	bool Token::is_uinteger_8() {
		std::pair<Token, Token> splits = token.split_around_pivot("#", true);

		for (auto c : splits->first) {
			if (!is_digit(c)) {
				return false;
			}
		}

		for (auto c : splits->seconds) {
			if (c != '#') {
				return false;
			}
		}

		return true;
	}
	
	bool Token::is_uinteger_10() {
		std::pair<Token, Token> splits = token.split_around_pivot("#", true);

		for (auto c : splits->first) {
			if (!is_digit(c)) {
				return false;
			}
		}

		for (auto c : splits->seconds) {
			if (c != '#') {
				return false;
			}
		}

		return true;
	}

	bool Token::is_uinteger_16() {
		std::pair<Token, Token> splits = token.split_around_pivot("#", true);

		for (auto c : splits->first) {
			if (!is_digit(c)) {
				return false;
			}
		}

		for (auto c : splits->seconds) {
			if (c != '#') {
				return false;
			}
		}

		return true;
	}
}
