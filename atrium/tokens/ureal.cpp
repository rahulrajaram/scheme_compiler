#include <string>

#include "token.h"

namespace Atrium {
	bool Token::is_ureal_2() {
		if (token.find("/") != std::string::npos) {
			std::pair<Token, Token> presumable_uinteger_2_pair = split_around_pivot("/");
			if (
				presumable_uinteger_2_pair.first.is_uinteger_2()
				&& presumable_uinteger_2_pair.second.is_uinteger_2()
			) {
				return true;
			}
		}

		if (is_uinteger_2()) {
			return true;
		}

		return false;
	}

	bool Token::is_ureal_8() {
		if (token.find("/") != std::string::npos) {
			std::pair<Token, Token> presumable_uinteger_8_pair = split_around_pivot("/");
			if (
				presumable_uinteger_8_pair.first.is_uinteger_8()
				&& presumable_uinteger_8_pair.second.is_uinteger_8()
			) {
				return true;
			}
		}

		if (is_uinteger_8()) {
			return true;
		}

		return false;
	}

	bool Token::is_ureal_10() {
		if (token.find("/") != std::string::npos) {
			std::pair<Token, Token> presumable_uinteger_10_pair = split_around_pivot("/");
			if (
				presumable_uinteger_10_pair.first.is_uinteger_10()
				&& presumable_uinteger_10_pair.second.is_uinteger_10()
			) {
				return true;
			}
		}

		if (is_uinteger_10()) {
			return true;
		}

		if (is_decimal_10()) {
			return true;
		}

		return false;
	}

	bool Token::is_ureal_16() {
		if (token.find("/") != std::string::npos) {
			std::pair<Token, Token> presumable_uinteger_16_pair = split_around_pivot("/");
			if (
				presumable_uinteger_16_pair.first.is_uinteger_10()
				&& presumable_uinteger_16_pair.second.is_uinteger_10()
			) {
				return true;
			}
		}

		if (is_uinteger_16()) {
			return true;
		}

		return false;
	}
}
