#ifndef TOKEN_VECTOR_H
#define TOKEN_VECTOR_H

#include <iostream>
#include <vector>

#include "token.h"

namespace Atrium {
	class TokenVector {
		public:
		std::vector<Atrium::Token> token_vector;
		void push_back(const std::string& token);
		void push_back(const Token& token);
		void print_token_strings();
	};
}

#endif
