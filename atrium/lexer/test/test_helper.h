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
			const std::vector <Token>& expected_vector,
			const std::vector <Token>& actual_vector
		);
		void print_test_details ();
	public:
		std::string sample_applications_path; 
		bool test_failed {0};
		int test_number {1};
		std::string source_file;
		std::string test_name;

		// constructor
		TestCase() {
			sample_applications_path = "../../../config/sample_applications/";
		}

		// test run-related methods
		const Atrium::TokenVector load_expected_token_vector (const std::string& tokens_file_path);
		inline void print_colorized_error_message (const std::string&);
		inline void print_colorized_success_message ();
		void run (void (*test_method)());

		// assertion methods
		void assert_vectors_equal(
			const Atrium::TokenVector& expected,
			const Atrium::TokenVector& actual
		);
	};

	
}
