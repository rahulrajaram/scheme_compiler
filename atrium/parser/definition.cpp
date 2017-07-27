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

		if (current_token () != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (current_token() == "begin") {
			while (is_definition());

			if (current_token () != ")") {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
			token_vector_index ++;

			return true;
		}

		if (current_token() == "let-syntax") {
			token_vector_index ++;
		} else if (current_token() == "letrec-syntax") {
			token_vector_index ++;
		} else {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (current_token () != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		while (is_syntax_binding());

		if (current_token () != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		while (is_definition());

		if (current_token () != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		return true;
	}
