#include <spdlog/spdlog.h>

#include "lexer_input.h"
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

int main () {
	SpdlogLogger spdlog_console = spdlog::stdout_color_mt("console");
	print_welcome_message (spdlog_console);

	IfStream source_file("../../config/prog1.sc");
	IfStream lang_spec_file("../../config/syntax.txt");
	
	auto lexer_input = Atrium::LexicalAnalysis::LexerInput(source_file, lang_spec_file);
	auto lexer = Atrium::LexicalAnalysis::Lexer(lexer_input);

	lexer.parse(spdlog_console);

	return 0;
}
