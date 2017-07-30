#include <iostream>

#include "../parser.h"
#include "../../lexer/lexer.h"
#include "../../tokens/token.h"

int main() {
	std::ifstream expression_file("../../../config/sample_applications/parser/expressions/expression");

	std::string line;

	while (getline(expression_file, line)) {
		if (line.empty() || line[0] == ';') {
			continue;
		}

		Atrium::LexicalAnalysis::Lexer lexer(expression_file);

		Atrium::TokenVector token_vector = lexer.tokenize(line);
		Atrium::Parser parser(std::move(token_vector));

		std::cout << "Parsing:: " << line << "\n" << parser.is_expression() << "\n";
	}

	return 0;
}
