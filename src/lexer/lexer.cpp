#include <iostream>

#include <spdlog/spdlog.h>

#include "lexer.h"

namespace Atrium {
	namespace LexicalAnalysis {
		void Lexer::parse(
			SpdlogLogger spdlog_console
		) {
			spdlog_console->info("... Begin parsing");

			while ((present_character = lexer_input.source_file.get()) != EOF) {
				if (inside_comment()) {
					handle_commented_code();
				} else {
					handle_uncommented_code();
				}
				previous_char = present_character;
			}

			token_vector.print();
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
			}	else {
				handle_uncommented_and_non_string_code();
			}
		}

		void Lexer::handle_uncommented_and_non_string_code() {
			switch(present_character) {
				case '(':
					paren_stack.handle_open_paren();

					push_back_current_token_and_tokenize_present_character();
					push_back_and_clear_present_token();

					break;
				case ')':
					paren_stack.handle_closed_paren(this->current_line_number);

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
					inside_single_line_comment = true;

					break;
				case '\'':
					present_token = std::string(1, present_character);
					push_back_and_clear_present_token();

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

		bool Lexer::previous_character_was_hash() {
			return (previous_char == '#');
		}

		bool Lexer::previous_character_was_vertical_dash() {
			return (previous_char == '|');
		}

		void Lexer::push_back_current_token_and_tokenize_present_character() {
			token_vector.push_back(present_token);
			present_token = std::string(1, present_character);
		}

		void Lexer::push_back_and_clear_present_token() {
			token_vector.push_back(present_token);
			present_token.clear();
		}
	}
}
