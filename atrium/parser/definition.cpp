#include "parser.h"

namespace Atrium {
	bool Parser::is_definition () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_variable_definition ()) {
			return true;
		}

		if (is_syntax_definition ()) {
			return true;
		}

		if (is_derived_expression ()) {
			return true;
		}

		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (is_begin()) {
			while (is_definition());

			if (!is_right_paren()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			return true;
		}

		if (is_let_syntax()) {
		} else if (is_letrec_syntax()) {
		} else {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		while (is_syntax_binding());

		if (!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		while (is_definition());

		if (!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}
}
