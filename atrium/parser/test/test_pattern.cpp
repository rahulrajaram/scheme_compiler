#include <iostream>

#include "test_helper.h"

int main() {
	std::ifstream pattern_file("../../../config/sample_applications/parser/expressions/pattern");

	std::string line;
	int test_case_number = 0;

	while (getline(pattern_file, line)) {
 /*   if (line != "(+ ...)") {*/
			//continue;
		/*}*/
		Atrium::LexicalAnalysis::Lexer lexer(pattern_file);
		//lexer.suppress_output = false;
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));
		//parser.suppress_output = false;

		print_result(++ test_case_number, line, parser.is_pattern());
	}

	return 0;
}
