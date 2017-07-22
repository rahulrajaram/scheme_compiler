#include <string>

#include "token.h"

namespace Atrium {
	bool Token::is_ureal(bool (Token::*is_uinteger_method)()) {
		if (token.find("/") != std::string::npos) {
			std::pair<Token, Token> presumable_uinteger_r_pair = split_around_pivot("/");
			return (
				((&presumable_uinteger_r_pair.first)->*is_uinteger_method)()
				&& ((&presumable_uinteger_r_pair.second)->*is_uinteger_method)()
			);
		}

		return (this->*is_uinteger_method)();
	}

	bool Token::is_ureal_2() {
		return is_ureal(&Token::is_uinteger_2);
	}

	bool Token::is_ureal_8() {
		return is_ureal(&Token::is_uinteger_8);
	}

	bool Token::is_ureal_10() {
		return(
			is_ureal(&Token::is_uinteger_8)
			|| is_decimal_10()
			|| is_uinteger_10()
		);
	}

	bool Token::is_ureal_16() {
		return is_ureal(&Token::is_uinteger_16);
	}
}
