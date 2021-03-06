#include <iostream>

#include <spdlog/spdlog.h>

#include "lexer.h"
#include "../tokens/token.h"

namespace Atrium {
	namespace LexicalAnalysis {
		Atrium::TokenVector Lexer::tokenize(const std::string& tokens_string) {
			for(auto pc : tokens_string) {
				present_character = pc;
				if (inside_comment()) {
					handle_commented_code();
				} else {
					handle_uncommented_code();
				}
				previous_char = present_character;
			}

			if (!suppress_output) {
				token_vector.print_token_strings();
			}

			if (inside_string) {
				// TODO: Create exception class for this
				throw std::exception();
			}

			if (bracket_stack.definitely_unbalanced()) {
				// TODO: Create exception class for this
				throw std::exception();
			}

			token_vector.push_back(present_token);

			return token_vector;
		}

		Atrium::TokenVector Lexer::tokenize() {

			while ((present_character = source_file.get()) != EOF) {
				if (inside_comment()) {
					handle_commented_code();
				} else {
					handle_uncommented_code();
				}
				previous_char = present_character;
			}

			if (!suppress_output) {
				token_vector.print_token_strings();
			}

			return token_vector;
		}

		int Lexer::increment_line_number() {
			current_line_number ++;

			return current_line_number;
		}

		bool Lexer::inside_comment() {
			return (inside_single_line_comment || inside_multiline_comment);
		}

		void Lexer::handle_commented_code() {
			if (inside_single_line_comment && present_character == '\n') {
				inside_single_line_comment = false;
			}
			if (inside_multiline_comment
					&& present_character == '#'
					&& previous_character_was_vertical_dash()
				) {
					inside_multiline_comment = false;
			}
		}

		void Lexer::handle_uncommented_code() {
			if (inside_string) {
				present_token += present_character;
				if (present_character == '"') {
					inside_string = false;

					push_back_and_clear_present_token();
				}
			}	else if (inside_character) {
				if (present_token == "#\\") {
					if (current_character_is_whitespace()) {
						// TODO: Make the exception specific: "Expected character, but found whitespace"
						throw std::exception();
					}
					present_token += present_character;
				} else if (current_character_is_alphabetic()) {
					present_token += present_character;
				} else {
					inside_character = false;
					handle_uncommented_and_non_string_code();
				}
			} else if (possible_abbreviation_prefix) {
				possible_abbreviation_prefix = false;

				if (present_character == '@') {
					present_token += present_character;

					push_back_and_clear_present_token();
				} else {
					push_back_and_clear_present_token();

					handle_uncommented_and_non_string_code();
				}
			} else {
				handle_uncommented_and_non_string_code();
			}
		}

		void Lexer::handle_uncommented_and_non_string_code() {
			switch(present_character) {
				case '(':
					bracket_stack.handle_open_bracket(present_character);

					push_back_current_token_and_tokenize_present_character();
					push_back_and_clear_present_token();

					break;
				case ')':
					bracket_stack.handle_closed_bracket(present_character, this->current_line_number);

					push_back_current_token_and_tokenize_present_character();
					push_back_and_clear_present_token();

					break;
				case '[':
					bracket_stack.handle_open_bracket(present_character);

					push_back_current_token_and_tokenize_present_character();
					push_back_and_clear_present_token();

					break;
				case ']':
					bracket_stack.handle_closed_bracket(present_character, this->current_line_number);

					push_back_current_token_and_tokenize_present_character();
					push_back_and_clear_present_token();

					break;

				case '\n':
					increment_line_number();

					push_back_and_clear_present_token();

					break;
				case ' ':
					push_back_and_clear_present_token();

					break;
				case '\t':
					push_back_and_clear_present_token();

					break;
				case '#':
					present_token = std::string(1, present_character);

					break;
				case ';':
					if (previous_character_was_whitespace()) {
						inside_single_line_comment = true;
					} else {
						present_token += present_character;
					}
					break;
				case '\'':
					present_token = std::string(1, present_character);
					push_back_and_clear_present_token();

					break;
				case '\\':
					if (previous_character_was_hash()) {
						inside_character = true;
						present_token += present_character;
					} else {
						present_token = std::string(1, present_character);
					}

					break;
				case '`':
					present_token = std::string(1, present_character);
					push_back_and_clear_present_token();

					break;
				case ',':
					possible_abbreviation_prefix = true;
					present_token = std::string(1, present_character);

					break;
				case '|':
					if (previous_character_was_hash()) {
						present_token.clear();

						inside_multiline_comment = true;
					}
					break;
				case '"':
					present_token = std::string(1, present_character);

					if (!inside_comment()) {
						inside_string = true;
					}
					break;
				default:
					present_token += present_character;
			}
		}

		bool Lexer::previous_character_was_backslash() {
			return (previous_char == '\\');
		}

		bool Lexer::previous_character_was_hash() {
			return (previous_char == '#');
		}

		bool Lexer::previous_character_was_vertical_dash() {
			return (previous_char == '|');
		}

		bool Lexer::previous_character_was_comma() {
			return (previous_char == ',');
		}

		bool Lexer::previous_character_was_whitespace() {
			return (
				previous_char == '\n'
				|| previous_char == ' '
				|| previous_char == '\t'
			);
		}

		bool Lexer::current_character_is_whitespace() {
			return (
				present_character == '\n'
				|| present_character == ' '
				|| present_character == '\t'
			);
		}

		bool Lexer::current_character_is_alphabetic() {
			return (
				(present_character >= 65 && present_character <= 90)
				|| (present_character >= 97 && present_character <= 122)
			);
		}

		void Lexer::push_back_current_token_and_tokenize_present_character() {
			classify_and_push_token();

			present_token = std::string(1, present_character);
		}

		void Lexer::push_back_and_clear_present_token() {
			classify_and_push_token();

			present_token.clear();
		}


		void Lexer::classify_and_push_token () {
			Token new_token = Token(present_token);	
			new_token.classify();

			token_vector.push_back(new_token);
		};
	}
}
