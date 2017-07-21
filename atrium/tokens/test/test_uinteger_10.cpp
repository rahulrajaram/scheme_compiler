#include <iostream>
#include <vector>

#include "../token.h"

void test_uinteger_10() {
	std::vector <std::string> uinteger_10_examples {"0", "1", "12389", "9#", "0####", "8989####"};
	std::vector <std::string> non_uinteger_10_examples {"a", "f", "eff", "g#", "a#", "dd####", ""};

	for (auto exponent : uinteger_10_examples) {
		Atrium::Token uinteger_10_token = Atrium::Token(exponent);

		if (uinteger_10_token.is_uinteger_10()) {
			std::cout << exponent << " ... is a uinteger_10 --> SUCCESS\n";
		} else {
			std::cout << exponent << " ... is a uinteger_10, but was not found to be --> FAILURE\n";
		}
	}

	for (auto exponent : non_uinteger_10_examples) {
		Atrium::Token non_uinteger_10_token = Atrium::Token(exponent);

		if (!(non_uinteger_10_token.is_uinteger_10())) {
			std::cout << exponent << " ... is not uinteger_10 --> SUCCESS\n";
		} else {
			std::cout << exponent << " ... is not a uinteger_10, but was found to be --> FAILURE\n";
		}
	}
}

int main () {
	test_uinteger_10();

	return 0;
}
