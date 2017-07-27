#include "parser.h"

namespace Atrium {
	bool Parser::is_program() {
		while (is_form ());

		return true;
	}
}
