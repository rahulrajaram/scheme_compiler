#include "parser.h"

namespace Atrium {
	// <do result> --> <sequence> | <empty>
	bool Parser::is_do_result() {
		return is_expression();
	}
}
