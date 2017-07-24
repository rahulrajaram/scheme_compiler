#include "token.h"

namespace Atrium {
	bool Token::is_delimiter() {
		if (token == "(") {
			return true;
		}
		
		if (token == ")") {
			return true;
		}

		if (token == ".") {
			return true;
		}
	}
}
