#include "syntax_tree_node.h"

namespace Atrium {
	SyntaxTreeNode::~SyntaxTreeNode () {
		for (auto child : this->children) {
			if (child) {
				delete child;
			}
		}
	}
}