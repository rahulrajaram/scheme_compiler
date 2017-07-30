#include <iostream>

#include "../parser.h"
#include "../../lexer/lexer.h"
#include "../../tokens/token.h"

int main() {
	std::ifstream formals_file("../../../config/sample_applications/parser/expressions/formals");

	std::string line;

	while (getline(formals_file, line)) {
		Atrium::LexicalAnalysis::Lexer lexer(formals_file);
		lexer.suppress_output = false;
		Atrium::TokenVector token_vector = lexer.tokenize(line + "\n");
		Atrium::Parser parser(std::move(token_vector));
		parser.suppress_output = false;
		std::cout << "Parsing:: " << line << "\n" << parser.is_formals() << "\n";
	}

	return 0;
}
