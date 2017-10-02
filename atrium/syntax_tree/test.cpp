#include <iostream>

#include "syntax_tree.h"


int main() {
	Atrium::SyntaxTreeNode* root = new Atrium::SyntaxTreeNode(std::tuple <int, int> (1, 3), "yolo");
	Atrium::SyntaxTreeNode* leaf_1 = new Atrium::SyntaxTreeNode(std::tuple <int, int> (1, 1), "leaf_1");
	Atrium::SyntaxTreeNode* leaf_2 = new Atrium::SyntaxTreeNode(std::tuple <int, int> (2, 3), "leaf_2");

	root->children.push_back(leaf_1);
	root->children.push_back(leaf_2);

	Atrium::SyntaxTree* syntax_tree = new Atrium::SyntaxTree();

	syntax_tree->root = root;

	delete syntax_tree;

	return 0;
}