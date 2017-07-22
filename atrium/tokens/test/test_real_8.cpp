#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_real_8() {
	std::ifstream real_8_file("../../../config/production_examples/real_8_examples");
	std::string line;

	while(getline(real_8_file, line)) {
		if (Atrium::Token(line).is_real_8()) {
			std::cout << line << " ... is a real_8 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a real_8, but was not found to be --> FAILURE\n";
		}
	}

	real_8_file.close();
}

int main () {
	test_real_8();

	return 0;
}
