#include <unordered_set>

#include "token.h"

namespace Atrium {
	const
	std::unordered_set <std::string>
	Token::syntactic_keywords = {
		"access",
		"define-syntax",
		"macro",
		"and",
		"delay",
		"make-environment",
		"begin",
		"do",
		"named-lambda",
		"bkpt",
		"fluid-let",
		"or",
		"case",
		"if",
		"quasiquote",
		"cond",
		"in-package",
		"quote",
		"cons-stream",
		"lambda",
		"scode-quote",
		"declare",
		"let",
		"sequence",
		"default-object?",
		"let*",
		"set!",
		"define",
		"let-syntax",
		"the-environment",
		"define-integrable",
		"letrec",
		"unassigned?",
		"define-macro",
		"local-declare",
		"using-syntax",
		"define-structure"
	};

	bool Token::is_syntactic_keyword () {
		return syntactic_keywords.find(token) != syntactic_keywords.end();
	}
}
