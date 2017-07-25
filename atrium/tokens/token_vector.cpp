#include "token_vector.h"

namespace Atrium {
	void TokenVector::push_back(const std::string& token) {
		if (!token.empty()) {
			token_vector.push_back(Token(token, ""));
		}
	}

	void TokenVector::push_back(const Token& token) {
		if (!token.token.empty()) {
			token_vector.push_back(token);
		}
	}

	void TokenVector::print_token_strings() {
		for (auto token : token_vector) {
			std::cout << token.token << " --> " << token.type << "\n" ;
		}
	}
}
