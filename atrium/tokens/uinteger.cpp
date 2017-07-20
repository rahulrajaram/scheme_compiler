#include <string>

#include "token.h"

namespace Atrium {
	bool Token::is_uinteger_2() {
		std::pair<Token, Token> splits = split_around_pivot("#", true);

		for (auto c : splits.first.token) {
			if (!is_digit(c)) {
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

	bool Token::is_uinteger_8() {
		std::pair<Token, Token> splits = split_around_pivot("#", true);

		for (auto c : splits.first.token) {
			if (!is_digit(c)) {
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
	
	bool Token::is_uinteger_10() {
		std::pair<Token, Token> splits = split_around_pivot("#", true);

		for (auto c : splits.first.token) {
			if (!is_digit(c)) {
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

	bool Token::is_uinteger_16() {
		std::pair<Token, Token> splits = split_around_pivot("#", true);

		for (auto c : splits.first.token) {
			if (!is_digit(c)) {
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
}
