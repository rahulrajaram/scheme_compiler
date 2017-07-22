#include "token.h"

namespace Atrium {

	bool Token::starts_with_prefix_r(
		std::vector <std::string> four_char_prefixes,
		std::vector <std::string> two_char_prefixes,
		int& offset
	) {
		if (token.length() >= 4) {
			std::string token_prefix = token.substr(0, 4);
			for (auto prefix : four_char_prefixes) {
				if (prefix == token_prefix) {
					offset += 4;
					return true;
				}
			}
		}
		for (auto prefix : two_char_prefixes) {
			std::string token_prefix = prefix.substr(0, 2);
			if (prefix == token_prefix) {
				offset += 2;
				return true;
			}
		}

		return false;
	}

	bool Token::starts_with_prefix_2(int& offset) {
		std::vector <std::string> four_char_prefixes {"#b#e", "#b#i", "#i#b", "#e#b"};
		std::vector <std::string> two_char_prefixes {"#b"};

		return starts_with_prefix_r(four_char_prefixes, two_char_prefixes, offset);
	}

	bool Token::starts_with_prefix_8(int& offset) {
		std::vector <std::string> four_char_prefixes {"#o#e", "#o#i", "#i#o", "#e#o"};
		std::vector <std::string> two_char_prefixes {"#o"};

		return starts_with_prefix_r(four_char_prefixes, two_char_prefixes, offset);
	}

	bool Token::starts_with_prefix_10(int& offset) {
		std::vector <std::string> four_char_prefixes {"#d#e", "#d#i", "#i#d", "#e#d"};
		std::vector <std::string> two_char_prefixes {"#d", "#e", "#i"};

		return starts_with_prefix_r(four_char_prefixes, two_char_prefixes, offset);
	}

	bool Token::starts_with_prefix_16(int& offset) {
		std::vector <std::string> four_char_prefixes {"#x#e", "#x#i", "#i#x", "#e#x"};
		std::vector <std::string> two_char_prefixes {"#x"};

		return starts_with_prefix_r(four_char_prefixes, two_char_prefixes, offset);
	}
}
