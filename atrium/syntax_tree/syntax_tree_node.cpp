#include "syntax_tree_node.h"

#include <iostream>

namespace Atrium {
	int count = 10;
	SyntaxTreeNode::~SyntaxTreeNode () {
		for (auto child : this->children) {
			std::cout << count ++ << "\n";
			if (count == 10) {
				exit(1);
			}
			if (child) {
				delete child;
			}
		}
	}
}