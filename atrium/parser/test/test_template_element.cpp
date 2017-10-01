#include <iostream>

#include "test_helper.h"

int main (int argc, char* argv[]) {
	std::ifstream template_element_file("../../../config/sample_applications/parser/expressions/template_element");

	std::string line;
	int test_case_number = 0;

	while (getline(template_element_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(template_element_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		print_result(++ test_case_number, line, parser.is_template_element(), must_print_success(argc, argv));
	}

	return 0;
}
