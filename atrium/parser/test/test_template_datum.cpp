#include <iostream>

#include "test_helper.h"

int main() {
	std::ifstream template_datum_file("../../../config/sample_applications/parser/expressions/template_datum");

	std::string line;
	int test_case_number = 0;

	while (getline(template_datum_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(template_datum_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		print_result(++ test_case_number, line, parser.is_template_datum());
	}

	return 0;
}
