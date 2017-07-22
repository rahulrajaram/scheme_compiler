#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_num_8() {
	std::ifstream num_8_file("../../../config/production_examples/num_8_examples");
	std::string line;

	while(getline(num_8_file, line)) {
		if (Atrium::Token(line).is_num_8()) {
			std::cout << line << " ... is a num_8 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a num_8, but was not found to be --> FAILURE\n";
		}
	}

	num_8_file.close();
}

int main () {
	test_num_8();

	return 0;
}
