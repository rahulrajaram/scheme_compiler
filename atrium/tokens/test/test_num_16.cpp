#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_num_16() {
	std::ifstream num_16_file("../../../config/production_examples/num_16_examples");
	std::string line;

	while(getline(num_16_file, line)) {
		if (Atrium::Token(line).is_num_16()) {
			std::cout << line << " ... is a num_16 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a num_16, but was not found to be --> FAILURE\n";
		}
	}

	num_16_file.close();
}

int main () {
	test_num_16();

	return 0;
}
