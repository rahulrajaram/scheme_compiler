#include <iostream>

#include "test_helper.h"

int main() {
	std::ifstream iteration_spec_file("../../../config/sample_applications/parser/expressions/iteration_spec");

	std::string line;
	int test_case_number = 0;

	while (getline(iteration_spec_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(iteration_spec_file);
		// Atrium::TokenVector token_vector = lexer.tokenize("(case '((a b) (c d)) (((123 . 456)) (((if 123 #t #f)))) (else (((if 123 #t #f)))))\n");
		// Atrium::TokenVector token_vector = lexer.tokenize("(case '((a b) (c d)) (((123 . 456)) (((if 123 #t #f))))\n");
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");

		Atrium::Parser parser(std::move(token_vector));
		print_result(++ test_case_number, line, parser.is_iteration_spec());
	}

	return 0;
}
