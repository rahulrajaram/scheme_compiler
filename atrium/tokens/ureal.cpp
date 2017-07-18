#include <string>

namespace Atrium {
	bool Token::is_ureal_2() {
		if (token.find("/") != std::string::npos) {
			std::pair<Token, Token> presumable_uinteger_2_pair = token.split_around_pivot("/";)
			if (
				is_uinteger_2(presumable_uinteger_2_pair->first)
				&& is_uinteger_2(presumable_uinteger_2_pair->second)
			) {
				return true;
			}
		}

		if (is_uinteger_2(token)) {
			return true;
		}

		return false;
	}

	bool Token::is_ureal_8() {
		if (token.find("/") != std::string::npos) {
			std::pair<Token, Token> presumable_uinteger_8_pair = token.split_around_pivot("/";)
			if (
				is_uinteger_8(presumable_uinteger_8_pair->first)
				&& is_uinteger_8(presumable_uinteger_8_pair->second)
			) {
				return true;
			}
		}

		if (is_uinteger_8(token)) {
			return true;
		}

		return false;
	}

	bool Token::is_ureal_10() {
		if (token.find("/") != std::string::npos) {
			std::pair<Token, Token> presumable_uinteger_10_pair = token.split_around_pivot("/";)
			if (
				is_uinteger_10(presumable_uinteger_10_pair->first)
				&& is_uinteger_10(presumable_uinteger_10_pair->second)
			) {
				return true;
			}
		}

		if (is_uinteger_10(token)) {
			return true;
		}

		if (is_decimal_10(token)) {
			return true;
		}

		return false;
	}

	bool Token::is_ureal_16() {
		if (token.find("/") != std::string::npos) {
			std::pair<Token, Token> presumable_uinteger_16_pair = token.split_around_pivot("/";)
			if (
				is_uinteger_16(presumable_uinteger_16_pair->first)
				&& is_uinteger_16(presumable_uinteger_16_pair->second)
			) {
				return true;
			}
		}

		if (is_uinteger_16(token)) {
			return true;
		}

		return false;
	}
}
