#ifndef ATRIUM_TOKEN_H
#define ATRIUM_TOKEN_H

namespace Atrium {
	class Token {
	public:
		std::string token;
		std::string type;

		Token(
			const std::string& token,
			const std::string& type
		) : token { token }, type { type }
				{ }

		inline bool operator!=(const Token& other_token) const {
			return (
				token != other_token.token
			);
		}
	};
}
#endif
