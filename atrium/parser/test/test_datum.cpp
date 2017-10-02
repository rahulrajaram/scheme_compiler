#include <iostream>

#include "test_helper.h"

int main (int argc, char* argv[]) {
	std::ifstream datum_file(test_set_base + "datum");

	std::string line;
	int test_case_number = 0;

	while (getline(datum_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(datum_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::SyntaxTree* syntax_tree = new Atrium::SyntaxTree();
		Atrium::Parser parser(std::move(token_vector), syntax_tree);

		print_result(++ test_case_number, line, parser.is_datum(), must_print_success(argc, argv));
	}

	return 0;
}
