#include "parser.h"

namespace Atrium {
	bool Parser::is_template_element () {
		if (!is_template ()) {
			return false;
		}

		is_ellipsis ();

		return true;
	}
}
