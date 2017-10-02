#ifndef ATRIUM_PARSER_TEST_HELPER_H
#define ATRIUM_PARSER_TEST_HELPER_H

#include <vector>

#include "../parser.h"
#include "../../lexer/lexer.h"
#include "../../tokens/token.h"
#include "../../syntax_tree/syntax_tree.h"

const static std::string test_set_base = "../../../config/sample_applications/parser/expressions/";

bool must_print_success(int argc, char* argv[]);

void print_result(
	int test_case_number,
	std::string& example_string,
	bool result,
	bool print_result=false
);
#endif
