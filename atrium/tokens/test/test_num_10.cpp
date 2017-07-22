#include <fstream>
#include <iostream>
#include <vector>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include "../token.h"

void test_num_10() {
	boost::filesystem::path num_10_examples_directory("../../../config/production_examples/num_10_examples");
	std::string line;

	for (
		auto& num_10_example_file: boost::make_iterator_range(
			boost::filesystem::directory_iterator(
				num_10_examples_directory
			),
			{}
		)	
	) {
			std::cout << "Processing file :: " << num_10_example_file.path().string() << "\n\n";

			auto example_file = std::ifstream(num_10_example_file.path().string());

			while(getline(example_file, line)) {
				if (Atrium::Token(line).is_num_10()) {
					//std::cout << line << " ... is a num_10 --> SUCCESS\n";
				} else {
					std::cout << line << " ... is a num_10, but was not found to be --> FAILURE\n";
				}
			}

			example_file.close();
	}
}

int main () {
	test_num_10();

	return 0;
}
