#ifndef LEXER_H
#define LEXER_H

#include <spdlog/logger.h>
#include <spdlog/spdlog.h>

#include "../global_aliases.h"
#include "lexer_input.h"

namespace Atrium {
	namespace Lexer {

		class Lexer {
			Atrium::Lexer::LexerInput& lexer_input;

		public:
			std::shared_ptr<spdlog::logger> console;
			Lexer(Atrium::Lexer::LexerInput& lexer_input) : lexer_input { lexer_input } { };

			void parse (SpdlogLogger);
		};
	}
}

#endif
