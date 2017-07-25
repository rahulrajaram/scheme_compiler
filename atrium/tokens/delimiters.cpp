#include "token.h"

namespace Atrium {
	bool Token::is_left_paren() {
		if (token == "(") {
			return true;
		}

		return false;
	}	

	bool Token::is_right_paren() {
		if (token == ")") {
			return true;
		}

		return false;
	}

	bool Token::is_left_bracket() {
		if (token == "[") {
			return true;
		}

		return false;
	}	

	bool Token::is_right_bracket() {
		if (token == "]") {
			return true;
		}

		return false;
	}

	bool Token::is_separator() {
		if (token == ".") {
			return true;
		}

		return false;
	}

	bool Token::is_hash() {
		if (token == "#") {
			return true;
		}

		return false;
	}
}
