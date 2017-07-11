#include <iostream> 
#include <stdexcept> 
#include <exception> 

#include "bracket_stack.h"

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

		void BracketStack::handle_open_bracket(const char bracket) {
			bracket_stack.push(bracket);
		}

		void BracketStack::handle_closed_bracket(const char bracket, int line_number) {
			if ((bracket_stack.top()	== '(') && (bracket == ')')) {
				bracket_stack.pop();
			} else if ((bracket_stack.top()	== '[') && (bracket == ']')) {
				bracket_stack.pop();
			} else {
				throw UnbalancedBracketsException(line_number);
			}
		}

		bool BracketStack::definitely_unbalanced() {
			return (bracket_stack.size() > 0);
		}
	}
}
