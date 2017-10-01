#include <iostream>

#include "test_helper.h"

int main (int argc, char* argv[]) {
	std::ifstream pattern_identifier_file("../../../config/sample_applications/parser/expressions/pattern_identifier");

	std::string line;
	int test_case_number = 0;

	while (getline(pattern_identifier_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(pattern_identifier_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		print_result(++ test_case_number, line, parser.is_pattern_identifier(), must_print_success(argc, argv));
	}

	return 0;
}
