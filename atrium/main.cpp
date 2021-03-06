#include <exception>

#include <spdlog/spdlog.h>

#include "lexer/bracket_stack.h"
#include "lexer/lexer.h"
#include "parser/parser.h"

/*void print_welcome_message (SpdlogLogger spdlog_console) {*/
	//spdlog_console->info("**************************************");
	//spdlog_console->info("                                     *");
	//spdlog_console->info("Welcome the Atrium Scheme compiler!  *");
	//spdlog_console->info("                                     *");
	//spdlog_console->info("**************************************");
	//spdlog_console->info("");
	//spdlog_console->info("");
/*}*/

int main (int argc, char* argv[]) {
	//SpdlogLogger spdlog_console = spdlog::stdout_color_mt("console");

	IfStream source_file(argv[1]);
	
	if (!source_file.is_open()) {
		std::cout << "File not present!\n";

		std::exit(1);
	}

	auto lexer = Atrium::LexicalAnalysis::Lexer(source_file);
	lexer.suppress_output = false;

	Atrium::TokenVector token_vector;

	try {
		token_vector = lexer.tokenize();
	} catch (Atrium::LexicalAnalysis::UnbalancedBracketsException e) {
		std::cout << e.what() << "\n";

		exit(1);
	}

	Atrium::Parser parser(std::move(token_vector), syntax_tree);
	std::cout << parser.parse() << "\n";
	return 0;
}
