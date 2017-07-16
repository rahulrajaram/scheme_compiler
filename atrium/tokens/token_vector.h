#ifndef TOKEN_VECTOR_H
#define TOKEN_VECTOR_H

#include <iostream>
#include <vector>

namespace Atrium {
	class TokenVector {
		public:
		std::vector<std::string> token_vector;
		void push_back(const std::string& token);
		void print();
	};
}

#endif
