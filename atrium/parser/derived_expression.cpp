#include "parser.h"

namespace Atrium {

	bool Parser::is_derived_expression() {
		std::size_t token_vector_index_at_entry = token_vector_index;

    // TODO: support <quasiquotation>
		/*if (is_quasiquotation()) {*/
			//return true;
		/*}*/

		// (
		if (!is_left_paren ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (is_cond())  {
			// cond <cond clause>+
			// cond <cond clause>* (else <sequence>)
			if (is_cond_clause ()) {
				while (is_cond_clause());
			} else if (is_cond_clause()) {
				while (is_cond_clause());

				if (!is_left_paren()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
				if (!is_else ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				if (!is_sequence ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				if (!is_right_paren ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			} else {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
		} else if (is_case()) {
			// case <expression> <case clause>+
			// case <expression> <case clause>* (else <sequence>)
			if (! is_expression()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (is_case_clause ()) {
				while (is_case_clause());
			} else if (is_left_paren ()) {
				if (!is_else()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
				if (!is_sequence ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
						
				if (!is_right_paren()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			} else {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
		} else if (is_and()) {
			// (and <test>*)
			while (is_test());
		} else if (is_or()) {
			// (or <test>*)
			while (is_test());
		} else if (is_let()) {
			// let (<binding spec>*) <body>
			// let <variable> (<binding spec>*) <body>
			if (is_variable ());

			if (!is_left_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			while (is_binding_spec());

			if (!is_right_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (!is_body ()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
		} else if (is_let_star()) {
			// let* (<binding spec>*) <body>
			if (is_left_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			while (is_binding_spec());

			if (!is_right_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (!is_body()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
		} else if (is_letrec()) {
			// letrec (<binding spec>*) <body>
			if (!is_left_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			while (is_binding_spec());

			if (!is_right_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (!is_body()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
		} else if (is_begin()) {

			// begin <sequence>
			if (!is_sequence()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
		} else if (is_do ()) {
			// do (<iteration spec>*) (<test> <do result>) <command>*

			// (<iteration spec>*)
			if (!is_left_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			while (is_binding_spec ());

			if (!is_right_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			// (<test> <do result>)
			if (!is_left_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (!is_test ()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (!is_do_result ()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (!is_right_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			while (is_command ());

		} else if (is_delay()) {
     	// (delay <expression>)
			if (!is_expression ()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			return true;
		} else {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		// )
		if (!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
