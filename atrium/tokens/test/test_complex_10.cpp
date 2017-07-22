#include <fstream>
#include <iostream>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include "../token.h"

void test_complex_10() {
	boost::filesystem::path complex_10_examples_directory("../../../config/production_examples/complex_10_examples");
	std::string line;

	for (
		auto& complex_10_example_file: boost::make_iterator_range(
			boost::filesystem::directory_iterator(
				complex_10_examples_directory
			),
			{}
		)	
	) {
			std::cout << "Processing file :: " << complex_10_example_file.path().string() << "\n\n";

			auto example_file = std::ifstream(complex_10_example_file.path().string());

			while(getline(example_file, line)) {
				if (Atrium::Token(line).is_complex_10()) {
					//std::cout << line << " ... is a complex_10 --> SUCCESS\n";
				} else {
					std::cout << line << " ... is a complex_10, but was not found to be --> FAILURE\n";
				}
			}

			example_file.close();
	}
}

int main () {
	test_complex_10();

	return 0;
}
