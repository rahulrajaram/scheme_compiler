#include "parser.h"

namespace Atrium {
	bool Parser::is_test() {
		return is_expression();
	}
}
