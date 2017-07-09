#include "token_vector.h"

namespace Atrium {
	namespace LexicalAnalysis {

		void TokenVector::push_back(const std::string& token) {
			if (!token.empty()) {
				token_vector.push_back(token);
			}
		}

		void TokenVector::print() {
			for (auto token : token_vector) {
				std::cout << token << "\n";
			}
		}

	}
}
