#include <iostream>

#include "../parser.h"
#include "../../lexer/lexer.h"
#include "../../tokens/token.h"

int main() {
	std::ifstream list_file("../../../config/sample_applications/parser/expressions/list");

	std::string line;

	while (getline(list_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(list_file);

		Atrium::TokenVector token_vector = lexer.tokenize(line);
		Atrium::Parser parser(std::move(token_vector));

		std::cout << "Parsing:: " << line << "\n" << parser.parse() << "\n";
	}

	return 0;
}
