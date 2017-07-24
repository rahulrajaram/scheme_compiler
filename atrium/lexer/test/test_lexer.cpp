#include <spdlog/spdlog.h>

#include "../../global_aliases.h"

#include "../lexer_input.h"
#include "../lexer.h"
#include "test_helper.h"

Atrium::TestCase test_case;

SpdlogLogger spdlog_console = spdlog::stdout_color_mt("console");

using SVector = std::vector <std::string>;

Atrium::TokenVector actual_token_vector() {
	IfStream source_file(test_case.sample_applications_path + test_case.source_file + ".scm");

	auto lexer = Atrium::LexicalAnalysis::Lexer(source_file, spdlog_console);

	return lexer.tokenize();
}

Atrium::TokenVector expected_token_vector() {
	const std::string& test_source_path =	test_case.sample_applications_path + test_case.source_file + ".tok";

 	return test_case.load_expected_token_vector(test_source_path);
}

void test_assertion_violation_scm__expected_and_actual_equal() {
	test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
}

void test_boolean_scm() {
	test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
}

void test_digits_scm() {
	test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
}

void test_fib_scm() {
	test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
}

void test_identifier_name_with_question_mark_scm() {
	test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
}

void test_prog1_scm() {
	test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
}

void test_unbalanced_brackets_scm() {
	try {
		test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
	} catch (const Atrium::LexicalAnalysis::UnbalancedBracketsException& e) {
		std::cout << e.what() << "\n";
	}
}

void test_unbalanced_brackets_1_scm() {
	try {
		test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
	} catch (const Atrium::LexicalAnalysis::UnbalancedBracketsException& e) {
		std::cout << e.what() << "\n";
	}
}

void test_letrec_scm() {
		test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
}

void test_call_cc_scm() {
		test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
}

void test_vector_scm() {
		test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
}

void test_non_printing_character() {
		test_case.assert_vectors_equal(expected_token_vector(), actual_token_vector());
}

int main () {
	test_case = Atrium::TestCase();

 /* test_case.test_name = "test_assertion_violation_scm__expected_and_actual_are_equal";*/
	//test_case.source_file = "assertion-violation";
	//test_case.run(test_assertion_violation_scm__expected_and_actual_are_not_equal);

	test_case.test_name = "test_assertion_violation_scm__expected_and_actual_equal";
	test_case.source_file = "assertion-violation";
	test_case.run(test_assertion_violation_scm__expected_and_actual_equal);

	test_case.test_name = "test_boolean_scm";
	test_case.source_file = "boolean";
	test_case.run(test_boolean_scm);

	test_case.test_name = "test_digits_scm";
	test_case.source_file = "digits";
	test_case.run(test_digits_scm);

	test_case.test_name = "test_fib_scm";
	test_case.source_file = "fib";
	test_case.run(test_fib_scm);

	test_case.test_name = "test_identifier_name_with_question_mark_scm";
	test_case.source_file = "identifier_name_with_question_mark";
	test_case.run(test_identifier_name_with_question_mark_scm);

	test_case.test_name = "test_unbalanced_brackets_scm";
	test_case.source_file = "unbalanced_brackets";
	test_case.run(test_unbalanced_brackets_scm);

	test_case.test_name = "test_unbalanced_brackets_1_scm";
	test_case.source_file = "unbalanced_brackets_1";
	test_case.run(test_unbalanced_brackets_1_scm);

	test_case.test_name = "test_letrec_scm";
	test_case.source_file = "letrec";
	test_case.run(test_letrec_scm);

	test_case.test_name = "test_call_cc_scm";
	test_case.source_file = "call_cc";
	test_case.run(test_call_cc_scm);

	test_case.test_name = "test_vector_scm";
	test_case.source_file = "vector";
	test_case.run(test_vector_scm);

	test_case.test_name = "test_non_printing_character";
	test_case.source_file = "non_printing_character";
	test_case.run(test_non_printing_character);

	return 0;
}
