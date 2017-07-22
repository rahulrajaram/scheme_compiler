#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_ureal_2() {
	std::ifstream ureal_2_file("../../../config/production_examples/ureal_2_examples");
	std::string line;

	while(getline(ureal_2_file, line)) {
		if (Atrium::Token(line).is_ureal_2()) {
			std::cout << line << " ... is a ureal_2 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a ureal_2, but was not found to be --> FAILURE\n";
		}
	}

	ureal_2_file.close();
}

int main () {
	test_ureal_2();

	return 0;
}
