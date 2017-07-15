#include "parser.h"

namespace Atrium {
	namespace Parsing {
		bool Parser::parse() {
			spdlog_console->info("... Begin parsing");
		
			int token_vector_index = 0;
			return program(token_vector_index);
		}
		
		bool Parser::program(int& token_vector_index) {
			while(token_vector_index < token_vector.size()) {
				int saved_token_vector_index = token_vector_index;

				if (!form(token_vector_index)) {
					token_vector_index = saved_token_vector_index;
					break;
				}
			}

			if (token_vector_index < token_vector.size()) {
				return false;
			}

			return true;
		}

		bool Parser::form(int& token_vector_index) {
			int saved_token_vector_index = token_vector_index;
			if (definition(token_vector_index)) {
				return true;
			}

			token_vector_index = saved_token_vector_index;
			saved_token_vector_index = token_vector_index;
			if (expression(token_vector_index)) {
				return true;
			}
			token_vector_index = saved_token_vector_index;
			return false;
		}

		bool Parser::definition(int token_vector_index) {
			int saved_token_vector_index = token_vector_index;
			if (syntax_definition(token_vector_index)) {
				return true;
			}

			token_vector_index = saved_token_vector_index;
			saved_token_vector_index = token_vector_index;
			if (syntax_definition(token_vector_index)) {
				return true;
			}

			token_vector_index = saved_token_vector_index;
			saved_token_vector_index = token_vector_index;
			if (derived_definition(token_vector_index)) {
				return true;
			}

			token_vector_index = saved_token_vector_index;
			saved_token_vector_index = token_vector_index;
			if (token_vector[token_vector_index] == "(") {
				token_vector_index ++;
				if (token_vector[token_vector_index] == "begin") {
					token_vector_index ++;
					while(token_vector_index < token_vector.size()) {
						int saved_token_vector_index_inner = token_vector_index;
						if (!definition(token_vector_index)) {
							token_vector_index = saved_token_vector_index_inner;

							if (token_vector_index == saved_token_vector_index + 2) {
								token_vector_index = saved_token_vector_index;
							}
							break;
						}
					}
					
					if (token_vector_index > saved_token_vector_index) {
						return true;
					}
				}
			}

			token_vector_index = saved_token_vector_index;
			saved_token_vector_index = token_vector_index;
			if (token_vector[token_vector_index] == "(") {
				token_vector_index ++;
				if (token_vector[token_vector_index] == "let-syntax") {
					token_vector_index ++;
					if (token_vector[token_vector_index] == "(") {
						token_vector_index ++;
						while(token_vector_index < token_vector.size()) {
							int saved_token_vector_index_inner = token_vector_index;
							if (!syntax_binding(token_vector_index)) {
								token_vector_index = saved_token_vector_index_inner;
								if (token_vector_index == saved_token_vector_index + 3) {
									token_vector_index = saved_token_vector_index;
								}
								break;
							}
						}
						if (token_vector[token_vector_index] == ")") {
							token_vector_index ++;
							while(token_vector_index < token_vector.size()) {
								int saved_token_vector_index_inner = token_vector_index;
								if (!definition(token_vector_index)) {
									token_vector_index = saved_token_vector_index_inner;
									if (token_vector_index == saved_token_vector_index + 3) {
										token_vector_index = saved_token_vector_index;
									}
									break;
								}
							}
							if (token_vector[token_vector_index] == ")") {
								return true;
							} else {
								token_vector_index = saved_token_vector_index;
							}
						} else {
							token_vector_index = saved_token_vector_index;
						}
					} else {
						token_vector_index = saved_token_vector_index;
					}
				} 
				if (token_vector[token_vector_index] == "letrec-syntax") {
					token_vector_index ++;
					if (token_vector[token_vector_index] == "(") {
						token_vector_index ++;
						while(token_vector_index < token_vector.size()) {
							int saved_token_vector_index_inner = token_vector_index;
							if (!syntax_binding(token_vector_index)) {
								token_vector_index = saved_token_vector_index_inner;
								if (token_vector_index == saved_token_vector_index + 3) {
									token_vector_index = saved_token_vector_index;
								}
								break;
							}
						}
						if (token_vector[token_vector_index] == ")") {
							token_vector_index ++;
							while(token_vector_index < token_vector.size()) {
								int saved_token_vector_index_inner = token_vector_index;
								if (!definition(token_vector_index)) {
									token_vector_index = saved_token_vector_index_inner;
									if (token_vector_index == saved_token_vector_index + 3) {
										token_vector_index = saved_token_vector_index;
									}
									break;
								}
							}
							if (token_vector[token_vector_index] == ")") {
								return true;
							} else {
								token_vector_index = saved_token_vector_index;
							}
						} else {
							token_vector_index = saved_token_vector_index;
						}
					} else {
						token_vector_index = saved_token_vector_index;
					}
				}
			}

			token_vector_index = saved_token_vector_index;

			return false;
		}
	}
}	
