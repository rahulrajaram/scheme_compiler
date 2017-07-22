#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_imag_2() {
	std::ifstream imag_2_file("../../../config/production_examples/imag_2_examples");
	std::string line;

	while(getline(imag_2_file, line)) {
		if (Atrium::Token(line).is_imag_2()) {
			std::cout << line << " ... is a imag_2 --> SUCCESS\n";
		} else {
			std::cout << line << " ... is a imag_2, but was not found to be --> FAILURE\n";
		}
	}

	imag_2_file.close();
}

int main () {
	test_imag_2();

	return 0;
}
