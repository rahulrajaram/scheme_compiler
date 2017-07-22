#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_num_2() {
	std::ifstream num_2_file("../../../config/production_examples/num_2_examples");
	std::string line;

	while(getline(num_2_file, line)) {
		if (Atrium::Token(line).is_num_2()) {
			//std::cout << line << " ... is a num_2 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a num_2, but was not found to be --> FAILURE\n";
		}
	}

	num_2_file.close();
}

int main () {
	test_num_2();

	return 0;
}
