#include "test_helper.h"

void test_assertion_violation_sc__expected_and_actual_are_equal(
		Atrium::TestCase& test_case,
		const int test_number
) {

	std::cout << "\n\n";
	std::cout << "*******************************************************************\n";
	std::cout << "Test " << std::to_string(test_number) <<":: ";
	std::cout << "test_assertion_violation_sc__expected_and_actual_are_equal\n";
	std::cout << "*******************************************************************\n";

	Atrium::SourceFile source_file1("../../config/identifier_name_with_question_mark.sc");

	std::vector <std::string> expected {
		"(", "define", "reciprocal", "(", "lambda", 
		"(", "n", ")", "(", "if", "(", "and", "(",
		"number?", "n", ")", "(", "not", "(", "=",
		"n", "0", ")", ")", ")", "(", "/    ", "1",
		"n", ")", "(", "assertion-violation", "'",
		"reciprocal", "\"improper argument\"", "n",
		")", ")", ")"
	};

	std::vector <std::string> actual {"(", "define", "yolo"};

	test_case.assert_vectors_equal(expected, actual);
}

int main () {
	Atrium::TestCase test_case = Atrium::TestCase();

	test_assertion_violation_sc__expected_and_actual_are_equal(test_case, 1);

	return 0;
}
