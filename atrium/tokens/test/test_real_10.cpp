#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_real_10() {
	std::ifstream real_10_file("../../../config/production_examples/real_10_examples");
	std::string line;

	while(getline(real_10_file, line)) {
		if (Atrium::Token(line).is_real_10()) {
			std::cout << line << " ... is a real_10 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a real_10, but was not found to be --> FAILURE\n";
		}
	}

	real_10_file.close();
}

int main () {
	test_real_10();

	return 0;
}
