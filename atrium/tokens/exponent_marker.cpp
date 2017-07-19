#include "token.h"

namespace Atrium {
	bool Token::is_exponent_marker(const char c) {
		switch(c) {
			case 'e': return true;
			case 's': return true;
			case 'f': return true;
			case 'd': return true;
			case 'l': return true;
		}

		return false;
	}
}
