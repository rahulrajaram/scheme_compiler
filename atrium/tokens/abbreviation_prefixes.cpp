#include "token.h"

namespace Atrium {
	bool Token::is_single_quote() {
		if (token == "'") {
			return true;
		}
	}	

	bool Token::is_backtick() {
		if (token == "`") {
			return true;
		}
	}

	bool Token::is_comma() {
		if (token == ",") {
			return true;
		}
	}

	bool Token::is_comma_at() {
		if (token == ",@") {
			return true;
		}
	}

	bool Token::is_abbreviation_prefix() {
		return (
			is_backtick()
			|| is_comma()
			|| is_comma_at()
		);
	}
}
