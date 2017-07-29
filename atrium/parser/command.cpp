#include "parser.h"

namespace Atrium {
	// <do result> --> <sequence> | <empty>
	bool Parser::is_command() {
		return is_expression();
	}
}
