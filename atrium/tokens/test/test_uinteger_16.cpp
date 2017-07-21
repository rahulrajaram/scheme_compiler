#include <iostream>
#include <vector>

#include "../token.h"

void test_uinteger_16() {
	std::vector <std::string> uinteger_16_examples {"0", "1", "12ef", "f#", "0####", "efef####"};
	std::vector <std::string> non_uinteger_16_examples {"g", "h", "lll", "6g#", "8888888888888888888888888r#", "999ooooaaaaaaaaa-qe####", ""};

	for (auto exponent : uinteger_16_examples) {
		Atrium::Token uinteger_16_token = Atrium::Token(exponent);

		if (uinteger_16_token.is_uinteger_16()) {
			std::cout << exponent << " ... is a uinteger_16 --> SUCCESS\n";
		} else {
			std::cout << exponent << " ... is a uinteger_16, but was not found to be --> FAILURE\n";
		}
	}

	for (auto exponent : non_uinteger_16_examples) {
		Atrium::Token non_uinteger_16_token = Atrium::Token(exponent);

		if (!(non_uinteger_16_token.is_uinteger_16())) {
			std::cout << exponent << " ... is not uinteger_16 --> SUCCESS\n";
		} else {
			std::cout << exponent << " ... is not a uinteger_16, but was found to be --> FAILURE\n";
		}
	}
}

int main () {
	test_uinteger_16();

	return 0;
}
