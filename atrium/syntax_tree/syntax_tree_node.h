#ifndef SYNTAX_TREE_NODE
#define SYNTAX_TREE_NODE

#include <tuple>
#include <vector>

namespace Atrium {
	class SyntaxTreeNode {
		std::tuple <int, int> range {-1, -1};
		std::string type;
	public:

		std::vector <SyntaxTreeNode*> children;

		SyntaxTreeNode(
			const std::tuple <int, int>& range,
			const std::string type
		) : range { range },
			type { type }
			{}

		~SyntaxTreeNode();
	};
}

#endif
