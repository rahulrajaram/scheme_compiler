LEXER_SRC = ..
TOKENS_SRC = ../../tokens

# **************
# SRC OBJECTS
# **************
TEST_OBJS = bin/test_lexer.o bin/test_helper.o
LEXER_OBJS = bin/lexer.o bin/bracket_stack.o
TOKENS_OBJS = bin/token_vector.o bin/utils.o bin/digit.o bin/complex.o\
bin/decimal.o bin/exponent.o bin/exponent_marker.o bin/imag.o\
bin/num.o bin/number.o bin/prefix.o bin/real.o bin/suffix.o bin/uinteger.o\
bin/ureal.o bin/letter.o bin/initial.o bin/subsequent.o bin/identifier.o\
bin/symbol.o bin/character.o bin/string.o bin/boolean.o\
bin/abbreviation_prefixes.o bin/classify.o bin/delimiters.o bin/syntactic_keywords.o bin/procedures.o


CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

all: bin/test_all

bin/test_all: $(TEST_OBJS) $(LEXER_OBJS) $(TOKENS_OBJS)
	$(CC) $(LFLAGS) $(TEST_OBJS) $(LEXER_OBJS) $(TOKENS_OBJS) -o bin/test_all

bin/test_helper.o: test_case_exceptions.h test_helper.h test_helper.cpp
	$(CC) $(CFLAGS) test_helper.cpp -o bin/test_helper.o

bin/test_lexer.o: $(LEXER_SRC)/../global_aliases.h test_helper.h test_lexer.cpp
	$(CC) $(CFLAGS) test_lexer.cpp -o bin/test_lexer.o


# ****************************
# Lexer source
# ****************************
bin/lexer.o: $(LEXER_SRC)/../global_aliases.h $(TOKENS_SRC)/token_vector.h $(LEXER_SRC)/lexer.h $(LEXER_SRC)/lexer.cpp
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


clean:
	rm bin/*
