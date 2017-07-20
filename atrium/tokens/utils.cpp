#include "token.h"

namespace Atrium {
	bool Token::is_all_digits() {
		for (auto c : token) {
			if (!is_digit(c)) {
				return false;
			}
		}

		return true;
	}

	bool Token::contains_only(char ch) {
		for (auto c : token) {
			if (c != ch) {
				return false;
			}
		}

		return true;
	}

	bool Token::starts_with_prefix(const std::string& prefix) {
		if (prefix.length() > token.length()) {
			return false;
		}

		return (token.substr(0, prefix.length()) == prefix);
	}

	bool Token::ends_with_suffix(const std::string& suffix) {
		if (suffix.length() > token.length()) {
			return false;
		}

		return (token.substr(token.length() - suffix.length()) == suffix);
	}

	std::pair<Token, Token>
	Token::split_around_pivot(
		const std::string& pivot,
		bool include_split_point
	) {
		std::size_t split_location = token.find(pivot);

		// Return original token as the only string
		if (split_location == std::string::npos) {
			return std::make_pair(Token(token), Token(""));
		}

		if ((split_location + pivot.length()) == token.length()) {
			return std::make_pair(Token(token), Token(""));
		}

		Token first_part_1 = Token(token.substr(0, split_location));
		Token second_part_1("");

		if (include_split_point) {
			second_part_1 = Token(token.substr(split_location + 1)); 
		} else {
			second_part_1 = Token(token.substr(split_location + 1)); 
		}

		return std::make_pair(first_part_1, second_part_1);
	}

	std::pair<Token, Token>
	Token::split_at_discontinuity(
		const char continuity_character
	) {
		std::size_t split_location = 0;

		while (split_location < token.length()) {
			if (token[split_location] != continuity_character) {
				break;
			}
			split_location ++;
		}

		Token first_part_1 = Token(token.substr(0, split_location));
		Token second_part_1 = Token(token.substr(split_location)); 

		return std::make_pair(first_part_1, second_part_1);
	}
}
