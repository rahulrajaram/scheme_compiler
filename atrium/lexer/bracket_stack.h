#ifndef BRACKET_STACK_H
#define BRACKET_STACK_H

#include <stack>

namespace Atrium {
	namespace LexicalAnalysis {

		class BracketStack {
			std::stack <char> bracket_stack;

		public:
			void handle_open_bracket(const char bracket);
			void handle_closed_bracket(const char bracket, int line_number);
			bool definitely_unbalanced();
		};
	}
}

#endif
