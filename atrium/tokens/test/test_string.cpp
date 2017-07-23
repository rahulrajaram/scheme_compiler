#include <fstream>
#include <iostream>
#include <vector>

#include "../token.h"

void test_string() {
	std::string line;

	std::ifstream illegitimate_strings_file("../../../config/production_examples/strings_examples__illegitimate");
	while(getline(illegitimate_strings_file, line)) {
		if (!Atrium::Token(line).is_string()) {
		} else {
			std::cout << line << " is an illegitimate string, but was not found to be one. \n";
		}
	}
	illegitimate_strings_file.close();

	std::ifstream legitimate_strings_file("../../../config/production_examples/strings_examples__legitimate");
	while(getline(legitimate_strings_file, line)) {
		if (Atrium::Token(line).is_string()) {
		} else {
			std::cout << line << " is a legitimate string, but was not found to be one. \n";
		}
	}
	legitimate_strings_file.close();

}

int main () {
	test_string();

	return 0;
}
