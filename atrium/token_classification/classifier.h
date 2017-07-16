#ifndef ATRIUM_TOKEN_CLASSIFICATION_CLASSIFIER_H
#define ATRIUM_TOKEN_CLASSIFICATION_CLASSIFIER_H

#include "../lexer/token_vector.h"

namespace Atrium {
	namespace TokenClassification {
		class Classifier {
			Atrium::LexicalAnalysis::TokenVector token_vector;
		public:
			Classifier(
				const Atrium::LexicalAnalysis::TokenVector&& token_vector
			) : token_vector { token_vector }
					{ }
		}
	}
}
#endif
