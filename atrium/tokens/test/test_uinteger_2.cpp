#include <iostream>
#include <vector>

#include "../token.h"

void test_uinteger_2() {
	std::vector <std::string> uinteger_2_examples {"0", "1", "100", "1#", "0#", "101####"};
	std::vector <std::string> non_uinteger_2_examples {"2", "3", "200", "8#", "9#", "68####", ""};

	for (auto exponent : uinteger_2_examples) {
		Atrium::Token uinteger_2_token = Atrium::Token(exponent);

		if (uinteger_2_token.is_uinteger_2()) {
			std::cout << exponent << " ... is a uinteger_2 --> SUCCESS\n";
		} else {
			std::cout << exponent << " ... is a uinteger_2, but was not found to be --> FAILURE\n";
		}
	}

	for (auto exponent : non_uinteger_2_examples) {
		Atrium::Token non_uinteger_2_token = Atrium::Token(exponent);

		if (!(non_uinteger_2_token.is_uinteger_2())) {
			std::cout << exponent << " ... is not uinteger_2 --> SUCCESS\n";
		} else {
			std::cout << exponent << " ... is not a uinteger_2, but was found to be --> FAILURE\n";
		}
	}
}

int main () {
	test_uinteger_2();

	return 0;
}
