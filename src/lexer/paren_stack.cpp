#include <iostream> 
#include <stdexcept> 
#include <exception> 

#include "paren_stack.h"

namespace Atrium {
	namespace LexicalAnalysis {
	
		class UnbalancedParenthesesException : public std::exception {
			std::string exception_message;
		public:

			UnbalancedParenthesesException(int line_number) { 
				exception_message =
					"UnbalancedParenthesesException:: Irrevocable Papentheses imbalance at line "
						 + std::to_string(line_number);
				}

			virtual const char* what() const throw() {
				return exception_message.c_str();
			}
		};

		void ParenStack::handle_open_paren() {
			state ++;
		}

		void ParenStack::handle_closed_paren(int line_number) {
			state --;	

			try {	
				if (definitely_unbalanced()) {
					throw UnbalancedParenthesesException(line_number);
				}
			} catch (const UnbalancedParenthesesException& e) {
				std::cout << e.what() << "\n";
				std::exit(1);
			}
		}
			
		bool ParenStack::definitely_unbalanced() {
			return (state < 0);
		}
	}
}
