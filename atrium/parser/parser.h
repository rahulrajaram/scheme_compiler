#ifndef ATRIUM_PARSER_H
#define ATRIUM_PARSER_H

#include <iostream>
#include <cstddef>

#include <spdlog/spdlog.h>

#include "../global_aliases.h"
#include "../tokens/token_vector.h"

namespace Atrium {
	class Parser {
		Atrium::TokenVector token_vector;
		SpdlogLogger spdlog_console;

		std::size_t token_vector_index {0};

		std::string current_token ();
		std::string current_token_type ();
	public:
		Parser(
			const Atrium::TokenVector&& token_vector,
			const SpdlogLogger& spdlog_console
		) :
			token_vector { token_vector },
			spdlog_console { spdlog_console }
			{}

		bool parse();

		bool is_abbreviation();
		bool is_application();
		bool is_body();
		bool is_constant();
		bool is_datum();
		bool is_definition();
		bool is_expression();
		bool is_form();
		bool is_formals();
		bool is_keyword();
		bool is_list();
		bool is_program();
		bool is_syntax_definition();
		bool is_syntax_binding();
		bool is_variable();
		bool is_variable_definition();
		bool is_vector();
	};
}

#endif
