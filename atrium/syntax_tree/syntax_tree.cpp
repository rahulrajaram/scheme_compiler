#include "syntax_tree.h"

namespace Atrium {
	SyntaxTree::~SyntaxTree () {
		if (this->root) {
			delete root;
		}
	}
}