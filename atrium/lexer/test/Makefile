OBJS = bin/test_helper.o bin/tokenizer_tests.o
SRC_REL_PATH = ..
SOBJS = bin/lexer.o bin/lexer_input.o bin/token_vector.o bin/paren_stack.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

all: bin/test_all

bin/test_all: $(OBJS) $(SOBJS)
	$(CC) $(LFLAGS) $(OBJS) $(SOBJS) -o bin/test_all

bin/test_helper.o: test_case_exceptions.h test_helper.h test_helper.cpp
	$(CC) $(CFLAGS) test_helper.cpp -o bin/test_helper.o

bin/tokenizer_tests.o: test_helper.h tokenizer_tests.cpp
	$(CC) $(CFLAGS) tokenizer_tests.cpp -o bin/tokenizer_tests.o

bin/lexer.o: $(SRC_REL_PATH)/../global_aliases.h $(SRC_REL_PATH)/lexer.h $(SRC_REL_PATH)/lexer.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/lexer.cpp -o bin/lexer.o

bin/lexer_input.o: $(SRC_REL_PATH)/../global_aliases.h $(SRC_REL_PATH)/lexer_input.h $(SRC_REL_PATH)/lexer_input.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/lexer_input.cpp -o bin/lexer_input.o

bin/paren_stack.o: $(SRC_REL_PATH)/paren_stack.h $(SRC_REL_PATH)/paren_stack.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/paren_stack.cpp -o bin/paren_stack.o

bin/token_vector.o: $(SRC_REL_PATH)/token_vector.h $(SRC_REL_PATH)/token_vector.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/token_vector.cpp -o bin/token_vector.o

clean:
	rm bin/*