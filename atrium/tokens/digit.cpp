#include "token.h"

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
		return is_digit(ch);
	}

	bool Token::is_digit_16(char ch) {
		if (is_digit(ch)) {
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

	bool Token::is_sign(char ch) {
		return (
			ch == '+' || ch == '-'
		);
	}
}
