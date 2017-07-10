#include <spdlog/spdlog.h>

#include "../lexer_input.h"
#include "../lexer.h"
#include "test_helper.h"

Atrium::TestCase test_case;

void test_assertion_violation_scm__expected_and_actual_equal() {
	std::vector <std::string> expected =
 		test_case.load_expected_token_vector("../../../config/assertion-violation.tok");

	IfStream source_file("../../../config/assertion-violation.scm");

	SpdlogLogger spdlog_console = spdlog::stdout_color_mt("console");

	auto lexer = Atrium::LexicalAnalysis::Lexer(source_file);

	auto actual_token_vector = lexer.parse(spdlog_console);

	test_case.assert_vectors_equal(
		expected,
		actual_token_vector.token_vector
	);
}

void test_assertion_violation_scm__expected_and_actual_are_not_equal() {
	std::vector <std::string> expected =
 		test_case.load_expected_token_vector("../../../config/assertion-violation.tok");

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
