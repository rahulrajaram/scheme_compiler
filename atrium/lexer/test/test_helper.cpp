#include <exception>
#include <iomanip>
#include <vector>

#include "../../tokens/token_vector.h"

#include "test_case_exceptions.h"
#include "test_helper.h"

namespace Atrium {
	void TestCase::print_test_details () {
		std::cout << "\n\n";
		std::cout << "*******************************************************************\n";
		std::cout << "\033[1;34m";
		std::cout << "Test " << std::to_string(test_number ++) <<":: ";
		std::cout << "\033[0m\n";

		std::cout << test_name + "\n";
		std::cout << "*******************************************************************\n";
	}

	void TestCase::run (void (*test_method)()) {
		print_test_details();
		Atrium::SourceFile source_file1(sample_applications_path + source_file + ".scm");

		test_method();

		if (!test_failed) {
			print_colorized_success_message();
		}
		test_failed = false;
	}

	const Atrium::TokenVector TestCase::load_expected_token_vector (
		const std::string& tokens_file_path
	) {
		std::ifstream tokens_file(tokens_file_path);
		Atrium::TokenVector token_vector;
		std::string line;

		while (getline(tokens_file, line)) {
			std::size_t separator = line.find(" --> ");
			std::string token = line.substr(0, separator);
			std::string type = line.substr(separator + 6);

			token_vector.push_back(Token(token, type));
		}

		return token_vector;
	}

	void TestCase::assert_vectors_equal(
		const Atrium::TokenVector& expected_token_vector,
		const Atrium::TokenVector& actual_token_vector
	) {
		const std::vector <Atrium::Token> expected_vector = expected_token_vector.token_vector;
		const std::vector <Atrium::Token> actual_vector = actual_token_vector.token_vector;
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
	
				test_failed = true;
				return;
		}
			
		for (std::size_t i = 0; i < expected_vector.size(); i ++) {
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

				test_failed = true;
				return;
			}
		}
	}

	SourceFile::SourceFile(const std::string&	source_file_name) {
		std::ifstream source_file(source_file_name);
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
		const std::vector <Atrium::Token>& expected_vector,
		const std::vector <Atrium::Token>& actual_vector
	) {
		
		std::cout << "----------------------------------";
		std::cout << "----------------------------------\n";
		std::cout << std::setw(40) << " Expected ";
		std::cout << " | ";
		std::cout << " Actual\n";
		std::cout << "----------------------------------";
		std::cout << "----------------------------------\n";
		for (
			std::size_t i = 0, j = 0;
			i < expected_vector.size(), j < actual_vector.size();
			i ++, j ++
		) {
			if (i < expected_vector.size()) {
				std::cout << std::setw(40) << expected_vector[i].token;
			}
			
			std::cout << " | ";

			if (j < expected_vector.size()) {
				std::cout << actual_vector[j].token;
			}

			if (expected_vector[j] != actual_vector[j]) {
				print_colorized_error_message (" * ");
			}

			std::cout << "\n";
		}
	}

	inline void TestCase::print_colorized_error_message (const std::string& error_message) {
		std::cout << "\033[1;31m" + error_message + "\033[0m\n";
	}

	inline void TestCase::print_colorized_success_message () {
		std::cout << "\033[1;32mSUCCESS !\033[0m\n";
	}
	
	/*inline std::string color_code(const char color) {*/
		//switch(color) {
			//'b' : return "30";
			//'r' : return "31";
			//'g' : return "32";
			//'b' : return "33";
			//'b' : return "34";
			//'m' : return "35";
			//'c' : return "36";
			//'l' : return "37";
		//}
	/*}*/
}
