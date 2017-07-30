#include <iostream>

#include "../parser.h"
#include "../../lexer/lexer.h"
#include "../../tokens/token.h"

int main() {
	std::ifstream pattern_identifier_file("../../../config/sample_applications/parser/expressions/pattern_identifier");

	std::string line;

	while (getline(pattern_identifier_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(pattern_identifier_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		std::cout << "Parsing:: " << line << "\n" << parser.is_pattern_identifier() << "\n";
	}

	return 0;
}
