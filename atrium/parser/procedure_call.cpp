#include "parser.h"

namespace Atrium {
	// <procedure call> --> (<operator> <operand>*)
	bool Parser::is_procedure_call() {
		std::size_t token_vector_index_at_entry = token_vector_index;

		std::cout << "start \n";
		if (!is_left_paren()) {
			return false;
		}
		std::cout << "okay (\n";
		if (!is_operator()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		std::cout << "okay operator\n";
		while (is_operand());

		std::cout << "okay operand\n";
		if(!is_right_paren()) {
			token_vector_index = token_vector_index_at_entry;
			return false;
		}

		std::cout << "okay right paren\n";
		return true;
	}
}
