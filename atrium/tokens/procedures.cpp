#include "token.h"

namespace Atrium {
	const
	std::unordered_set <std::string>
	Token::procedures = {
		"call-with-current-continuation",
		"call/cc"
	};

	bool Token::is_procedure() {
		return(
			procedures.find(token)
			!= procedures.end()
		);

		return false;
	}
}
