#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_complex_8() {
	std::ifstream complex_8_file("../../../config/production_examples/complex_8_examples");
	std::string line;

	while(getline(complex_8_file, line)) {
		if (Atrium::Token(line).is_complex_8()) {
			std::cout << line << " ... is a complex_8 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a complex_8, but was not found to be --> FAILURE\n";
		}
	}

	complex_8_file.close();
}

int main () {
	test_complex_8();

	return 0;
}
