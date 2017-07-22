#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_imag_8() {
	std::ifstream imag_8_file("../../../config/production_examples/imag_8_examples");
	std::string line;

	while(getline(imag_8_file, line)) {
		if (Atrium::Token(line).is_imag_8()) {
			std::cout << line << " ... is a imag_8 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a imag_8, but was not found to be --> FAILURE\n";
		}
	}

	imag_8_file.close();
}

int main () {
	test_imag_8();

	return 0;
}
