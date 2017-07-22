#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_ureal_8() {
	std::ifstream ureal_8_file("../../../config/production_examples/ureal_8_examples");
	std::string line;

	while(getline(ureal_8_file, line)) {
		if (Atrium::Token(line).is_ureal_8()) {
			std::cout << line << " ... is a ureal_8 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a ureal_8, but was not found to be --> FAILURE\n";
		}
	}

	ureal_8_file.close();
}

int main () {
	test_ureal_8();

	return 0;
}
