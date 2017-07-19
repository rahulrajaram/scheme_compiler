#include "token.h"

namespace Atrium {
	bool Token::is_num_2() {
		int offset = 0;
		if (starts_with_prefix_2(offset)) {
			Token possible_complex_2 = Token(this->token.substr(offset));
			if (possible_complex_2.is_complex_2()) {
				return true;
			}
		}

		if (possible_complex_2.is_complex_2()) {
			return true;
		}

		return false;
	}

	bool Token::is_num_8() {
		int offset = 0;
		if (starts_with_prefix_8(offset)) {
			Token possible_complex_8 = Token(this->token.substr(offset));
			if (possible_complex_8.is_complex_2()) {
				return true;
			}
		}

		if (possible_complex_8.is_complex_8()) {
			return true;
		}

		return false;
	}

	bool Token::is_num_10() {
		int offset = 0;
		if (starts_with_prefix_10(offset)) {
			Token possible_complex_10 = Token(this->token.substr(offset));
			if (possible_complex_10.is_complex_10()) {
				return true;
			}
		}

		if (possible_complex_10.is_complex_10()) {
			return true;
		}

		return false;
	}

	bool Token::is_num_16() {
		int offset = 0;
		if (starts_with_prefix_16(offset)) {
			Token possible_complex_16 = Token(this->token.substr(offset));
			if (possible_complex_16.is_complex_16()) {
				return true;
			}
		}

		if (possible_complex_16.is_complex_16()) {
			return true;
		}

		return false;
	}
}
