#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_real_2() {
	std::ifstream real_2_file("../../../config/production_examples/real_2_examples");
	std::string line;

	while(getline(real_2_file, line)) {
		if (Atrium::Token(line).is_real_2()) {
			std::cout << line << " ... is a real_2 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a real_2, but was not found to be --> FAILURE\n";
		}
	}

	real_2_file.close();
}

int main () {
	test_real_2();

	return 0;
}
