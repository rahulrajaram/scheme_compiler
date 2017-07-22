#include "token.h"

namespace Atrium {
	bool Token::starts_with_prefix_2(int& offset) {
		if (token.length() >= 4) {
			if (
				token.substr(0, 4) == "#b#e"
				|| token.substr(0, 4) == "#b#i"
				|| token.substr(0, 4) == "#i#b"
				|| token.substr(0, 4) == "#e#b"
			) {
				offset += 4;
				return true;
			}
		}

		if (token.length() >= 2) {
			if (token.substr(0, 2) == "#b") {
				offset += 2;
				return true;
			}
		}

		return false;
	}

	bool Token::starts_with_prefix_8(int& offset) {
		if (token.length() >= 4) {
			if (
				token.substr(0, 4) == "#o#e"
				|| token.substr(0, 4) == "#o#i"
				|| token.substr(0, 4) == "#i#o"
				|| token.substr(0, 4) == "#e#o"
			) {
				offset += 4;
				return true;
			}
		}
		if (token.length() >= 2) {
			if (token.substr(0, 2) == "#o") {
				offset += 2;
				return true;
			}
		}
		return false;
	}

	bool Token::starts_with_prefix_10(int& offset) {
		if (token.length() >= 4) {
			if (
				token.substr(0, 4) == "#d#e"
				|| token.substr(0, 4) == "#d#i"
				|| token.substr(0, 4) == "#i#d"
				|| token.substr(0, 4) == "#e#d"
			) {
				offset += 4;
				return true;
			}
		}
		if (token.length() >= 2) {
			if (
				token.substr(0, 2) == "#o"
				|| token.substr(0, 2) == "#e"
				|| token.substr(0, 2) == "#i"
			) {
				offset += 2;
				return true;
			}
		}
		return false;
	}

	bool Token::starts_with_prefix_16(int& offset) {
		if (token.length() >= 4) {
			if (
				token.substr(0, 4) == "#x#e"
				|| token.substr(0, 4) == "#x#i"
				|| token.substr(0, 4) == "#i#x"
				|| token.substr(0, 4) == "#e#x"
			) {
				offset += 4;
				return true;
			}
		}
		if (token.length() >= 2) {
			if (token.substr(0, 2) == "#x") {
				offset += 2;
				return true;
			}
		}
		return false;
	}
}
