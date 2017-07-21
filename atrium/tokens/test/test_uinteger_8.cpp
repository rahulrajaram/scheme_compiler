#include <iostream>
#include <vector>

#include "../token.h"

void test_uinteger_8() {
	std::vector <std::string> uinteger_8_examples {"0", "1", "1123", "7#", "0#", "6767####"};
	std::vector <std::string> non_uinteger_8_examples {"9", "8", "9876", "abs#", "", "8989####", "####"};

	for (auto exponent : uinteger_8_examples) {
		Atrium::Token uinteger_8_token = Atrium::Token(exponent);

		if (uinteger_8_token.is_uinteger_8()) {
			std::cout << exponent << " ... is a uinteger_8 --> SUCCESS\n";
		} else {
			std::cout << exponent << " ... is a uinteger_8, but was not found to be --> FAILURE\n";
		}
	}

	for (auto exponent : non_uinteger_8_examples) {
		Atrium::Token non_uinteger_8_token = Atrium::Token(exponent);

		if (!(non_uinteger_8_token.is_uinteger_8())) {
			std::cout << exponent << " ... is not uinteger_8 --> SUCCESS\n";
		} else {
			std::cout << exponent << " ... is not a uinteger_8, but was found to be --> FAILURE\n";
		}
	}
}

int main () {
	test_uinteger_8();

	return 0;
}
