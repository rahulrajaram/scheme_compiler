#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_complex_2() {
	std::ifstream complex_2_file("../../../config/production_examples/complex_2_examples");
	std::string line;

	while(getline(complex_2_file, line)) {
		if (Atrium::Token(line).is_complex_2()) {
			std::cout << line << " ... is a complex_2 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a complex_2, but was not found to be --> FAILURE\n";
		}
	}

	complex_2_file.close();
}

int main () {
	test_complex_2();

	return 0;
}
