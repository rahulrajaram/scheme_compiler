#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_decimal() {
	std::vector <std::string> decimal_examples;
	std::ifstream decimal_examples_file("../../../config/production_examples/decimal_10_examples");
	std::string line = ".9876##l+234";

	while(getline(decimal_examples_file, line)) {
		if (Atrium::Token(line).is_decimal_10()) {
			std::cout << line << " ... is a decimal --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a decimal, but was not found to be --> FAILURE\n";
		}
	}

	decimal_examples_file.close();
}

int main () {
	test_decimal();

	return 0;
}
