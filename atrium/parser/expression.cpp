#include "parser.h"

namespace Atrium {
	bool Parser::is_expression() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_procedure_call ()) {
			print_production(token_vector_index_at_entry, "expression::procedure_call");
			return true;
		}

		if (is_constant ()) {
			print_production(token_vector_index_at_entry, "expression::constant");
			return true;
		}

		if (is_variable ()) {
			print_production(token_vector_index_at_entry, "expression::variable");
			return true;
		}

		if (is_application ()) {
			print_production(token_vector_index_at_entry, "expression::application");
			return true;
		}

		if (is_single_quote()) {
			if (!is_datum ()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			print_production(token_vector_index_at_entry, "expression::single-quote");
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
					print_production(token_vector_index_at_entry, "expression::if");
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

			print_production(token_vector_index_at_entry, "expression");
			return true;
		}
	}
}
