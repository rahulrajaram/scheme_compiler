#include <iostream>

#include "test_helper.h"

int main (int argc, char* argv[]) {
	std::ifstream syntax_rule_file("../../../config/sample_applications/parser/expressions/syntax_rule");

	std::string line;
	int test_case_number = 0;

	while (getline(syntax_rule_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(syntax_rule_file);

		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		print_result(++ test_case_number, line, parser.is_syntax_rule(), must_print_success(argc, argv));
	}

	return 0;
}
