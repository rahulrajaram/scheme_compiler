#include <iostream>
#include <exception>
#include <fstream>
#include <vector>

#include "test_case_exceptions.h"

namespace Atrium {
	class SourceFile {
		std::string source_file_name;
	public:
		SourceFile(const std::string&	source_file_name);
	};

	class TestCase {
		void print_vector_difference (
			const std::vector <std::string>& expected_vector,
			const std::vector <std::string>& actual_vector
		);
		void print_test_details ();
	public:
		int test_number {1};
		std::string source_file;
		std::string test_name;

		// test run-related methods
		inline void print_colorized_error_message (const std::string&);
		void run (void (*test_method)());

		// assertion methods
		void assert_vectors_equal(
			const std::vector<std::string>& expected,
			const std::vector<std::string>& actual
		);
	};

	
}
