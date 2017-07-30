#include <iostream>

#include "test_helper.h"

int main() {
	std::ifstream datum_file(test_set_base + "datum");

	std::string line;
	int test_case_number = 0;

	while (getline(datum_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(datum_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		print_result(++ test_case_number, line, parser.is_datum());
	}

	return 0;
}
