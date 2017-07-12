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
		bool test_failed {0};
		int test_number {1};
		std::string source_file;
		std::string test_name;

		// test run-related methods
		const Atrium::LexicalAnalysis::TokenVector load_expected_token_vector (const std::string& tokens_file_path);
		inline void print_colorized_error_message (const std::string&);
		inline void print_colorized_success_message ();
		void run (void (*test_method)());

		// assertion methods
		void assert_vectors_equal(
			const Atrium::LexicalAnalysis::TokenVector& expected,
			const Atrium::LexicalAnalysis::TokenVector& actual
		);
	};

	
}
