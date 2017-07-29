#include "parser.h"

namespace Atrium {
	// <do result> --> <sequence> | <empty>
	bool Parser::is_do_result() {
		if (!is_sequence()) {
			return false;
		}

		print_production(token_vector_index, "is_do_result");
		return true;
	}
}
