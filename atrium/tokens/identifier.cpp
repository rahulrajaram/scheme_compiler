#include "token.h"

namespace Atrium {
	bool Token::is_identifier() {
		if (
			token == "+"
			|| token == "-"
			|| token == "..."
		) {
			return true;
		}

		if (is_initial(token[0])) {
			for (auto c : token.substr(1)) {
				if (!is_subsequent(c)) {
					return false;
				}
			}

			return true;
		}
		return false;
	}
}
