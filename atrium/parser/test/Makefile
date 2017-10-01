# **************
# SRC PATHS
# **************
ATRIUM_SRC = ../..
TOKENS_SRC = ../../tokens
LEXER_SRC = ../../lexer
PARSER_SRC = ..

# **************
# SRC OBJECTS
# **************
LEXER_OBJS = bin/lexer.o bin/bracket_stack.o
TOKENS_OBJS = bin/token_vector.o bin/utils.o bin/digit.o bin/complex.o\
bin/decimal.o bin/exponent.o bin/exponent_marker.o bin/imag.o\
bin/num.o bin/number.o bin/prefix.o bin/real.o bin/suffix.o bin/uinteger.o\
bin/ureal.o bin/letter.o bin/initial.o bin/subsequent.o bin/identifier.o\
bin/symbol.o bin/character.o bin/string.o bin/boolean.o\
bin/abbreviation_prefixes.o bin/classify.o bin/delimiters.o bin/syntactic_keywords.o bin/procedures.o
PARSER_OBJS = bin/parser.o bin/abbreviation.o bin/body.o bin/constant.o bin/datum.o bin/definition.o bin/form.o bin/formals.o bin/keyword.o bin/list.o bin/pattern.o bin/pattern_identifier.o bin/program.o bin/syntax_binding.o bin/syntax_definition.o bin/template.o bin/template_datum.o bin/template_element.o bin/variable.o bin/variable_definition.o bin/vector.o bin/derived_expression.o bin/cond_clause.o bin/sequence.o bin/case_clause.o bin/test.o bin/binding_spec.o bin/do_result.o bin/command.o bin/parser_utils.o bin/expression.o bin/transformer_expression.o bin/syntax_rule.o bin/application.o bin/iteration_spec.o bin/procedure_call.o bin/operand.o bin/operator.o 

CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

all: bin/test_body bin/test_iteration_spec bin/test_variable_definition bin/test_constant bin/test_datum bin/test_expression bin/test_formals bin/test_identifier bin/test_list bin/test_pattern bin/test_pattern_identifier bin/test_syntax_rule bin/test_syntax_binding bin/test_template bin/test_template_datum bin/test_template_element bin/test_vector bin/test_transformer_expression bin/test_case_clause bin/test_sequence bin/test_derived_expression bin/test_cond_clause bin/test_binding_spec bin/test_form

bin/test_form: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_form.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_form.o -o bin/test_form

bin/test_form.o: test_form.cpp test_helper.h
	$(CC) $(CFLAGS) test_form.cpp -o bin/test_form.o

bin/test_body: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_body.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_body.o -o bin/test_body

bin/test_body.o: test_body.cpp test_helper.h
	$(CC) $(CFLAGS) test_body.cpp -o bin/test_body.o

bin/test_case_clause: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_case_clause.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_case_clause.o -o bin/test_case_clause

bin/test_case_clause.o: test_case_clause.cpp test_helper.h
	$(CC) $(CFLAGS) test_case_clause.cpp -o bin/test_case_clause.o

bin/test_variable_definition: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_variable_definition.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_variable_definition.o -o bin/test_variable_definition

bin/test_variable_definition.o: test_variable_definition.cpp test_helper.h
	$(CC) $(CFLAGS) test_variable_definition.cpp -o bin/test_variable_definition.o

bin/test_iteration_spec: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_iteration_spec.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_iteration_spec.o -o bin/test_iteration_spec

bin/test_iteration_spec.o: test_iteration_spec.cpp test_helper.h
	$(CC) $(CFLAGS) test_iteration_spec.cpp -o bin/test_iteration_spec.o

bin/test_binding_spec: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_binding_spec.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_binding_spec.o -o bin/test_binding_spec

bin/test_binding_spec.o: test_binding_spec.cpp test_helper.h
	$(CC) $(CFLAGS) test_binding_spec.cpp -o bin/test_binding_spec.o

bin/test_cond_clause: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_cond_clause.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_cond_clause.o -o bin/test_cond_clause

bin/test_cond_clause.o: test_cond_clause.cpp test_helper.h
	$(CC) $(CFLAGS) test_cond_clause.cpp -o bin/test_cond_clause.o

bin/test_constant: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_constant.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_constant.o -o bin/test_constant

bin/test_constant.o: test_constant.cpp test_helper.h
	$(CC) $(CFLAGS) test_constant.cpp -o bin/test_constant.o

bin/test_datum: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_datum.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_datum.o -o bin/test_datum

bin/test_datum.o: test_datum.cpp test_helper.h
	$(CC) $(CFLAGS) test_datum.cpp -o bin/test_datum.o

bin/test_derived_expression: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_derived_expression.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_derived_expression.o -o bin/test_derived_expression

bin/test_derived_expression.o: test_derived_expression.cpp test_helper.h
	$(CC) $(CFLAGS) test_derived_expression.cpp -o bin/test_derived_expression.o

bin/test_expression: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_expression.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_expression.o -o bin/test_expression

bin/test_expression.o: test_expression.cpp test_helper.h
	$(CC) $(CFLAGS) test_expression.cpp -o bin/test_expression.o

bin/test_formals: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_formals.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_formals.o -o bin/test_formals

bin/test_formals.o: test_formals.cpp test_helper.h
	$(CC) $(CFLAGS) test_formals.cpp -o bin/test_formals.o

bin/test_identifier: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_identifier.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_identifier.o -o bin/test_identifier

bin/test_identifier.o: test_identifier.cpp test_helper.h
	$(CC) $(CFLAGS) test_identifier.cpp -o bin/test_identifier.o

bin/test_list: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_list.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_list.o -o bin/test_list

bin/test_list.o: test_list.cpp test_helper.h
	$(CC) $(CFLAGS) test_list.cpp -o bin/test_list.o

bin/test_pattern: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_pattern.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_pattern.o -o bin/test_pattern

bin/test_pattern.o: test_pattern.cpp test_helper.h
	$(CC) $(CFLAGS) test_pattern.cpp -o bin/test_pattern.o

bin/test_pattern_identifier: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_pattern_identifier.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_pattern_identifier.o -o bin/test_pattern_identifier

bin/test_pattern_identifier.o: test_pattern_identifier.cpp test_helper.h
	$(CC) $(CFLAGS) test_pattern_identifier.cpp -o bin/test_pattern_identifier.o

bin/test_sequence: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_sequence.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_sequence.o -o bin/test_sequence

bin/test_sequence.o: test_sequence.cpp test_helper.h
	$(CC) $(CFLAGS) test_sequence.cpp -o bin/test_sequence.o

bin/test_syntax_binding: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_syntax_binding.o bin/test_syntax_binding.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_syntax_binding.o -o bin/test_syntax_binding

bin/test_syntax_binding.o: test_syntax_binding.cpp test_helper.h
	$(CC) $(CFLAGS) test_syntax_binding.cpp -o bin/test_syntax_binding.o

bin/test_syntax_rule: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_syntax_rule.o bin/test_syntax_rule.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_syntax_rule.o -o bin/test_syntax_rule

bin/test_syntax_rule.o: test_syntax_rule.cpp test_helper.h
	$(CC) $(CFLAGS) test_syntax_rule.cpp -o bin/test_syntax_rule.o

bin/test_template: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_template.o bin/test_template.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_template.o -o bin/test_template

bin/test_template.o: test_template.cpp test_helper.h
	$(CC) $(CFLAGS) test_template.cpp -o bin/test_template.o

bin/test_template_datum: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_template_datum.o bin/test_template_datum.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_template_datum.o -o bin/test_template_datum

bin/test_template_datum.o: test_template_datum.cpp test_helper.h
	$(CC) $(CFLAGS) test_template_datum.cpp -o bin/test_template_datum.o

bin/test_template_element: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_template_element.o bin/test_template_element.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_template_element.o -o bin/test_template_element

bin/test_template_element.o: test_template_element.cpp test_helper.h
	$(CC) $(CFLAGS) test_template_element.cpp -o bin/test_template_element.o

bin/test_transformer_expression.o: test_transformer_expression.cpp test_helper.h
	$(CC) $(CFLAGS) test_transformer_expression.cpp -o bin/test_transformer_expression.o

bin/test_transformer_expression: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_transformer_expression.o bin/test_transformer_expression.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_transformer_expression.o -o bin/test_transformer_expression


bin/test_vector: $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_vector.o
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) $(PARSER_OBJS) bin/test_helper.o bin/test_vector.o -o bin/test_vector

bin/test_vector.o: test_vector.cpp test_helper.h
	$(CC) $(CFLAGS) test_vector.cpp -o bin/test_vector.o

bin/test_helper.o: test_helper.cpp
	$(CC) $(CFLAGS) test_helper.cpp -o bin/test_helper.o

# *****************************
# Lexer files
# *****************************
bin/lexer.o: $(ATRIUM_SRC)/global_aliases.h $(TOKENS_SRC)/token_vector.h $(LEXER_SRC)/lexer.h $(LEXER_SRC)/lexer.cpp
	$(CC) $(CFLAGS) $(LEXER_SRC)/lexer.cpp  -o bin/lexer.o

bin/bracket_stack.o: $(LEXER_SRC)/bracket_stack.h $(LEXER_SRC)/bracket_stack.cpp
	$(CC) $(CFLAGS) $(LEXER_SRC)/bracket_stack.cpp -o bin/bracket_stack.o


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
bin/application.o: $(PARSER_SRC)/application.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/application.cpp -o bin/application.o

bin/abbreviation.o: $(PARSER_SRC)/abbreviation.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/abbreviation.cpp -o bin/abbreviation.o

bin/binding_spec.o: $(PARSER_SRC)/binding_spec.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/binding_spec.cpp -o bin/binding_spec.o

bin/body.o: $(PARSER_SRC)/body.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/body.cpp -o bin/body.o

bin/case_clause.o: $(PARSER_SRC)/case_clause.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/case_clause.cpp -o bin/case_clause.o

bin/command.o: $(PARSER_SRC)/command.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/command.cpp -o bin/command.o

bin/cond_clause.o: $(PARSER_SRC)/cond_clause.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/cond_clause.cpp -o bin/cond_clause.o

bin/constant.o: $(PARSER_SRC)/constant.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/constant.cpp -o bin/constant.o

bin/datum.o: $(PARSER_SRC)/datum.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/datum.cpp -o bin/datum.o

bin/definition.o: $(PARSER_SRC)/definition.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/definition.cpp -o bin/definition.o

bin/derived_expression.o: $(PARSER_SRC)/derived_expression.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/derived_expression.cpp -o bin/derived_expression.o

bin/do_result.o: $(PARSER_SRC)/do_result.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/do_result.cpp -o bin/do_result.o

bin/expression.o: $(PARSER_SRC)/expression.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/expression.cpp -o bin/expression.o

bin/form.o: $(PARSER_SRC)/form.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/form.cpp -o bin/form.o

bin/formals.o: $(PARSER_SRC)/formals.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/formals.cpp -o bin/formals.o

bin/iteration_spec.o: $(PARSER_SRC)/iteration_spec.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/iteration_spec.cpp -o bin/iteration_spec.o

bin/keyword.o: $(PARSER_SRC)/keyword.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/keyword.cpp -o bin/keyword.o

bin/list.o: $(PARSER_SRC)/list.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/list.cpp -o bin/list.o

bin/operand.o: $(PARSER_SRC)/operand.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/operand.cpp -o bin/operand.o

bin/operator.o: $(PARSER_SRC)/operator.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/operator.cpp -o bin/operator.o

bin/parser.o: $(PARSER_SRC)/parser.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/parser.cpp -o bin/parser.o

bin/pattern.o: $(PARSER_SRC)/pattern.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/pattern.cpp -o bin/pattern.o

bin/pattern_identifier.o: $(PARSER_SRC)/pattern_identifier.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/pattern_identifier.cpp -o bin/pattern_identifier.o

bin/procedure_call.o: $(PARSER_SRC)/procedure_call.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/procedure_call.cpp -o bin/procedure_call.o

bin/program.o: $(PARSER_SRC)/program.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/program.cpp -o bin/program.o

bin/syntax_binding.o: $(PARSER_SRC)/syntax_binding.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/syntax_binding.cpp -o bin/syntax_binding.o

bin/sequence.o: $(PARSER_SRC)/sequence.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/sequence.cpp -o bin/sequence.o

bin/syntax_definition.o: $(PARSER_SRC)/syntax_definition.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/syntax_definition.cpp -o bin/syntax_definition.o

bin/syntax_rule.o: $(PARSER_SRC)/syntax_rule.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/syntax_rule.cpp -o bin/syntax_rule.o

bin/test.o: $(PARSER_SRC)/test.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/test.cpp -o bin/test.o

bin/template.o: $(PARSER_SRC)/template.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/template.cpp -o bin/template.o

bin/template_datum.o: $(PARSER_SRC)/template_datum.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/template_datum.cpp -o bin/template_datum.o

bin/template_element.o: $(PARSER_SRC)/template_element.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/template_element.cpp -o bin/template_element.o

bin/transformer_expression.o: $(PARSER_SRC)/transformer_expression.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/transformer_expression.cpp -o bin/transformer_expression.o

bin/parser_utils.o: $(PARSER_SRC)/utils.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/utils.cpp -o bin/parser_utils.o

bin/variable.o: $(PARSER_SRC)/variable.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/variable.cpp -o bin/variable.o

bin/variable_definition.o: $(PARSER_SRC)/variable_definition.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/variable_definition.cpp -o bin/variable_definition.o

bin/vector.o: $(PARSER_SRC)/vector.cpp
	$(CC) $(CFLAGS) $(PARSER_SRC)/vector.cpp -o bin/vector.o

clean:
	rm bin/*
