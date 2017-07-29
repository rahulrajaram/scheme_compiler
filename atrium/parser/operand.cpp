#include "parser.h"

namespace Atrium {
	bool Parser::is_operand() {
		return (is_expression());
	}
}
