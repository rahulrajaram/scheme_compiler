#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_imag_10() {
	std::ifstream imag_10_file("../../../config/production_examples/imag_10_examples");
	std::string line;

	while(getline(imag_10_file, line)) {
		if (Atrium::Token(line).is_imag_10()) {
			std::cout << line << " ... is a imag_10 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a imag_10, but was not found to be --> FAILURE\n";
		}
	}

	imag_10_file.close();
}

int main () {
	test_imag_10();

	return 0;
}
