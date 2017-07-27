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

		if (current_token() == "'") {
			token_vector_index ++;

			if (!is_datum ()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			return true;
		}

		if (current_token() == "(") {
			token_vector_index ++;

			if (current_token () == "quote") {
				token_vector_index ++;

				if (! is_datum ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			}

			if (current_token () == "lambda") {
				token_vector_index ++;

				if (! is_formals ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
				
				if (! is_body ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			}

			if (current_token () == "if") {
				token_vector_index ++;

				if (! is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				if (! is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				if (current_token () == ")") {
					token_vector_index ++;
					return true;
				}

				if (! is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			}

			if (current_token () == "set!") {
				token_vector_index ++;

				if (! is_variable ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				if (! is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			}

			if (current_token () == "let-syntax") {
				token_vector_index ++;

				if (current_token () != "(") {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
				token_vector_index ++;

				std::size_t token_vector_index_at_start_of_loop = token_vector_index;
				while ( is_syntax_binding ()) {
					token_vector_index_at_start_of_loop = token_vector_index;
				}
				token_vector_index = token_vector_index_at_start_of_loop;

				if (current_token () != ")") {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
				token_vector_index ++;

				if (! is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				token_vector_index_at_start_of_loop = token_vector_index;
				while ( is_expression ()) {
					token_vector_index_at_start_of_loop = token_vector_index;
				}
				token_vector_index = token_vector_index_at_start_of_loop;
			}

			if (current_token () == "letrec-syntax") {
				token_vector_index ++;

				if (current_token () != "(") {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
				token_vector_index ++;

				std::size_t token_vector_index_at_start_of_loop = token_vector_index;
				while ( is_syntax_binding ()) {
					token_vector_index_at_start_of_loop = token_vector_index;
				}
				token_vector_index = token_vector_index_at_start_of_loop;

				if (current_token () != ")") {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
				token_vector_index ++;

				if (! is_expression ()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}

				token_vector_index_at_start_of_loop = token_vector_index;
				while ( is_expression ()) {
					token_vector_index_at_start_of_loop = token_vector_index;
				}
				token_vector_index = token_vector_index_at_start_of_loop;
			}

			if (current_token () != ")") {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
			token_vector_index ++;

			return true;
		}
	}
}
