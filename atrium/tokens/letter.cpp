#include "token.h"

namespace Atrium {
	bool Token::is_letter(const char c) {
		return (c >= 97 && c <= 122);
	}
}
