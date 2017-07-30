#include "test_helper.h"

void print_result(
	int test_case_number,
	std::string& example_string,
	bool result
)	{
	if (result) {
		std::cout << "\033[1;32m" << test_case_number << ". " << example_string << "\033[0m\n";
	} else {
		std::cout << "\033[1;31m" << test_case_number << ". " << example_string << "\033[0m\n";
	}
}
