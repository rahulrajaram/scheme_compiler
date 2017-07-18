namespace Atrium {
	bool Token::is_number () {
		if (is_num_2()) {
			return true;
		}
		if (is_num_8()) {
			return true;
		}
		if (is_num_10()) {
			return true;
		}
		if (is_num_16()) {
			return true;
		}

		return false;
	}
}
