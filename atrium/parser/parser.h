#ifndef ATRIUM_PARSER_H
#define ATRIUM_PARSER_H

#include <iostream>
#include <cstddef>

#include "../global_aliases.h"
#include "../tokens/token_vector.h"

namespace Atrium {
	class Parser {
		Atrium::TokenVector token_vector;

		std::size_t token_vector_index_prev {0};
		std::size_t token_vector_index {0};

		std::string current_token ();
		std::string current_token_type ();
	public:
		bool suppress_output {true};
		Parser(
			const Atrium::TokenVector&& token_vector
		) :
			token_vector { token_vector }
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
		bool is_expression();
		bool is_form();
		bool is_formals();
		bool is_iteration_spec();
		bool is_keyword();
		bool is_list();
		bool is_operand();
		bool is_operator();
		bool is_pattern_identifier();
		bool is_pattern();
		bool is_procedure_call();
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
		bool is_abbreviation_prefix ();
		bool is_and ();
		bool is_begin ();
		bool is_boolean ();
		bool is_case ();
		bool is_character ();
		bool is_cond ();
		bool is_define ();
		bool is_define_syntax ();
		bool is_delay ();
		bool is_do ();
		bool is_ellipsis ();
		bool is_else ();
		bool is_equal_arrow ();
		bool is_hash ();
		bool is_identifier ();
		bool is_if ();
		bool is_lambda ();
		bool is_left_paren ();
		bool is_let ();
		bool is_let_star ();
		bool is_letrec ();
		bool is_let_syntax ();
		bool is_letrec_syntax ();
		bool is_number ();
		bool is_or ();
		bool is_period ();
		bool is_quote ();
		bool is_right_paren ();
		bool is_set_bang ();
		bool is_single_quote ();
		bool is_string ();
		bool is_symbol ();
		bool is_syntactic_keyword ();
		bool is_syntax_rules ();
		bool is_terminal (const std::string& type);
		bool is_terminal_type (const std::string& type);

		// other utils
		void print_production(
			const int token_vector_index_at_entry,
			const std::string& prod_type
		);

		void log(
			char* file,
			char* method,
			int line_number
		);

		#define LOG() log((char*)(__FILE__), (char*)(__FUNCTION__), __LINE__);
	};
}

#endif
