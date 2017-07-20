#include <iostream>
#include <vector>

#include "../token.h"

void test_exponent() {
	std::vector <std::string> sample_exponent_productions {
		"e0", "e1", "e0123", "e234", "e-0", "e-1", "e-0123", "e-234", "e+0", "e+1", "e+0123", "e+234",
		"f0", "f1", "f0123", "f234", "f-0", "f-1", "f-0123", "f-234", "f+0", "f+1", "f+0123", "f+234",
		"d0", "d1", "d0123", "d234", "d-0", "d-1", "d-0123", "d-234", "d+0", "d+1", "d+0123", "d+234",
		"s0", "s1", "s0123", "s234", "s-0", "s-1", "s-0123", "s-234", "s+0", "s+1", "s+0123", "s+234",
		"l0", "l1", "l0123", "l234", "l-0", "l-1", "l-0123", "l-234", "l+0", "l+1", "l+0123", "l+234"
	};
	
	for (auto exponent : sample_exponent_productions) {
		Atrium::Token exponent_token = Atrium::Token(exponent);

		if (exponent_token.is_exponent()) {
			std::cout << exponent << " --> SUCCESS\n";
		} else {
			std::cout << exponent << " --> FAILURE\n";
		}
	}
}

int main () {
	test_exponent();
	return 0;
}
