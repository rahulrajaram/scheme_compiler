#include "parser.h"

namespace Atrium {
	bool Parser::is_template_datum () {
		return is_constant();
	}
}
