#ifndef LEXER_H
#define LEXER_H

#include <vector>

#include <spdlog/logger.h>
#include <spdlog/spdlog.h>

#include "../global_aliases.h"
#include "bracket_stack.h"
#include "token_vector.h"

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
			SpdlogLogger& spdlog_console;
			bool suppress_output {true};


			bool inside_string {false};
			bool inside_quoted_expression {false};
			bool inside_single_line_comment {false};
			bool inside_multiline_comment {false};

			Lexer(
				IfStream& source_file,
				SpdlogLogger spdlog_console
			) :
				source_file { source_file },
		 		spdlog_console { spdlog_console }
				{}

			TokenVector tokenize ();

			bool inside_comment();
			bool previous_character_was_hash();
			bool previous_character_was_vertical_dash();
			void handle_commented_code();
			void handle_uncommented_code();
			void handle_uncommented_and_non_string_code();
		};
	}
}
#endif
