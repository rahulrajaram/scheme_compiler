#ifndef BRACKET_STACK_H
#define BRACKET_STACK_H

#include <stack>

namespace Atrium {
	namespace LexicalAnalysis {
		class UnbalancedBracketsException : public std::exception {
			std::string exception_message;
		public:

			UnbalancedBracketsException(int line_number) { 
				exception_message =
					"UnbalancedBracketsException:: Irrevocable Papentheses imbalance at line "
						 + std::to_string(line_number);
				}

			virtual const char* what() const throw() {
				return exception_message.c_str();
			}
		};

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
