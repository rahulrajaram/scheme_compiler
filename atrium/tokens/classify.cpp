#include "token.h"

namespace Atrium {
	void Token::classify () {
		if (token.empty()) {
			return;
		}

		if (is_syntactic_keyword()) {
			type = "SYNTACTIC_KEYWORD";

			return;
		}

		if (is_procedure()) {
			type = "PROCEDURE";

			return;
		}

		if (is_number()) {
			type = "NUMBER";

			return;
		}

		if (is_boolean()) {
			type = "BOOLEAN";

			return;
		}

		if (is_string()) {
			type = "STRING";

			return;
		}

		if (is_character()) {
			type = "CHARACTER";

			return;
		}

		if (is_identifier()) {
			type = "IDENTIFIER";

			return;
		}

		if (is_left_paren()) {
			type = "LEFT_PAREN";

			return;
		}

		if (is_right_paren()) {
			type = "RIGHT_PAREN";

			return;
		}

		if (is_left_bracket()) {
			type = "LEFT_BRACKET";

			return;
		}

		if (is_right_bracket()) {
			type = "RIGHT_BRACKET";

			return;
		}

		if (is_hash()) {
			type = "HASH";

			return;
		}


		if (is_separator()) {
			type = "SEPARATOR";

			return;
		}

		if (is_single_quote()) {
			type = "SINGLE_QUOTE";

			return;
		}

		if (is_abbreviation_prefix()) {
			type = "ABBREVIATION_PREFIX";

			return;
		}
	}
}
