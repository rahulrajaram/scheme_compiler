#ifndef ATRIUM_PARSER_H
#define ATRIUM_PARSER_H

#include <spdlog/spdlog.h>

#include "../global_aliases.h"
#include "../lexer/token_vector.h"

namespace Atrium {
	namespace Parsing {
		class Parser {
			Atrium::LexicalAnalysis::TokenVector token_vector;
			SpdlogLogger spdlog_console;
		public:
			Parser(
				const Atrium::LexicalAnalysis::TokenVector&& token_vector,
				const SpdlogLogger& spdlog_console
			) :
				token_vector { token_vector },
			 	spdlog_console { spdlog_console }
				{}

			void parse();
		};
	}
}

#endif
