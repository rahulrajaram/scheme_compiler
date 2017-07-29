#include "parser.h"

namespace Atrium {
	bool Parser::is_variable() {
		return is_identifier();
	}
}
