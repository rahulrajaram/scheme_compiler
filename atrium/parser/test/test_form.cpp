#include <iostream>

#include "test_helper.h"

int main (int argc, char* argv[]) {
	std::ifstream form_file("../../../config/sample_applications/parser/expressions/form");

	std::string line;
	int test_case_number = 0;

	while (getline(form_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(form_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		// Atrium::TokenVector token_vector = lexer.tokenize("(define (=l2_h10$6 lsixo*z~vc:f_&/e9+lyd>0!23r-?j8 . r-bemj) ''())\n");
		Atrium::Parser parser(std::move(token_vector));
		print_result(++ test_case_number, line, parser.is_form(), must_print_success(argc, argv));
	}

	return 0;
}
