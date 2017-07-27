namespace Atrium {
	bool Parser::is_datum () {
		std::size_t token_vector_index_at_entry = token_vector_index;

		if (current_token_type() == "BOOLEAN") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "NUMBER") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "CHARACTER") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "STRING") {
			token_vector_index ++;
			return true;
		}

		if (current_token_type() == "SYMBOL") {
			token_vector_index ++;
			return true;
		}

		if (is_list ()) {
			return true;
		}

		while (is_vector ()) {
			return true;
		};

		return false;
	}
}
