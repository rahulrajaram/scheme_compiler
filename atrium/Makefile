# **************
# SRC PATHS
# **************
TOKENS_SRC = tokens
LEXER_SRC = lexer
PARSER_SRC = parser

# **************
# SRC OBJECTS
# **************
LEXER_OBJS = bin/lexer.o bin/bracket_stack.o bin/main.o
TOKENS_OBJS = bin/token_vector.o bin/utils.o bin/digit.o bin/complex.o\
bin/decimal.o bin/exponent.o bin/exponent_marker.o bin/imag.o\
bin/num.o bin/number.o bin/prefix.o bin/real.o bin/suffix.o bin/uinteger.o\
bin/ureal.o bin/letter.o bin/initial.o bin/subsequent.o bin/identifier.o\
bin/symbol.o bin/character.o bin/string.o bin/boolean.o\
bin/abbreviation_prefixes.o bin/classify.o bin/delimiters.o bin/syntactic_keywords.o bin/procedures.o
PARSER_OBJS = bin/parser.o bin/abbreviation.o bin/body.o bin/constant.o bin/datum.o bin/definition.o bin/ellipsis.o bin/form.o bin/formals.o bin/keyword.o bin/list.o bin/pattern.o bin/pattern_identifier.o bin/program.o bin/syntax_binding.o bin/syntax_definition.o bin/template.o bin/template_datum.o bin/template_element.o bin/variable.o bin/variable_definition.o bin/vector.o bin/derived_expression.o bin/cond_clause.o bin/sequence.o bin/case_clause.o bin/test.o bin/binding_spec.o bin/do_result.o bin/command.o

CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

all: bin/main

bin/main: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS)
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) -o bin/main

bin/main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o bin/main.o

# *****************************
# Lexer files
# *****************************
bin/lexer.o: global_aliases.h $(TOKENS_SRC)/token_vector.h lexer/lexer.h lexer/lexer.cpp
	$(CC) $(CFLAGS) lexer/lexer.cpp  -o bin/lexer.o

bin/bracket_stack.o: lexer/bracket_stack.h lexer/bracket_stack.cpp
	$(CC) $(CFLAGS) lexer/bracket_stack.cpp -o bin/bracket_stack.o


# ****************************
# Token::Util source
# ****************************
bin/utils.o: $(TOKENS_SRC)/utils.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/utils.cpp -o bin/utils.o

bin/digit.o: $(TOKENS_SRC)/digit.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/digit.cpp -o bin/digit.o
# **************************** 
# Token::Number Source link objects
# ****************************
bin/complex.o: $(TOKENS_SRC)/complex.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/complex.cpp -o bin/complex.o

bin/decimal.o: $(TOKENS_SRC)/decimal.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/decimal.cpp -o bin/decimal.o

bin/exponent.o: $(TOKENS_SRC)/exponent.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/exponent.cpp -o bin/exponent.o

bin/exponent_marker.o: $(TOKENS_SRC)/exponent_marker.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/exponent_marker.cpp -o bin/exponent_marker.o

bin/imag.o: $(TOKENS_SRC)/imag.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/imag.cpp -o bin/imag.o

bin/num.o: $(TOKENS_SRC)/num.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/num.cpp -o bin/num.o

bin/number.o: $(TOKENS_SRC)/number.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/number.cpp -o bin/number.o

bin/prefix.o: $(TOKENS_SRC)/prefix.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/prefix.cpp -o bin/prefix.o

bin/real.o: $(TOKENS_SRC)/real.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/real.cpp -o bin/real.o

bin/suffix.o: $(TOKENS_SRC)/suffix.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/suffix.cpp -o bin/suffix.o

bin/token_vector.o: $(TOKENS_SRC)/token_vector.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/token_vector.cpp -o bin/token_vector.o

bin/uinteger.o: $(TOKENS_SRC)/uinteger.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/uinteger.cpp -o bin/uinteger.o

bin/ureal.o: $(TOKENS_SRC)/ureal.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/ureal.cpp -o bin/ureal.o
# **************************** 
# Token::Identifier Source link objects
# ****************************
bin/letter.o: $(TOKENS_SRC)/letter.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/letter.cpp -o bin/letter.o

bin/initial.o: $(TOKENS_SRC)/initial.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/initial.cpp -o bin/initial.o

bin/subsequent.o: $(TOKENS_SRC)/subsequent.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/subsequent.cpp -o bin/subsequent.o

bin/identifier.o: $(TOKENS_SRC)/identifier.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/identifier.cpp -o bin/identifier.o

bin/symbol.o: $(TOKENS_SRC)/symbol.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/symbol.cpp -o bin/symbol.o

bin/character.o: $(TOKENS_SRC)/character.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/character.cpp -o bin/character.o

bin/string.o: $(TOKENS_SRC)/string.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/string.cpp -o bin/string.o

bin/boolean.o: $(TOKENS_SRC)/boolean.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/boolean.cpp -o bin/boolean.o
# **************************** 
# Token::Classifier Source link objects
# ****************************
bin/abbreviation_prefixes.o: $(TOKENS_SRC)/abbreviation_prefixes.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/abbreviation_prefixes.cpp -o bin/abbreviation_prefixes.o

bin/classify.o: $(TOKENS_SRC)/classify.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/classify.cpp -o bin/classify.o

bin/delimiters.o: $(TOKENS_SRC)/delimiters.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/delimiters.cpp -o bin/delimiters.o

bin/syntactic_keywords.o: $(TOKENS_SRC)/syntactic_keywords.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/syntactic_keywords.cpp -o bin/syntactic_keywords.o

bin/procedures.o: $(TOKENS_SRC)/procedures.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC)/procedures.cpp -o bin/procedures.o


# *****************************
# Token files
# *****************************
bin/abbreviation.o: parser/abbreviation.cpp
	$(CC) $(CFLAGS) parser/abbreviation.cpp -o bin/abbreviation.o

bin/binding_spec.o: parser/binding_spec.cpp
	$(CC) $(CFLAGS) parser/binding_spec.cpp -o bin/binding_spec.o

bin/body.o: parser/body.cpp
	$(CC) $(CFLAGS) parser/body.cpp -o bin/body.o

bin/case_clause.o: parser/case_clause.cpp
	$(CC) $(CFLAGS) parser/case_clause.cpp -o bin/case_clause.o

bin/command.o: parser/command.cpp
	$(CC) $(CFLAGS) parser/command.cpp -o bin/command.o

bin/cond_clause.o: parser/cond_clause.cpp
	$(CC) $(CFLAGS) parser/cond_clause.cpp -o bin/cond_clause.o

bin/constant.o: parser/constant.cpp
	$(CC) $(CFLAGS) parser/constant.cpp -o bin/constant.o

bin/datum.o: parser/datum.cpp
	$(CC) $(CFLAGS) parser/datum.cpp -o bin/datum.o

bin/definition.o: parser/definition.cpp
	$(CC) $(CFLAGS) parser/definition.cpp -o bin/definition.o

bin/derived_expression.o: parser/derived_expression.cpp
	$(CC) $(CFLAGS) parser/derived_expression.cpp -o bin/derived_expression.o

bin/do_result.o: parser/do_result.cpp
	$(CC) $(CFLAGS) parser/do_result.cpp -o bin/do_result.o

bin/ellipsis.o: parser/ellipsis.cpp
	$(CC) $(CFLAGS) parser/ellipsis.cpp -o bin/ellipsis.o

bin/form.o: parser/form.cpp
	$(CC) $(CFLAGS) parser/form.cpp -o bin/form.o

bin/formals.o: parser/formals.cpp
	$(CC) $(CFLAGS) parser/formals.cpp -o bin/formals.o

bin/keyword.o: parser/keyword.cpp
	$(CC) $(CFLAGS) parser/keyword.cpp -o bin/keyword.o

bin/list.o: parser/list.cpp
	$(CC) $(CFLAGS) parser/list.cpp -o bin/list.o

bin/parser.o: parser/parser.cpp
	$(CC) $(CFLAGS) parser/parser.cpp -o bin/parser.o

bin/pattern.o: parser/pattern.cpp
	$(CC) $(CFLAGS) parser/pattern.cpp -o bin/pattern.o

bin/pattern_identifier.o: parser/pattern_identifier.cpp
	$(CC) $(CFLAGS) parser/pattern_identifier.cpp -o bin/pattern_identifier.o

bin/program.o: parser/program.cpp
	$(CC) $(CFLAGS) parser/program.cpp -o bin/program.o

bin/syntax_binding.o: parser/syntax_binding.cpp
	$(CC) $(CFLAGS) parser/syntax_binding.cpp -o bin/syntax_binding.o

bin/sequence.o: parser/sequence.cpp
	$(CC) $(CFLAGS) parser/sequence.cpp -o bin/sequence.o

bin/syntax_definition.o: parser/syntax_definition.cpp
	$(CC) $(CFLAGS) parser/syntax_definition.cpp -o bin/syntax_definition.o

bin/syntax_definition.o: parser/syntax_definition.cpp
	$(CC) $(CFLAGS) parser/syntax_definition.cpp -o bin/syntax_definition.o

bin/test.o: parser/test.cpp
	$(CC) $(CFLAGS) parser/test.cpp -o bin/test.o

bin/template.o: parser/template.cpp
	$(CC) $(CFLAGS) parser/template.cpp -o bin/template.o

bin/template_datum.o: parser/template_datum.cpp
	$(CC) $(CFLAGS) parser/template_datum.cpp -o bin/template_datum.o

bin/template_element.o: parser/template_element.cpp
	$(CC) $(CFLAGS) parser/template_element.cpp -o bin/template_element.o

bin/variable.o: parser/variable.cpp
	$(CC) $(CFLAGS) parser/variable.cpp -o bin/variable.o

bin/variable_definition.o: parser/variable_definition.cpp
	$(CC) $(CFLAGS) parser/variable_definition.cpp -o bin/variable_definition.o

bin/vector.o: parser/vector.cpp
	$(CC) $(CFLAGS) parser/vector.cpp -o bin/vector.o

clean:
	rm bin/*
