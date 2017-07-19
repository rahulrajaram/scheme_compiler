#include "parser.h"

namespace Atrium {
	bool Token::is_digit(char ch) {
		switch (ch) {
			case '0': break;
			case '1': break;
			case '2': break;
			case '3': break;
			case '4': break;
			case '5': break;
			case '6': break;
			case '7': break;
			case '8': break;
			case '9': break;
			default: return false;	
		}

		return true;
	}

	bool Token::is_digit_10(char ch) {
		return digit(ch);
	}

	bool Token::is_digit_16(char ch) {
		if (digit(ch)) {
			return true;
		}
		switch (ch) {
			case 'a': break;
			case 'b': break;
			case 'c': break;
			case 'd': break;
			case 'e': break;
			case 'f': break;
			default: return false;	
		}

		return true;
	}

	bool Token::is_digit_8(char ch) {
		switch (ch) {
			case '0': break;
			case '1': break;
			case '2': break;
			case '3': break;
			case '4': break;
			case '5': break;
			case '6': break;
			case '7': break;
			default: return false;	
		}

		return true;
	}

	bool Token::is_digit_2(char ch) {
		switch (ch) {
			case '0': break;
			case '1': break;
			default: return false;	
		}

		return true;
	}

	bool Token::is_radix_2(int& token_vector_index) {
		return (token_vector[token_vector_index] == "#b");
	}

	bool Token::is_radix_8(int& token_vector_index) {
		return (token_vector[token_vector_index] == "#o");
	}
	
	bool Token::is_radix_10(int& token_vector_index) {
		return (token_vector[token_vector_index] == "#d");
	}

	bool Token::is_radix_16(int& token_vector_index) {
		return (token_vector[token_vector_index] == "#x");
	}
	
	bool Token::is_exactness(int& token_vector_index) {
		return (
			token_vector[token_vector_index] == "#i"
			|| token_vector[token_vector_index] == "#e"
		);
	}	

	bool Token::is_sign(char ch) {
		return (
			ch == '+' || ch == '-'
		);
	}
}
