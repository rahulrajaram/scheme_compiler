#include "token.h"

namespace Atrium {
	bool Token::is_boolean() {
		return(
			token == "#t"
			|| token == "#f"
		);
	}
}
