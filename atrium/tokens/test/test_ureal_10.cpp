#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_ureal_10() {
	std::ifstream ureal_10_file("../../../config/production_examples/ureal_10_examples");
	std::string line;

	while(getline(ureal_10_file, line)) {
		if (Atrium::Token(line).is_ureal_10()) {
			std::cout << line << " ... is a ureal_10 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a ureal_10, but was not found to be --> FAILURE\n";
		}
	}

	ureal_10_file.close();
}

int main () {
	test_ureal_10();

	return 0;
}
