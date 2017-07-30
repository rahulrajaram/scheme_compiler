#include <iostream>

#include "../parser.h"
#include "../../lexer/lexer.h"
#include "../../tokens/token.h"

int main() {
	std::ifstream identifier_file("../../../config/sample_applications/parser/expressions/identifier");

	std::string line;

	while (getline(identifier_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(identifier_file);

		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		std::cout << "Parsing:: " << line << "\n" << parser.is_identifier() << "\n";
	}

	return 0;
}
