#include <iostream>

#include "test_helper.h"

int main() {
	std::ifstream body_file("../../../config/sample_applications/parser/expressions/body");

	std::string line;
	int test_case_number = 0;

	while (getline(body_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(body_file);
		// Atrium::TokenVector token_vector = lexer.tokenize("(case '((a b) (c d)) (((123 . 456)) (((if 123 #t #f)))) (else (((if 123 #t #f)))))\n");
		// Atrium::TokenVector token_vector = lexer.tokenize("(delay ((if #f #t 12.123123) ', ()))\n");
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");

		Atrium::Parser parser(std::move(token_vector));
		print_result(++ test_case_number, line, parser.is_body());
	}

	return 0;
}
