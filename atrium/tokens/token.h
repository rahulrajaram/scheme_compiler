#ifndef ATRIUM_TOKEN_H
#define ATRIUM_TOKEN_H

#include <iostream>
#include <cstddef>

namespace Atrium {
	class Token {

	std::size_t position_of_at_sign();
	std::size_t position_of_minus_sign();
	std::size_t position_of_plus_sign();

	public:
		std::string token;
		std::string type;

		Token(
			const std::string& token
		) : token { token }
				{ }

		Token(
			const std::string& token,
			const std::string& type
		) : token { token }, type { type }
				{ }

		inline bool operator!=(const Token& other_token) const {
			return (
				token != other_token.token
			);
		}
	
		bool is_number ();

		bool is_num_2 ();
		bool is_num_8 ();
		bool is_num_10 ();
		bool is_num_16 ();

		bool starts_with_prefix_2 (int& offset);
		bool starts_with_prefix_8 (int& offset);
		bool starts_with_prefix_10 (int& offset);
		bool starts_with_prefix_16 (int& offset);

		bool is_complex_2 ();
		bool is_complex_8 ();
		bool is_complex_10 ();
		bool is_complex_16 ();

		bool is_real_2 ();
		bool is_real_8 ();
		bool is_real_10 ();
		bool is_real_16 ();

		bool is_imag_2 ();
		bool is_imag_8 ();
		bool is_imag_10 ();
		bool is_imag_16 ();
	
		bool is_ureal_2();
		bool is_ureal_8();
		bool is_ureal_10();
		bool is_ureal_16();

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
	};
}
#endif
