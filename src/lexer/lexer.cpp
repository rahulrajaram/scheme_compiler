#include <iostream>

#include <spdlog/spdlog.h>

#include "lexer.h"

namespace Atrium {
	namespace LexicalAnalysis {
		void Lexer::parse(
			SpdlogLogger spdlog_console
		) {
			spdlog_console->info("... Begin parsing");

			char ch;

			while ((ch = lexer_input.source_file.get()) != EOF) {
				if (inside_comment()) {
					handle_commented_code(ch);
				} else {
					handle_uncommented_code(ch);
				}
				previous_char = ch;
			}

			print_token_array();
		}

		int Lexer::increment_line_number() {
			current_line_number ++;

			return current_line_number;
		}

		bool Lexer::inside_comment() {
			return (inside_single_line_comment || inside_multiline_comment);
		}

		void Lexer::handle_commented_code(char ch) {
			if (inside_single_line_comment && ch == '\n') {
				inside_single_line_comment = false;
			}
			if (
				inside_multiline_comment
					&& ch == '#'
					&& previous_character_was_vertical_dash()
				) {
					present_token += ch;
					inside_multiline_comment = false;
			}
		}

		void Lexer::handle_uncommented_code(char ch) {
			if (inside_string) {
				present_token += ch;
				if (ch == '"') {
					token_array.push_back(present_token);
					present_token.clear();
					inside_string = false;
				}
			} else if (inside_quoted_expression) {
				if (ch == ')') {
					token_array.push_back(present_token);
					present_token = std::string(1, ch);
					token_array.push_back(present_token);
					present_token.clear();
					inside_quoted_expression = false;
					paren_stack.handle_closed_paren(current_line_number);
				}	else {
					present_token += ch;
				}
			}	else {
				handle_uncommented_and_non_string_code(ch);
			}
		}

		void Lexer::handle_uncommented_and_non_string_code(char ch) {
			switch(ch) {
				case '(':
					token_array.push_back(present_token);
					present_token += ch;
					token_array.push_back(present_token);
					present_token.clear();
					paren_stack.handle_open_paren();
					break;
				case ')':
					token_array.push_back(present_token);
					present_token += ch;
					token_array.push_back(present_token);
					present_token.clear();
					paren_stack.handle_closed_paren(this->current_line_number);
					break;
				case '\n':
					increment_line_number();
					token_array.push_back(present_token);
					present_token.clear();
					increment_line_number();	
					break;
				case ' ':
					token_array.push_back(present_token);
					present_token.clear();
					break;
				case '\t':
					token_array.push_back(present_token);
					present_token.clear();
					break;
				case '#':
					break;
				case ';':
					inside_single_line_comment = true;
					break;
				case '\'':
					present_token += ch;
					inside_quoted_expression = true;
					break;
				case '|':
					if (previous_character_was_hash()) {
						inside_multiline_comment = true;
					}
					break;
				case '"':
					present_token += ch;
					if (!inside_comment()) {
						inside_string = true;
					}
					break;
				default:
					present_token += ch;
			}
		}

		bool Lexer::previous_character_was_hash() {
			return (previous_char == '#');
		}

		bool Lexer::previous_character_was_vertical_dash() {
			return (previous_char == '|');
		}

		void Lexer::print_token_array() {
			for (auto token : token_array) {
				std::cout << token << "\n";
			}
		}
	}
}
