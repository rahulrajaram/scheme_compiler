#include "test_helper.h"

bool must_print_success(int argc, char* argv[]) {
	if (argc == 2) {
		if (std::string(argv[1]) == "-v") {
			return true;
		}
	}

	return false;
}

void print_result(
	int test_case_number,
	std::string& example_string,
	bool result,
	bool print_success
)	{
	if (result) {
		if (print_success) {
			std::cout << "\033[1;32m" << test_case_number << ". " << example_string << "\033[0m\n";			
		}
	} else {
		std::cout << "\033[1;31m" << test_case_number << ". " << example_string << "\033[0m\n";
	}
}
