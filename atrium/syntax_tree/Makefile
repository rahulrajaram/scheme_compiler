OBJS = bin/syntax_tree.o bin/syntax_tree_node.o bin/main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

bin/main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o bin/main

bin/main.o: test.cpp
	$(CC) $(CFLAGS) test.cpp -o bin/main.o

bin/syntax_tree.o: syntax_tree.h syntax_tree.cpp
	$(CC) $(CFLAGS) syntax_tree.cpp -o bin/syntax_tree.o

bin/syntax_tree_node.o: syntax_tree_node.h syntax_tree_node.cpp
	$(CC) $(CFLAGS) syntax_tree_node.cpp -o bin/syntax_tree_node.o

clean:
	rm bin/*
