#include <iostream>

#include "test_helper.h"

int main (int argc, char* argv[]) {
	std::ifstream body_file("../../../config/sample_applications/parser/expressions/body");

	std::string line;
	int test_case_number = 0;

	while (getline(body_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(body_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::SyntaxTree* syntax_tree = new Atrium::SyntaxTree();
		Atrium::Parser parser(std::move(token_vector), syntax_tree);
		print_result(++ test_case_number, line, parser.is_body(), must_print_success(argc, argv));
	}

	return 0;
}
