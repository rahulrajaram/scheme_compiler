OBJS = bin/test_helper.o bin/tokenizer_tests.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

all: bin/test_all

bin/test_all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o bin/test_all

bin/test_helper.o: test_case_exceptions.h test_helper.h test_helper.cpp
	$(CC) $(CFLAGS) test_helper.cpp -o bin/test_helper.o

bin/tokenizer_tests.o: test_helper.h tokenizer_tests.cpp
	$(CC) $(CFLAGS) tokenizer_tests.cpp -o bin/tokenizer_tests.o

clean:
	rm bin/*
