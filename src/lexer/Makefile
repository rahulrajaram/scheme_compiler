OBJS = bin/lexer.o bin/lexer_input.o bin/main.o
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

bin/lexer_input.o: ../global_aliases.h lexer_input.h lexer_input.cpp
	$(CC) $(CFLAGS) lexer_input.cpp -o bin/lexer_input.o

clean:
	rm *o bin/*
