#include "parser.h"

namespace Atrium {
	bool Parser::is_expression() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_constant ()) {
			return true;
		}

		if (is_variable ()) {
			return true;
		}

		if (is_application ()) {
			return true;
		}

		if (is_single_quote()) {
			if (!is_datum ()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			return true;
		}

		if (is_left_paren()) {
			if (is_quote()) {
				if (! is_datum ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			} else if (is_lambda()) {
				if (! is_formals ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
				
				if (! is_body ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			} else if (is_if()) {
				if (! is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				if (! is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				if (is_right_paren()) {
					return true;
				}

				if (! is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			} else if (is_set_bang()) {
				if (! is_variable ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				if (! is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			} else if (is_let_syntax()) {
				if (!is_left_paren()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				while (is_syntax_binding ());

				if (!is_right_paren()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				if (! is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				while ( is_expression ());
			} else if (is_letrec_syntax()) {
				if (!is_left_paren()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				while (is_syntax_binding ());

				if (!is_right_paren()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				if (!is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				while ( is_expression ());
			} 

			if (!is_right_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			return true;
		}
	}
}
