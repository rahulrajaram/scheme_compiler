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
		bool is_binding_spec();
		bool is_body();
		bool is_case_clause();
		bool is_command();
		bool is_cond_clause();
		bool is_constant();
		bool is_datum();
		bool is_definition();
		bool is_derived_expression();
		bool is_do_result();
		bool is_ellipsis ();
		bool is_expression();
		bool is_form();
		bool is_formals();
		bool is_iteration_spec();
		bool is_keyword();
		bool is_list();
		bool is_pattern_identifier();
		bool is_pattern();
		bool is_program();
		bool is_sequence();
		bool is_syntax_definition();
		bool is_syntax_binding();
		bool is_syntax_rule();
		bool is_template ();
		bool is_template_datum ();
		bool is_template_element ();
		bool is_test ();
		bool is_transformer_expression ();
		bool is_variable();
		bool is_variable_definition();
		bool is_vector();

		// Terminal symbols	
		bool is_terminal (const std::string& type);
		bool is_left_paren ();
		bool is_right_paren ();
		bool is_cond ();
		bool is_else ();
		bool is_and ();
		bool is_or ();
		bool is_let ();
		bool is_let_star ();
		bool is_letrec ();
		bool is_begin ();
		bool is_do ();
		bool is_delay ();
		bool is_equal_arrow ();
		bool is_case ();
		bool is_syntax_rules ();
		bool is_hash ();
		bool is_period ();
		bool is_identifier ();
	};
}

#endif
