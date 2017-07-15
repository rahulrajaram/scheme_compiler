LEXER_OBJS = bin/lexer.o bin/token_vector.o bin/bracket_stack.o bin/main.o
PARSER_OBJS = bin/parser.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

all: bin/main

bin/main: $(LEXER_OBJS) $(PARSER_OBJS)
	$(CC) $(LFLAGS) $(LEXER_OBJS) $(PARSER_OBJS) -o bin/main

bin/main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o bin/main.o

bin/lexer.o: global_aliases.h lexer/lexer.h lexer/lexer.cpp
	$(CC) $(CFLAGS) lexer/lexer.cpp -o bin/lexer.o

bin/bracket_stack.o: lexer/bracket_stack.h lexer/bracket_stack.cpp
	$(CC) $(CFLAGS) lexer/bracket_stack.cpp -o bin/bracket_stack.o

bin/token_vector.o: lexer/token_vector.h lexer/token_vector.cpp
	$(CC) $(CFLAGS) lexer/token_vector.cpp -o bin/token_vector.o

bin/parser.o: global_aliases.h parser/parser.h
	$(CC) $(CFLAGS) parser/parser.cpp -o bin/parser.o

clean:
	rm bin/*
