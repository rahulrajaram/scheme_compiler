namespace Atrium {
	bool Token::is_number() {
		if (is_num2()) {
			return true;
		}
		if (is_num8()) {
			return true;
		}
		if (is_num10()) {
			return true;
		}
		if (is_num16()) {
			return true;
		}
	}
}
