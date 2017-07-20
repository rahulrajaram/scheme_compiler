SRC_REL_PATH = ..
SOBJS = bin/complex.o	bin/decimal.o	bin/digit.o bin/exponent.o bin/exponent_marker.o bin/imag.o bin/num.o	bin/number.o bin/prefix.o bin/real.o bin/suffix.o bin/utils.o bin/token_vector.o bin/uinteger.o bin/ureal.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

all: bin/test_number

bin/test_number: $(SOBJS) bin/test_number.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_number.o -o bin/test_number

bin/test_number.o: test_number.cpp
	$(CC) $(CFLAGS) test_number.cpp -o bin/test_number.o

bin/complex.o: $(SRC_REL_PATH)/complex.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/complex.cpp -o bin/complex.o

bin/decimal.o: $(SRC_REL_PATH)/decimal.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/decimal.cpp -o bin/decimal.o

bin/digit.o: $(SRC_REL_PATH)/digit.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/digit.cpp -o bin/digit.o

bin/exponent.o: $(SRC_REL_PATH)/exponent.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/exponent.cpp -o bin/exponent.o

bin/exponent_marker.o: $(SRC_REL_PATH)/exponent_marker.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/exponent_marker.cpp -o bin/exponent_marker.o

bin/imag.o: $(SRC_REL_PATH)/imag.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/imag.cpp -o bin/imag.o

bin/num.o: $(SRC_REL_PATH)/num.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/num.cpp -o bin/num.o

bin/number.o: $(SRC_REL_PATH)/number.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/number.cpp -o bin/number.o

bin/prefix.o: $(SRC_REL_PATH)/prefix.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/prefix.cpp -o bin/prefix.o

bin/real.o: $(SRC_REL_PATH)/real.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/real.cpp -o bin/real.o

bin/suffix.o: $(SRC_REL_PATH)/suffix.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/suffix.cpp -o bin/suffix.o

bin/token_vector.o: $(SRC_REL_PATH)/token_vector.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/token_vector.cpp -o bin/token_vector.o

bin/uinteger.o: $(SRC_REL_PATH)/uinteger.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/uinteger.cpp -o bin/uinteger.o

bin/ureal.o: $(SRC_REL_PATH)/ureal.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/ureal.cpp -o bin/ureal.o

bin/utils.o: $(SRC_REL_PATH)/utils.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/utils.cpp -o bin/utils.o

clean:
	rm bin/*
