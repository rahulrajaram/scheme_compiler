#include <spdlog/spdlog.h>

#include "../../global_aliases.h"

#include "../lexer_input.h"
#include "../lexer.h"
#include "test_helper.h"

Atrium::TestCase test_case;

SpdlogLogger spdlog_console = spdlog::stdout_color_mt("console");

void test_assertion_violation_scm__expected_and_actual_equal() {
	std::vector <std::string> expected =
 		test_case.load_expected_token_vector("../../../config/assertion-violation.tok");

	IfStream source_file("../../../config/assertion-violation.scm");

	auto lexer = Atrium::LexicalAnalysis::Lexer(source_file);

	auto actual_token_vector = lexer.parse(spdlog_console);

	test_case.assert_vectors_equal(
		expected,
		actual_token_vector.token_vector
	);
}

void test_boolean_scm() {
	std::vector <std::string> expected =
 		test_case.load_expected_token_vector("../../../config/boolean.tok");

	IfStream source_file("../../../config/boolean.scm");

	auto lexer = Atrium::LexicalAnalysis::Lexer(source_file);

	auto actual_token_vector = lexer.parse(spdlog_console);

	test_case.assert_vectors_equal(
		expected,
		actual_token_vector.token_vector
	);
}

void test_digits_scm() {
	std::vector <std::string> expected =
 		test_case.load_expected_token_vector("../../../config/digits.tok");

	IfStream source_file("../../../config/digits.scm");


	auto lexer = Atrium::LexicalAnalysis::Lexer(source_file);

	auto actual_token_vector = lexer.parse(spdlog_console);

	test_case.assert_vectors_equal(
		expected,
		actual_token_vector.token_vector
	);
}

void test_fib_scm() {
	std::vector <std::string> expected =
 		test_case.load_expected_token_vector("../../../config/fib.tok");

	IfStream source_file("../../../config/fib.scm");

	auto lexer = Atrium::LexicalAnalysis::Lexer(source_file);

	auto actual_token_vector = lexer.parse(spdlog_console);

	test_case.assert_vectors_equal(
		expected,
		actual_token_vector.token_vector
	);
}

void test_identifier_name_with_question_mark_scm() {
	std::vector <std::string> expected =
 		test_case.load_expected_token_vector("../../../config/identifier_name_with_question_mark.tok");

	IfStream source_file("../../../config/identifier_name_with_question_mark.scm");

	auto lexer = Atrium::LexicalAnalysis::Lexer(source_file);

	auto actual_token_vector = lexer.parse(spdlog_console);

	test_case.assert_vectors_equal(
		expected,
		actual_token_vector.token_vector
	);
}


void test_prog1_scm() {
	std::vector <std::string> expected =
 		test_case.load_expected_token_vector("../../../config/prog1.tok");

	IfStream source_file("../../../config/prog1.scm");


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

	test_case.test_name = "test_boolean_scm";
	test_case.source_file = "boolean.scm";
	test_case.run(test_boolean_scm);

	test_case.test_name = "test_digits_scm";
	test_case.source_file = "digits.scm";
	test_case.run(test_digits_scm);

	test_case.test_name = "test_fib_scm";
	test_case.source_file = "fib.scm";
	test_case.run(test_fib_scm);

	test_case.test_name = "test_identifier_name_with_question_mark_scm";
	test_case.source_file = "identifier_name_with_question_mark.scm";
	test_case.run(test_identifier_name_with_question_mark_scm);

	return 0;
}
