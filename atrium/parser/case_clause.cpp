#include "parser.h"

namespace Atrium {
	// <case clause> --> ((<datum>*) <sequence>)
	bool Parser::is_case_clause() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (!is_left_paren()) {
			return false;
		}
	
		if (!is_left_paren()) {
			token_vector_index_at_entry = token_vector_index;
			return false;
		}

		while(is_datum());

		if (!is_right_paren()) {
			token_vector_index_at_entry = token_vector_index;
			return false;
		}

		if (!is_sequence()) {
			token_vector_index_at_entry = token_vector_index;
			return false;
		}	

		if (!is_right_paren()) {
			token_vector_index_at_entry = token_vector_index;
			return false;
		}		

		print_production(token_vector_index_at_entry, "case_clause");
		return true;
	}
}
