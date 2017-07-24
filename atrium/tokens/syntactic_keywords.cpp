#include <unordered_set>

#include "token.h"

namespace Atrium {
	const
	std::unordered_set <std::string>
	Token::syntactic_keywords = {
		"access",
		"and",
		"begin",
		"bkpt",
		"case",
		"cond",
		"cons-stream",
		"declare",
		"default-object?",
		"define",
		"define-integrable",
		"define-macro",
		"define-structure"
		"define-syntax",
		"delay",
		"do",
		"fluid-let",
		"if",
		"in-package",
		"lambda",
		"let",
		"let*",
		"let-syntax",
		"letrec",
		"local-declare",
		"macro",
		"make-environment",
		"named-lambda",
		"or",
		"quasiquote",
		"quote",
		"scode-quote",
		"sequence",
		"set!",
		"the-environment",
		"unassigned?",
		"using-syntax",
	};

	bool Token::is_syntactic_keyword () {
		return syntactic_keywords.find(token) != syntactic_keywords.end();
	}
}
