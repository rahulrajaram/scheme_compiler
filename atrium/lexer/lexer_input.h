#ifndef LEXER_INPUT_H
#define LEXER_INPUT_H

#include <fstream>

#include "../global_aliases.h"

namespace Atrium {
	namespace LexicalAnalysis {

		class LexerInput {
		public:
			IfStream& source_file;
			IfStream& language_specification_file;
			LexerInput(
				IfStream& source_file,
				IfStream& lang_spec_file
			) :
				source_file { source_file },
				language_specification_file { lang_spec_file }
				{}
		};

	}
}


#endif
