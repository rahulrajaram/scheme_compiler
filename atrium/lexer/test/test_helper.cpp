#include <exception>
#include <iomanip>
#include <vector>

#include "test_case_exceptions.h"
#include "test_helper.h"

namespace Atrium {
	void TestCase::print_test_details () {
		std::cout << "\n\n";
		std::cout << "*******************************************************************\n";
		std::cout << "Test " << std::to_string(test_number ++) <<":: ";
		std::cout << test_name + "\n";
		std::cout << "*******************************************************************\n";
	}

	void TestCase::run (void (*test_method)()) {
		print_test_details();
		Atrium::SourceFile source_file1(source_file);

		test_method();
	}

	void TestCase::assert_vectors_equal(
		const std::vector<std::string>& expected_vector,
		const std::vector<std::string>& actual_vector
	) {
		try {
			if (expected_vector.size() != actual_vector.size()) {
				throw VectorsNotOfEqualSizeException(
					expected_vector.size(),
					actual_vector.size()
				);
			}
		}	catch (const VectorsNotOfEqualSizeException& e) {
				TestCase::print_colorized_error_message(e.what());
				TestCase::print_vector_difference(expected_vector, actual_vector);

				return;
		}
			
		for (int i = 0; i < expected_vector.size(); i ++) {
			try {
				if (expected_vector.size() != actual_vector.size()) {
					throw VectorsNotOfEqualSizeException(
						static_cast<const int>(expected_vector.size()),
						static_cast<const int>(actual_vector.size())
					);
				} else if (expected_vector[i] != actual_vector[i]) {
					throw VectorsNotEqualException(i);
				}
			}	catch (const VectorsNotEqualException& e) {
				TestCase::print_colorized_error_message(e.what());
				TestCase::print_vector_difference(expected_vector, actual_vector);

				return;
			}
		}
	}

	SourceFile::SourceFile(const std::string&	source_file_name) {
		std::ifstream source_file("../../../config/" + source_file_name);
		Atrium::TestCase test_case;

		try {
			if (!source_file.is_open()) {
				throw SourceFileNotFoundException(source_file_name);
			}
		} catch (const SourceFileNotFoundException& e) {
			test_case.print_colorized_error_message(e.what());

			return;
		}
	}

	// private
	void TestCase::print_vector_difference (
		const std::vector <std::string>& expected_vector,
		const std::vector <std::string>& actual_vector
	) {
		
		std::cout << "----------------------------------";
		std::cout << "----------------------------------\n";
		std::cout << std::setw(40) << " Expected ";
		std::cout << " | ";
		std::cout << " Actual\n";
		std::cout << "----------------------------------";
		std::cout << "----------------------------------\n";
		for (
			int i = 0, j = 0;
			i < expected_vector.size(), j < actual_vector.size();
			i ++, j ++
		) {
			if (i < expected_vector.size()) {
				std::cout << std::setw(40) << expected_vector[i];
			}
			
			std::cout << " | ";

			if (j < expected_vector.size()) {
				std::cout << actual_vector[j];
			}

			std::cout << "\n";
		}
	}

	inline void TestCase::print_colorized_error_message (const std::string& error_message) {
		std::cout <<		
			"\033[1;31m"
				+ error_message
				+ "\033[0m\n";
	}
}
