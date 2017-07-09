#ifndef PAREN_STACK_H
#define PAREN_STACK_H

namespace Atrium {
	namespace LexicalAnalysis {

		class ParenStack {
			int state {0};

		public:
			void handle_open_paren();
			void handle_closed_paren(int line_number);
			bool definitely_unbalanced();
		};
	}
}

#endif
