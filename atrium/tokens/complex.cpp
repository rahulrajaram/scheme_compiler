#include <cstddef>
#include <iostream>
#include <string>

#include "token.h"

namespace Atrium {
	/*
	 * complex_2
	 */
	bool Token::is_complex_2() {
		int separator_location = 0;

		// <real 2> @ <real 2>
		if ((separator_location = position_of_at_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_2() && last_part.is_real_2()) {
				return true;
			}

			return false;
		}

		// <real 2> - <imag 2>
		if ((separator_location = position_of_minux_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_2() && last_part.is_imag_2()) {
				return true;
			}

			return false;
		}

		// <real 2> + <imag 2>
		if ((separator_location = position_of_plus_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_2() && last_part.is_imag_2()) {
				return true;
			}

			return false;
		}

		// + <imag 2>
		if ((separator_location = position_of_plus_sign()) == 0) {
			Token possibly_imag_2 = Token(token.substr(1));

			if (possibly_imag_2.is_imag_2()) {
				return true;
			}

			return false;
		}

		// - <imag 2>
		if ((separator_location = position_of_minus_sign()) == 0) {
			Token possibly_imag_2 = Token(token.substr(1));

			if (possibly_imag_2.is_imag_2()) {
				return true;
			}

			return false;
		}

		// <real 2>
		if (is_real_2()) {
			return true;
		}

		return false;
	}


	/*
	 * complex 8
	 */
	bool Token::is_complex_8() {
		int separator_location = 0;

		// <real 8> @ <real 8>
		if ((separator_location = position_of_at_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_8() && last_part.is_real_8()) {
				return true;
			}

			return false;
		}

		// <real 8> - <imag 8>
		if ((separator_location = position_of_minux_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_8() && last_part.is_imag_8()) {
				return true;
			}

			return false;
		}

		// <real 8> + <imag 8>
		if ((separator_location = position_of_plus_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_8() && last_part.is_imag_8()) {
				return true;
			}

			return false;
		}

		// + <imag 8>
		if ((separator_location = position_of_plus_sign()) == 0) {
			Token possibly_imag_8 = Token(token.substr(1));

			if (possibly_imag_8.is_imag_8()) {
				return true;
			}

			return false;
		}

		// - <imag 8>
		if ((separator_location = position_of_minus_sign()) == 0) {
			Token possibly_imag_8 = Token(token.substr(1));

			if (possibly_imag_8.is_imag_2()) {
				return true;
			}

			return false;
		}

		// <real 8>
		if (is_real_8()) {
			return true;
		}

		return false;
	}

	/*
	 * complex 10
	 */
	bool Token::is_complex_8() {
		int separator_location = 0;

		// <real 10> @ <real 10>
		if ((separator_location = position_of_at_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_10() && last_part.is_real_10()) {
				return true;
			}

			return false;
		}

		// <real 10> - <imag 10>
		if ((separator_location = position_of_minux_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_10() && last_part.is_imag_10()) {
				return true;
			}

			return false;
		}

		// <real 10> + <imag 10>
		if ((separator_location = position_of_plus_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_10() && last_part.is_imag_10()) {
				return true;
			}

			return false;
		}

		// + <imag 10>
		if ((separator_location = position_of_plus_sign()) == 0) {
			Token possibly_imag_10 = Token(token.substr(1));

			if (possibly_imag_10.is_imag_10()) {
				return true;
			}

			return false;
		}

		// - <imag 10>
		if ((separator_location = position_of_minus_sign()) == 0) {
			Token possibly_imag_10 = Token(token.substr(1));

			if (possibly_imag_10.is_imag_10()) {
				return true;
			}

			return false;
		}

		// <real 8>
		if (is_real_10()) {
			return true;
		}

		return false;
	}

	/*
	 * complex 16
	 */
	bool Token::is_complex_8() {
		int separator_location = 0;

		// <real 16> @ <real 16>
		if ((separator_location = position_of_at_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_16() && last_part.is_real_16()) {
				return true;
			}

			return false;
		}

		// <real 16> - <imag 16>
		if ((separator_location = position_of_minux_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_16() && last_part.is_imag_16()) {
				return true;
			}

			return false;
		}

		// <real 16> + <imag 16>
		if ((separator_location = position_of_plus_sign()) != std::string::npos) {
			Token first_part = Token(token.substr(0, separator_location));
			Token second_part = Token(token.substr(separator_location + 1));

			if (first_part.is_real_16() && last_part.is_imag_16()) {
				return true;
			}

			return false;
		}

		// + <imag 16>
		if ((separator_location = position_of_plus_sign()) == 0) {
			Token possibly_imag_16 = Token(token.substr(1));

			if (possibly_imag_16.is_imag_16()) {
				return true;
			}

			return false;
		}

		// - <imag 16>
		if ((separator_location = position_of_minus_sign()) == 0) {
			Token possibly_imag_16 = Token(token.substr(1));

			if (possibly_imag_16.is_imag_16()) {
				return true;
			}

			return false;
		}

		// <real 16>
		if (is_real_16()) {
			return true;
		}

		return false;
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
