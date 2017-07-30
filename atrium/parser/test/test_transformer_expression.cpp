#include <iostream>

#include "test_helper.h"

int main() {
	std::ifstream transformer_expression_file("../../../config/sample_applications/parser/expressions/transformer_expression");

	std::string line;
	int test_case_number = 0;

	while (getline(transformer_expression_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(transformer_expression_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		print_result(++ test_case_number, line, parser.is_transformer_expression());
	}

	return 0;
}
