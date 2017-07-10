#include <spdlog/spdlog.h>

#include "../lexer_input.h"
#include "../lexer.h"
#include "test_helper.h"

Atrium::TestCase test_case;

void test_assertion_violation_scm__expected_and_actual_equal() {
	std::vector <std::string> expected {
		"(", "define", "reciprocal", "(", "lambda", 
		"(", "n", ")", "(", "if", "(", "and", "(",
		"number?", "n", ")", "(", "not", "(", "=",
		"n", "0", ")", ")", ")", "(", "/", "1",
		"n", ")", "(", "assertion-violation", "'",
		"reciprocal", "\"improper argument\"", "n",
		")", ")", ")"
	};

	IfStream source_file1("../../../config/assertion-violation.scm");
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

	test_case.test_name = "test_assertion_violation_scm__expected_and_actual_are_equal";
	test_case.source_file = "assertion-violation.scm";
	test_case.run(test_assertion_violation_scm__expected_and_actual_are_not_equal);

	test_case.test_name = "test_assertion_violation_scm__expected_and_actual_equal";
	test_case.source_file = "assertion-violation.scm";
	test_case.run(test_assertion_violation_scm__expected_and_actual_equal);

	return 0;
}
