#ifndef LEXER_H
#define LEXER_H

#include <vector>

#include "../global_aliases.h"
#include "bracket_stack.h"
#include "../tokens/token_vector.h"

namespace Atrium {
	namespace LexicalAnalysis {
		class Lexer {

			BracketStack bracket_stack;
			TokenVector token_vector;

			int current_line_number {1};
			char present_character;
			char previous_char {-1};
			std::string present_token {""};

			void push_back_current_token_and_tokenize_present_character();
			void push_back_and_clear_present_token();

			int increment_line_number ();
			void print_token_array();
		public:
			// member variables
			IfStream& source_file;
			bool suppress_output {true};


			void classify_and_push_token ();

			bool inside_character {false};
			bool inside_string {false};
			bool inside_quoted_expression {false};
			bool inside_single_line_comment {false};
			bool inside_multiline_comment {false};
			bool possible_abbreviation_prefix {false};

			Lexer(
				IfStream& source_file
			) :
				source_file { source_file }
				{}

			TokenVector tokenize ();
			TokenVector tokenize (const std::string& token_string);

			bool inside_comment();
			bool previous_character_was_backslash();
			bool previous_character_was_hash();
			bool previous_character_was_vertical_dash();
			bool previous_character_was_comma();
			bool previous_character_was_whitespace();
			bool current_character_is_whitespace();
			bool current_character_is_alphabetic();
			void handle_commented_code();
			void handle_uncommented_code();
			void handle_uncommented_and_non_string_code();
		};
	}
}
#endif
