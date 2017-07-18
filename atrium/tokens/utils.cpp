namespace Atrium {
	bool Token::starts_with_prefix(const std::string& prefix) {
		if (prefix.length() > token.length()) {
			return false;
		}

		return (token.substr(0, prefix.length()) == prefix);
	}

	bool Token::ends_with_suffix(const std::string& suffix) {
		if (suffix.length() > token.length()) {
			return false;
		}

		return (token.substr(token.length() - suffix.length()) == suffix);
	}

	std::pair<Token, Token>
	Token::split_around_pivot(
		const std::string& pivot,
		bool include_split_point=false
	) {
		std::size_t split_location = token.find(pivot);

		// Return original token as the only string
		if (split_location == std::string::npos) {
			return std::pair(Token(token), Token(""));
		}

		if ((split_location + pivot.length()) == token.length()) {
			return std::pair(Token(token), Token(""));
		}

		Token first_part_1 = Token(token.substr(0, split_location));
		Token second_part_1 = Token(token.substr(split_location + 1)); 

		return std::pair(first_part_1, second_part_1);
	}
}
