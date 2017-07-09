#ifndef TOKEN_VECTOR_H
#define TOKEN_VECTOR_H

#include <iostream>
#include <vector>

namespace Atrium {
	namespace LexicalAnalysis {
		
		class TokenVector {
			std::vector<std::string> token_vector;	

			public:
			void push_back(const std::string& token);
			void print();
		};
	}
}

#endif
