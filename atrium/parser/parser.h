#ifndef ATRIUM_PARSER_H
#define ATRIUM_PARSER_H

#include <iostream>
#include <cstddef>

#include <spdlog/spdlog.h>

#include "../global_aliases.h"
#include "../tokens/token_vector.h"

namespace Atrium {
	namespace Parsing {
		class Parser {
			Atrium::TokenVector token_vector;
			SpdlogLogger spdlog_console;

			std::size_t token_vector_index {0};
		public:
			Parser(
				const Atrium::TokenVector&& token_vector,
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
