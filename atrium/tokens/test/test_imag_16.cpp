#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_imag_16() {
	std::ifstream imag_16_file("../../../config/production_examples/imag_16_examples");
	std::string line;

	while(getline(imag_16_file, line)) {
		if (Atrium::Token(line).is_imag_16()) {
			std::cout << line << " ... is a imag_16 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a imag_16, but was not found to be --> FAILURE\n";
		}
	}

	imag_16_file.close();
}

int main () {
	test_imag_16();

	return 0;
}
