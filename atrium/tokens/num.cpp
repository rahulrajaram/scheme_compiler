#include "token.h"

namespace Atrium {
	bool Token::is_num(
		bool (Token::*is_complex_method)(),
		bool (Token::*starts_with_prefix_r)(int& offset)
	) {
		int offset = 0;
		if ((this->*starts_with_prefix_r)(offset)) {
			Token possible_complex_r = Token(this->token.substr(offset));
			if ((&possible_complex_r->*is_complex_method)()) {
				return true;
			}
		}

		return (this->*is_complex_method)();
	}

	bool Token::is_num_2() {
		return is_num(&Token::is_complex_2, &Token::starts_with_prefix_2);
	}

	bool Token::is_num_8() {
		return is_num(&Token::is_complex_8, &Token::starts_with_prefix_8);
	}

	bool Token::is_num_10() {
		return is_num(&Token::is_complex_10, &Token::starts_with_prefix_10);
	}

	bool Token::is_num_16() {
		return is_num(&Token::is_complex_16, &Token::starts_with_prefix_16);
	}
}
