#include "token.h"

namespace Atrium {
	bool Token::is_subsequent(const char c) {
		return (
			is_initial(c)
			|| is_digit(c)
			|| is_sign(c)
			|| (c == '.')
		);
	}
}
