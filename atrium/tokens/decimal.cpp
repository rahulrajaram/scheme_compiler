#include <string>

#include "token.h"

namespace Atrium {
	bool Token::is_decimal_10 () {
		// <uinteger 10> <exponent>
		std::size_t emp = exponent_marker_position();
		if (
			(token.find(".") == std::string::npos)
			&& emp != std::string::npos
		) {
			std::pair<Token, Token> splits = split_around_pivot(
				token.substr(emp, 1),
				true
			);

			return(
				splits.first.is_uinteger_10()
				&& splits.second.is_exponent()
			);
		}

		// . <digit 10>+ #* <suffix>
		if (token[0] == '.') {
			std::string decimal_part = token.substr(1);
			std::size_t emp = Token(decimal_part).exponent_marker_position();

			// suffix is exponent
			if (emp != std::string::npos) {
				std::pair<Token, Token> splits = Token(decimal_part).split_around_pivot(
					decimal_part.substr(emp, 1),
					true
				);

				if (!splits.second.is_suffix()) {
					return false;
				}

				std::pair<Token, Token> sub_splits = Token(splits.first).split_around_pivot(
					"#",
					true
				);

				if (!sub_splits.first.is_all_digits()) {
					return false;
				}

				if (!sub_splits.second.contains_only('#')) {
					return false;
				}
			} else {
			// suffix is ""
				std::pair<Token, Token> sub_splits = Token(decimal_part).split_around_pivot(
					"#",
					true
				);

				if (!(sub_splits.first.is_all_digits())) {
					return false;
				}

				if (!sub_splits.second.contains_only('#')) {
					return false;
				}
			}

			return true;
		}

		// <digit 10>+ #+ . #* <suffix> 
		if (token.find(".") == std::string::npos) {
				return false;
		}

		std::pair<Token, Token> splits = split_around_pivot(".");

		// <digit 10>+ . <digit 10>* #* <suffix>
		if (splits.first.is_all_digits()) {
			std::size_t index = 0;

			while (index < splits.second.token.length() && is_digit(splits.second.token[index])) {
				index ++;
			}
			while (index < splits.second.token.length() && splits.second.token[index] == '#') {
				index ++;
			}
			if (Token(splits.second.token.substr(index)).is_suffix()) {
				return true;
			}

			return false;
		}

		// <digit 10>+ #+ . #* <suffix>
		std::pair<Token, Token> sub_splits_1 = splits.first.split_around_pivot("#");
		if (!sub_splits_1.first.is_all_digits()) {
			return false;
		}

		if (!sub_splits_1.second.contains_only('#')) {
			return false;
		}
		std::size_t index = 0;

		while (index < splits.second.token.length() && splits.second.token[index] == '#') {
			index ++;
		}
		if (index == splits.second.token.length()) {
			return true;
		}

		if (Token(splits.second.token.substr(index)).is_suffix()) {
			return true;
		}

		return false;
	}
}
