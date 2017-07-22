#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_real_16() {
	std::ifstream real_16_file("../../../config/production_examples/real_16_examples");
	std::string line;

	while(getline(real_16_file, line)) {
		if (Atrium::Token(line).is_real_16()) {
			std::cout << line << " ... is a real_16 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a real_16, but was not found to be --> FAILURE\n";
		}
	}

	real_16_file.close();
}

int main () {
	test_real_16();

	return 0;
}
