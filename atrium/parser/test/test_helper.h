#ifndef ATRIUM_PARSER_TEST_HELPER_H
#define ATRIUM_PARSER_TEST_HELPER_H

#include <vector>

#include "../parser.h"
#include "../../lexer/lexer.h"
#include "../../tokens/token.h"

const static std::string test_set_base = "../../../config/sample_applications/parser/expressions/";

void print_result(
	int test_case_number,
	std::string& example_string,
	bool result
);
#endif