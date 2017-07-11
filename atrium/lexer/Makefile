OBJS = bin/lexer.o bin/token_vector.o bin/bracket_stack.o bin/main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

all: bin/main

bin/main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o bin/main

bin/main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o bin/main.o

bin/lexer.o: ../global_aliases.h lexer.h lexer.cpp
	$(CC) $(CFLAGS) lexer.cpp -o bin/lexer.o

bin/bracket_stack.o: bracket_stack.h bracket_stack.cpp
	$(CC) $(CFLAGS) bracket_stack.cpp -o bin/bracket_stack.o

bin/token_vector.o: token_vector.h token_vector.cpp
	$(CC) $(CFLAGS) token_vector.cpp -o bin/token_vector.o

clean:
	rm bin/*
