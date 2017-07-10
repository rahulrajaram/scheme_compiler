#include <spdlog/spdlog.h>

#include "../../src/lexer/lexer_input.h"
#include "../../src/lexer/lexer.h"
#include "test_helper.h"

Atrium::TestCase test_case;
int test_number = 1;

void print_test_details (const std::string& test_name) {
	std::cout << "\n\n";
	std::cout << "*******************************************************************\n";
	std::cout << "Test " << std::to_string(test_number ++) <<":: ";
	std::cout << test_name + "\n";
	std::cout << "*******************************************************************\n";
}

void test_assertion_violation_scm__expected_and_actual_equal() {
	print_test_details("test_assertion_violation_scm__expected_and_actual_are_equal");

	Atrium::SourceFile source_file("assertion-violation.scm");

	std::vector <std::string> expected {
		"(", "define", "reciprocal", "(", "lambda", 
		"(", "n", ")", "(", "if", "(", "and", "(",
		"number?", "n", ")", "(", "not", "(", "=",
		"n", "0", ")", ")", ")", "(", "/", "1",
		"n", ")", "(", "assertion-violation", "'",
		"reciprocal", "\"improper argument\"", "n",
		")", ")", ")"
	};

	IfStream source_file1("../../config/assertion-violation.scm");
	IfStream lang_spec_file("");
	
	auto lexer_input = Atrium::LexicalAnalysis::LexerInput(
		source_file1,
		lang_spec_file
	);

	SpdlogLogger spdlog_console = spdlog::stdout_color_mt("console");

	auto lexer = Atrium::LexicalAnalysis::Lexer(
		lexer_input
	);

	auto actual_token_vector = lexer.parse(spdlog_console);

	test_case.assert_vectors_equal(
		expected,
		actual_token_vector.token_vector
	);
}

void test_assertion_violation_scm__expected_and_actual_are_not_equal() {
	print_test_details("test_assertion_violation_scm__expected_and_actual_are_not_equal");

	Atrium::SourceFile source_file1("assertion-violation.scm");

	std::vector <std::string> expected {
		"(", "define", "reciprocal", "(", "lambda", 
		"(", "n", ")", "(", "if", "(", "and", "(",
		"number?", "n", ")", "(", "not", "(", "=",
		"n", "0", ")", ")", ")", "(", "/", "1",
		"n", ")", "(", "assertion-violation", "'",
		"reciprocal", "\"improper argument\"", "n",
		")", ")", ")"
	};

	std::vector <std::string> actual {"(", "define", "yolo"};

	test_case.assert_vectors_equal(expected, actual);
}

int main () {
	test_case = Atrium::TestCase();

	test_assertion_violation_scm__expected_and_actual_are_not_equal();
	test_assertion_violation_scm__expected_and_actual_equal();

	return 0;
}
