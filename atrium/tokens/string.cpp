#include "token.h"

namespace Atrium {
	/*
	 * TODO: Add support for multi-line strings
	 */

	bool Token::is_string() {
		if (token.length() == 1) {
			return false;
		}

		if (
			!starts_with_prefix("\"")	
			|| !ends_with_suffix("\"")
		) {
			return false;
		}

		std::string string_content = token.substr(1, token.length() - 2);

		if (!string_content.length()) {
			return true;
		}

		for (int i = 0; i < string_content.length() - 1; ){
			if (string_content[i] == '\\') {
				if (string_content[i + 1] == '\\' || string_content[i + 1] == '\"') {
					i += 2;
					continue;
				} else {
					return false;
				}
			}

			if (string_content[i] == '\"') {
				return false;
			}
			i += 1;
		}

		return true;
	}
}
