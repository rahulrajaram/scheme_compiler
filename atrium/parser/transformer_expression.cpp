#include "parser.h"

namespace Atrium {
	// <transformer expression> --> (syntax-rules (<identifier>*) <syntax rule>*)
	bool Parser::is_transformer_expression() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_syntax_rules()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (!is_left_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		while (is_identifier());

		if (!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		while (is_syntax_rule());

		if (!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		print_production(token_vector_index_at_entry, "transformer_expression");
		return true;
	}
}
