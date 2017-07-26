#include "parser.h"

namespace Atrium {
	bool Parser::is_vector () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (current_token() != "#") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (current_token() != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		while (is_datum ());

		if (current_token() != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		return true;
	}

	bool Parser::is_datum () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (current_token_type() == "BOOLEAN") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "NUMBER") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "CHARACTER") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "STRING") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "SYMBOL") {
			token_vector_index ++;
			return true;
		}

		if (is_list ()) {
			return true;
		}

		while (is_vector ()) {
			return true;
		};

		return false;
	}

	bool Parser::is_list () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_abbreviation ()) {
			return true;
		}

		if (current_token() != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		token_vector_index ++; 

		if (is_datum()) {
			while (is_datum());

			if (current_token() == ".") {
				token_vector_index ++;

				if (!is_datum()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
			}
		}
		if (current_token() != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		return true;
	}

	bool Parser::is_abbreviation () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (current_token_type() != "ABBREVIATION_PREFIX") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (! is_datum()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}

	bool Parser::is_constant() {
		if (current_token_type() == "BOOLEAN") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "NUMBER") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "CHARACTER") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "STRING") {
			token_vector_index ++;
			return true;
		}

		return false;
	}

	bool Parser::is_application() {
		std::size_t token_vector_index_at_entry = token_vector_index;
		
		if (current_token() != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++; 

		if (! is_expression ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		while ( is_expression ());

		if (current_token() != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++; 

		return true;
	}

	bool Parser::is_formals() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (is_variable ()) {
			token_vector_index ++; 
			return true;
		}

		if (current_token() != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++; 

		if (! is_expression ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (is_variable ()) {
			token_vector_index ++; 
			return true;
		}

		while ( is_expression ());

		if (current_token() != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++; 

		return true;
	}

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

	bool Parser::is_syntax_binding() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (current_token () != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (! is_keyword()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (! is_transformer_expression ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (current_token () != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		return true;
	}

	bool Parser::is_keyword() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (! is_keyword()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		return true;
	}

	bool Parser::is_syntax_definition() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (current_token () != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (current_token () != "define-syntax") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (! is_keyword()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (! is_transformer_expression ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		if (current_token () != ")") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		return true;
	}

	bool Parser::is_body() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		std::size_t token_vector_index_at_start_of_loop = token_vector_index;
		while (is_definition ()) {
			token_vector_index_at_start_of_loop = token_vector_index;
		}

		if (! is_expression ()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		while (is_expression ());

		return true;
	}

	bool Parser::is_variable() {
		if (current_token_type() != "IDENTIFIER" ()) {
			return false;
		}
		token_vector_index ++;

		return true;
	}

	bool Parser::is_variable_definition () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (current_token () != "(") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (current_token () != "define") {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}
		token_vector_index ++;

		if (current_token () == "(") {
			token_vector_index ++;

			if (! is_variable()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			while (is_variable());

			if (current_token () == ".") {
				token_vector_index ++;

				if (! is_variable()) {
					token_vector_index = token_vector_index_at_entry;
					return false;
				}
				token_vector_index ++;
			}

			if (current_token () !== ")") {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
			token_vector_index ++;

			if (! is_body()) {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}

			if (current_token () != ")") {
				token_vector_index = token_vector_index_at_entry;
				return false;
			}
			token_vector_index ++;
		}

		return true;
	}

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


	bool Parser::is_form() {
		if (is_syntax_definition ()) {
			return true;
		}

		if (is_expression ()) {
			return true;
		}

		return false;
	}

	bool Parser::is_program() {
		while (is_form ());

		return true;
	}

	bool Parser::parse () {
		while (token_vector_index < token_vector.size()) {
			if (! is_form ()) {
				return false;
			}
		}

		return false;
	}

	std::string Parser::current_token() {
		return token_vector[token_vector_index].token;
	}

	std::string Parser::current_token_type () {
		return token_vector[token_vector_index].type;
	}
}
