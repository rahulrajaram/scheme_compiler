#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_complex_16() {
	std::ifstream complex_16_file("../../../config/production_examples/complex_16_examples");
	std::string line;

	while(getline(complex_16_file, line)) {
		if (Atrium::Token(line).is_complex_16()) {
			std::cout << line << " ... is a complex_16 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a complex_16, but was not found to be --> FAILURE\n";
		}
	}

	complex_16_file.close();
}

int main () {
	test_complex_16();

	return 0;
}
