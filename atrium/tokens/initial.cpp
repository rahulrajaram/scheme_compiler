#include "token.h"

namespace Atrium {
	bool Token::is_initial(const char c) {
		switch(c) {
			case '!': return true;
			case '$': return true;
			case '%': return true;
			case '&': return true;
			case '*': return true;
			case '/': return true;
			case ':': return true;
			case '<': return true;
			case '=': return true;
			case '>': return true;
			case '?': return true;
			case '~': return true;
			case '_': return true;
			case '^': return true;
		}

		return is_letter(c);
	}
}
