#include <iostream>

#include "../parser.h"
#include "../../lexer/lexer.h"
#include "../../tokens/token.h"

int main() {
	std::ifstream constant_file("../../../config/sample_applications/parser/expressions/constant");

	std::string line;

	while (getline(constant_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(constant_file);

		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		std::cout << "Parsing:: " << line << "\n" << parser.is_constant() << "\n";
	}

	return 0;
}
