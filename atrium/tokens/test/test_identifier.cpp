#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_identifier() {
	std::ifstream identifier_examples_file("../../../config/production_examples/identifier_examples");
	std::string line;

	while(getline(identifier_examples_file, line)) {
		if (Atrium::Token(line).is_identifier()) {
			std::cout << line << " ... is a identifier --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a identifier, but was not found to be --> FAILURE\n";
		}
	}

	identifier_examples_file.close();
}

int main () {
	test_identifier();

	return 0;
}
