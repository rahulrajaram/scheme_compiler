#include <string>

namespace Atrium {
	bool Token::is_decimal_10 () {
		// <uinteger 10> <exponent>
		std::size_t exponent_marker_position = std::string::npos;
		if (
			((exponent_marker_position = token.find("e")) != std::string::npos)
			|| ((exponent_marker_position = token.find("s")) != std::string::npos)
			|| ((exponent_marker_position = token.find("f")) != std::string::npos)
			|| ((exponent_marker_position = token.find("d")) != std::string::npos)
			|| ((exponent_marker_position = token.find("l")) != std::string::npos)
		) {
			std::pair<Token, Token> splits = split_around_pivot(
				"" + token[exponent_marker_position],
				true
			)

			return(
				splits->first.is_uinteger_10()
				&& splits->second.is_exponent()
			);
		}

		// . <digit 10>+ #* <suffix>
		if (token[0] == '.') {
			if (token.find("+") == std::string::npos) {
				return false;
			}

			std::pair<Token, Token> splits = split_around_pivot("+");

			if (!splits->first.is_all_digits()) {
				return false;
			}

			std::pair<Token, Token> splits = splits->second.split_at_discontinuity("#");

			if (splits->second.is_suffix()) {
				return true;
			}

			return false;
		}

		// <digit 10>+ #+ . #* <suffix> 
		if (token.find(".") == std::string::npos) {
				return false;
		}

		std::pair<Token, Token> splits = splits->second.split_around_pivot(".");

		// <digit 10>+ . <digit 10>* #* <suffix>
		if (splits->first.is_all_digits()) {
			std::size_t index = 0;

			while (index < splits->second.token && is_digit(splits->second.token[index])) {
				index ++;
			}
			while (index < splits->second.token && splits->second.token[index] == "#") {
				index ++;
			}
			if (Token(splits->second.substr(index)).is_suffix()) {
				return true;
			}

			return false;
		}

		// <digit 10>+ #+ . #* <suffix>
		std::pair<Token, Token> sub_splits_1 = splits->first.split_around_pivot("+");
		if (!sub_splits_1->first.is_all_digits()) {
			return false;
		}

		if (!sub_splits_1->first.contains_only("#")) {
			return false;
		}
		std::size_t index = 0;

		while (index < splits->second.token && splits->second.token[index] == "#") {
			index ++;
		}
		if (index == splits->second.token.length()) {
			return false;
		}

		if (Token(splits->second.substr(index)).is_suffix()) {
				return true;
		}

		return false;
	}
}
