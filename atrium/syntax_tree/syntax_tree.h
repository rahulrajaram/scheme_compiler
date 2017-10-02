#ifndef SYNTAX_TREE
#define SYNTAX_TREE

#include <iostream>

#include "syntax_tree_node.h"

namespace Atrium {
	class SyntaxTree {
	public:
		SyntaxTreeNode* root { nullptr };

		~SyntaxTree();
	};
}

#endif
