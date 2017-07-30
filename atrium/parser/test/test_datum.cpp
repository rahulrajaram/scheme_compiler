#include <iostream>

#include "../parser.h"
#include "../../lexer/lexer.h"
#include "../../tokens/token.h"

int main() {
	std::ifstream datum_file("../../../config/sample_applications/parser/expressions/datum");

	std::string line;

	while (getline(datum_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(datum_file);
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));

		std::cout << "\n\nParsing:: " << line << "\n" << parser.is_datum() << "\n";
	}

	return 0;
}
