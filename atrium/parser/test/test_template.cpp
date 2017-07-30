#include <iostream>

#include "test_helper.h"

int main() {
	std::ifstream template_file("../../../config/sample_applications/parser/expressions/template");

	std::string line;
	int test_case_number = 0;

	while (getline(template_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(template_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		print_result(++ test_case_number, line, parser.is_template());
	}

	return 0;
}
