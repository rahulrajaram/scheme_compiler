#include <cstddef>
#include <iostream>
#include <string>

#include "token.h"

namespace Atrium {
	bool Token::is_complex(
		bool (Token::*is_complex_method)(),
		bool (Token::*is_real_method)(),
		bool (Token::*is_imag_method)()
	) {
		int separator_location = 0;

		// <real 2> @ <real 2>
		if ((separator_location = position_of_at_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			return (
				(&first_part->*is_real_method)()
				&& (&second_part->*is_real_method)()
			); 
		}

		// + <imag 2>
		if (starts_with_prefix("+")) {
			Token possibly_imag_method = Token(token.substr(1));

			return (
				(&possibly_imag_method->*is_imag_method)()
				|| (&possibly_imag_method->*is_complex_method)()
			);
		}

		// - <imag 2>
		if (starts_with_prefix("-")) {
			Token possibly_imag_method = Token(token.substr(1));

			return (
				(&possibly_imag_method->*is_imag_method)()
				|| (&possibly_imag_method->*is_complex_method)()
			);
		}

		// <real 2> - <imag 2>
		if ((separator_location = position_of_minus_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			return (
				(&first_part->*is_real_method)()
				&& (&second_part->*is_imag_method)()
			);
		}

		// <real 2> + <imag 2>
		if ((separator_location = position_of_plus_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			return (
				(&first_part->*is_real_method)()
				&& (&second_part->*is_imag_method)()
			);
		}

		// <real 2>
		return (this->*is_real_method)();
	}


	/*
	 * complex_2
	 */
	bool Token::is_complex_2() {
		return is_complex(
			&Token::is_complex_2,
			&Token::is_real_2,
			&Token::is_imag_2
		);
	}


	/*
	 * complex 8
	 */
	bool Token::is_complex_8() {
		return is_complex(
			&Token::is_complex_8,
			&Token::is_real_8,
			&Token::is_imag_8
		);
	}

	/*
	 * complex 10
	 */
	bool Token::is_complex_10() {
		return is_complex(
			&Token::is_complex_10,
			&Token::is_real_10,
			&Token::is_imag_10
		);
	}

	/*
	 * complex 16
	 */
	bool Token::is_complex_16() {
		return is_complex(
			&Token::is_complex_16,
			&Token::is_real_16,
			&Token::is_imag_16
		);
	}

	std::size_t Token::position_of_at_sign() {
		return token.find("@");
	}
	
	std::size_t Token::position_of_minus_sign() {
		return token.find("-");
	}
	
	std::size_t Token::position_of_plus_sign() {
		return token.find("+");
	}
}
