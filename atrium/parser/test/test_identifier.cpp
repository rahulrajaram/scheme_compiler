#include <iostream>

#include "test_helper.h"

int main (int argc, char* argv[]) {
	std::ifstream identifier_file("../../../config/sample_applications/parser/expressions/identifier");

	std::string line;

	int test_case_number = 0;
	while (getline(identifier_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(identifier_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		print_result(++ test_case_number, line, parser.is_identifier(), must_print_success(argc, argv));
	}

	return 0;
}
