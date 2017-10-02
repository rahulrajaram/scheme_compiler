#include <iostream>

#include "test_helper.h"

int main (int argc, char* argv[]) {
	std::ifstream list_file("../../../config/sample_applications/parser/expressions/sequence");

	std::string line;
	int test_case_number = 0;

	while (getline(list_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(list_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::SyntaxTree* syntax_tree = new Atrium::SyntaxTree();
		Atrium::Parser parser(std::move(token_vector), syntax_tree);

		print_result(++ test_case_number, line, parser.is_sequence(), must_print_success(argc, argv));
	}

	return 0;
}
