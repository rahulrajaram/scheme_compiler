LEXER_OBJS = bin/lexer.o bin/bracket_stack.o bin/main.o
TOKENS_OBJS = bin/token_vector.o
#PARSER_OBJS = bin/parser.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

all: bin/main

bin/main: $(LEXER_OBJS) $(TOKENS_OBJS) #$(PARSER_OBJS)
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(TOKENS_OBJS) -o bin/main

bin/main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o bin/main.o

bin/lexer.o: global_aliases.h tokens/token_vector.h lexer/lexer.h lexer/lexer.cpp
	$(CC) $(CFLAGS) lexer/lexer.cpp  -o bin/lexer.o

bin/bracket_stack.o: lexer/bracket_stack.h lexer/bracket_stack.cpp
	$(CC) $(CFLAGS) lexer/bracket_stack.cpp -o bin/bracket_stack.o

bin/token_vector.o: tokens/token_vector.h tokens/token_vector.cpp
	$(CC) $(CFLAGS) tokens/token_vector.cpp -o bin/token_vector.o

#bin/parser.o: global_aliases.h parser/parser.h
	#$(CC) $(CFLAGS) parser/parser.cpp -o bin/parser.o

clean:
	rm bin/*
