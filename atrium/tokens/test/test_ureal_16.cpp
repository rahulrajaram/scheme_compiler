#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_ureal_16() {
	std::ifstream ureal_16_file("../../../config/production_examples/ureal_16_examples");
	std::string line;

	while(getline(ureal_16_file, line)) {
		if (Atrium::Token(line).is_ureal_16()) {
			std::cout << line << " ... is a ureal_16 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a ureal_16, but was not found to be --> FAILURE\n";
		}
	}

	ureal_16_file.close();
}

int main () {
	test_ureal_16();

	return 0;
}
