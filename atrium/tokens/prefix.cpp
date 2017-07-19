#include "token.h"

namespace Atrium {
	bool Token::starts_with_prefix_2(int& offset) {
		if (token.length() >= 4) {
			if (
				token == "#b#e"
				|| token == "#b#i"
				|| token == "#i#b"
				|| token == "#e#b"
			) {
				offset += 4;
				return true;
			}

			if (token.length() >= 2) {
				if (token == "#b") {
					return true;
				}
			}
		}
		return false;
	}

	bool Token::starts_with_prefix_8(int& offset) {
		if (token.length() >= 4) {
			if (
				token == "#o#e"
				|| token == "#o#i"
				|| token == "#i#o"
				|| token == "#e#o"
			) {
				offset += 4;
				return true;
			}

			if (token.length() >= 2) {
				if (token == "#o") {
					return true;
				}
			}
		}
		return false;
	}

	bool Token::starts_with_prefix_10(int& offset) {
		if (token.length() >= 4) {
			if (
				token == "#d#e"
				|| token == "#d#i"
				|| token == "#i#d"
				|| token == "#e#d"
			) {
				offset += 4;
				return true;
			}

			if (token.length() >= 2) {
				if (
					token == "#o"
					|| token == "#e"
					|| token == "#i"
				) {
					return true;
				}
			}
		}
		return false;
	}

	bool Token::starts_with_prefix_16(int& offset) {
		if (token.length() >= 4) {
			if (
				token == "#x#e"
				|| token == "#x#i"
				|| token == "#i#x"
				|| token == "#e#x"
			) {
				offset += 4;
				return true;
			}

			if (token.length() >= 2) {
				if (token == "#x") {
					return true;
				}
			}
		}
		return false;
	}
}
