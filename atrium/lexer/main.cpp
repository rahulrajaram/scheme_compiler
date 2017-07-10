#include <spdlog/spdlog.h>

#include "lexer.h"

void print_welcome_message (SpdlogLogger spdlog_console) {
	spdlog_console->info("**************************************");
	spdlog_console->info("                                     *");
	spdlog_console->info("Welcome the Atrium Scheme compiler!  *");
	spdlog_console->info("                                     *");
	spdlog_console->info("**************************************");
	spdlog_console->info("");
	spdlog_console->info("");
}

int main (int argc, char* argv[]) {
	SpdlogLogger spdlog_console = spdlog::stdout_color_mt("console");
	print_welcome_message (spdlog_console);

	IfStream source_file(argv[1]);
	
	if (!source_file.is_open()) {
		std::cout << "File not present!\n";

		std::exit(1);
	}

	auto lexer = Atrium::LexicalAnalysis::Lexer(source_file);

	Atrium::LexicalAnalysis::TokenVector token_vector = lexer.parse(spdlog_console);

	return 0;
}
