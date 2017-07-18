#include "parser.h"

namespace Atrium {
	namespace Parsing {
		bool Parser::digit(char ch) {
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

		bool Parser::digit10(char ch) {
			return digit(ch);
		}

		bool Parser::digit16(char ch) {
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

		bool Parser::digit8(char ch) {
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

		bool Parser::digit2(char ch) {
			switch (ch) {
				case '0': break;
				case '1': break;
				default: return false;	
			}

			return true;
		}

		bool Parser::radix2(int& token_vector_index) {
			return (token_vector[token_vector_index] == "#b");
		}

		bool Parser::radix2(int& token_vector_index) {
			return (token_vector[token_vector_index] == "#o");
		}
		
		bool Parser::radix10(int& token_vector_index) {
			return (token_vector[token_vector_index] == "#d");
		}

		bool Parser::radix10(int& token_vector_index) {
			return (token_vector[token_vector_index] == "#x");
		}
		
		bool Parser::exactness(int& token_vector_index) {
			return (
				token_vector[token_vector_index] == "#i"
				|| token_vector[token_vector_index] == "#e"
			);
		}	

		bool Parser::sign(char ch) {
			return (
				ch == '+' || ch == '-'
			);
		}
	}
}
