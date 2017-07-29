#include "parser.h"

namespace Atrium {
	bool Parser::is_operator() {
		return (is_expression());
	}
}
