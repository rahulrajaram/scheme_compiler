#include "token.h"

namespace Atrium {
	bool Token::is_symbol() {
		return is_identifier();
	}
}
