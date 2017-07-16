OBJS = bin/test_helper.o bin/test_lexer.o
LEXER_SRC_REL_PATH = ..
TOKENS_SRC_REL_PATH = ../../tokens
SOBJS = bin/lexer.o bin/token_vector.o bin/bracket_stack.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

all: bin/test_all

bin/test_all: $(OBJS) $(SOBJS)
	$(CC) $(LFLAGS) $(OBJS) $(SOBJS) -o bin/test_all

bin/test_helper.o: test_case_exceptions.h test_helper.h test_helper.cpp
	$(CC) $(CFLAGS) test_helper.cpp -o bin/test_helper.o

bin/test_lexer.o: $(LEXER_SRC_REL_PATH)/../global_aliases.h test_helper.h test_lexer.cpp
	$(CC) $(CFLAGS) test_lexer.cpp -o bin/test_lexer.o

bin/lexer.o: $(LEXER_SRC_REL_PATH)/../global_aliases.h $(LEXER_SRC_REL_PATH)/lexer.h $(LEXER_SRC_REL_PATH)/lexer.cpp
	$(CC) $(CFLAGS) $(LEXER_SRC_REL_PATH)/lexer.cpp -o bin/lexer.o

bin/bracket_stack.o: $(LEXER_SRC_REL_PATH)/bracket_stack.h $(LEXER_SRC_REL_PATH)/bracket_stack.cpp
	$(CC) $(CFLAGS) $(LEXER_SRC_REL_PATH)/bracket_stack.cpp -o bin/bracket_stack.o

bin/token_vector.o: $(TOKENS_SRC_REL_PATH)/token_vector.h $(TOKENS_SRC_REL_PATH)/token_vector.cpp
	$(CC) $(CFLAGS) $(TOKENS_SRC_REL_PATH)/token_vector.cpp -o bin/token_vector.o

clean:
	rm bin/*
