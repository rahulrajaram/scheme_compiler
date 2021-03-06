#ifndef ATRIUM_TOKEN_H
#define ATRIUM_TOKEN_H

#include <iostream>
#include <cstddef>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace Atrium {
	class Token {
	public:
		const static std::unordered_map <std::string, std::string> non_printing_characters_map;
		const static std::unordered_set <std::string> syntactic_keywords;
		const static std::unordered_set <std::string> procedures;
	
		std::string token;
		std::string type;

		/***************************************
		 * Constructors
		 ***************************************/
		Token(
			const std::string& token
		) : token { token }
				{ }

		Token(
			const std::string& token,
			const std::string& type
		) : token { token }, type { type }
				{ }

		/***************************************
		 * Token Comparators
		 ***************************************/
		inline bool operator!=(const Token& other_token) const {
			return (
				token != other_token.token
			);
		}
	
		/***************************************
		 * Classifier methods
		 ***************************************/
		void classify ();


		/***************************************
		 * Syntactic keyword
		 ***************************************/
		bool is_syntactic_keyword ();


		/***************************************
		 * Procedures
		 ***************************************/
		bool is_procedure ();


		/***************************************
		 * Number
		 ***************************************/
		bool is_number ();

		bool is_num(
			bool (Token::*is_complex_method)(),
			bool (Token::*starts_with_prefix_r)(int& offset)
		);
		bool is_num_2 ();
		bool is_num_8 ();
		bool is_num_10 ();
		bool is_num_16 ();

		bool starts_with_prefix_r (
			std::vector <std::string> four_char_prefixes,
			std::vector <std::string> two_char_prefixes,
			int& offset
		);
		bool starts_with_prefix_2 (int& offset);
		bool starts_with_prefix_8 (int& offset);
		bool starts_with_prefix_10 (int& offset);
		bool starts_with_prefix_16 (int& offset);

		bool is_complex(
			bool (Token::*is_complex_method)(),
			bool (Token::*is_real_method)(),
			bool (Token::*is_imag_method)()
		);
		bool is_complex_2 ();
		bool is_complex_8 ();
		bool is_complex_10 ();
		bool is_complex_16 ();

		bool is_real(bool (Token::*is_ureal_method)());
		bool is_real_2 ();
		bool is_real_8 ();
		bool is_real_10 ();
		bool is_real_16 ();

		bool is_imag(bool (Token::*is_imag_method)() );
		bool is_imag_2 ();
		bool is_imag_8 ();
		bool is_imag_10 ();
		bool is_imag_16 ();
	
		bool is_ureal(bool (Token::*is_uinteger_method)() );
		bool is_ureal_2();
		bool is_ureal_8();
		bool is_ureal_10();
		bool is_ureal_16();

		bool is_uinteger(bool (Token::*is_digit_method)(char) );
		bool is_uinteger_2 ();
		bool is_uinteger_8 ();
		bool is_uinteger_10 ();
		bool is_uinteger_16 ();

		bool is_decimal_10 ();

		bool is_exponent ();

		bool is_exponent_marker(const char c);

		bool is_suffix ();

		bool is_all_digits ();
		bool contains_only (char ch);
		bool starts_with_prefix (const std::string& prefix);
		bool ends_with_suffix (const std::string& suffix);
		std::pair<Token, Token> split_around_pivot (const std::string& pivot, bool include_split_point=false);
		std::pair<Token, Token> split_at_discontinuity (const char continuity_character);
		std::size_t exponent_marker_position();

		bool is_digit (char ch);
		bool is_digit_10 (char ch);
		bool is_digit_16 (char ch);
		bool is_digit_8 (char ch);
		bool is_digit_2 (char ch);
		bool is_sign (char ch);

		std::size_t position_of_at_sign();
		std::size_t position_of_minus_sign();
		std::size_t position_of_plus_sign();


		/****************************************************
		 * Datum
		 ****************************************************/
		bool is_identifier();

		bool is_letter(const char c);
		bool is_initial(const char c);
		bool is_subsequent(const char c);

		bool is_symbol();

		/****************************************************
		 * Strings
		 * **************************************************/
		bool is_character ();
		bool is_printing_character ();
		bool is_non_printing_character ();

		bool is_string ();
		bool is_boolean ();


		/****************************************************
		 * Delimiters
		 * **************************************************/
		bool is_left_paren ();
		bool is_right_paren ();
		bool is_left_bracket ();
		bool is_right_bracket ();
		bool is_separator ();
		bool is_hash ();
		
		
		/****************************************************
		 * Abbreviation prefix
		 * **************************************************/
		bool is_abbreviation_prefix ();
		bool is_backtick();
		bool is_single_quote ();
		bool is_comma ();
		bool is_comma_at ();

	};
}
#endif
