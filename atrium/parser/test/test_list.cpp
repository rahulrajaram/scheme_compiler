#include <iostream>

#include "test_helper.h"

int main (int argc, char* argv[]) {
	std::ifstream list_file("../../../config/sample_applications/parser/expressions/list");

	std::string line;
	int test_case_number = 0;

	while (getline(list_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(list_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::SyntaxTree* syntax_tree = new Atrium::SyntaxTree();
		Atrium::Parser parser(std::move(token_vector), syntax_tree);

		print_result(++ test_case_number, line, parser.is_list(), argc == 1 ? (argv[0] == "-p" ? true : false) : false);
	}

	return 0;
}
