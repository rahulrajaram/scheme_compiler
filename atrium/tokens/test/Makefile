SRC_REL_PATH = ..
SOBJS = bin/complex.o	bin/decimal.o	bin/digit.o bin/exponent.o bin/exponent_marker.o bin/imag.o bin/num.o	bin/number.o bin/prefix.o bin/real.o bin/suffix.o bin/utils.o bin/token_vector.o bin/uinteger.o bin/ureal.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread

all: bin/test_exponent bin/test_suffix bin/test_uinteger_2 bin/test_uinteger_8\
bin/test_uinteger_10 bin/test_uinteger_16 bin/test_decimal bin/test_ureal_10\
bin/test_ureal_2 bin/test_ureal_8 bin/test_ureal_16\
bin/test_real_10 bin/test_real_2 bin/test_real_8 bin/test_real_16


# test executables
bin/test_exponent: $(SOBJS) bin/test_exponent.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_exponent.o -o bin/test_exponent

bin/test_exponent.o: test_exponent.cpp
	$(CC) $(CFLAGS) test_exponent.cpp -o bin/test_exponent.o

bin/test_suffix: $(SOBJS) bin/test_suffix.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_suffix.o -o bin/test_suffix

bin/test_suffix.o: test_suffix.cpp
	$(CC) $(CFLAGS) test_suffix.cpp -o bin/test_suffix.o

bin/test_uinteger_2: $(SOBJS) bin/test_uinteger_2.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_uinteger_2.o -o bin/test_uinteger_2

bin/test_uinteger_2.o: test_uinteger_2.cpp
	$(CC) $(CFLAGS) test_uinteger_2.cpp -o bin/test_uinteger_2.o

bin/test_uinteger_8: $(SOBJS) bin/test_uinteger_8.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_uinteger_8.o -o bin/test_uinteger_8

bin/test_uinteger_8.o: test_uinteger_8.cpp
	$(CC) $(CFLAGS) test_uinteger_8.cpp -o bin/test_uinteger_8.o

bin/test_uinteger_10: $(SOBJS) bin/test_uinteger_10.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_uinteger_10.o -o bin/test_uinteger_10

bin/test_uinteger_10.o: test_uinteger_10.cpp
	$(CC) $(CFLAGS) test_uinteger_10.cpp -o bin/test_uinteger_10.o

bin/test_uinteger_16: $(SOBJS) bin/test_uinteger_16.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_uinteger_16.o -o bin/test_uinteger_16

bin/test_uinteger_16.o: test_uinteger_16.cpp
	$(CC) $(CFLAGS) test_uinteger_16.cpp -o bin/test_uinteger_16.o

bin/test_decimal: $(SOBJS) bin/test_decimal.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_decimal.o -o bin/test_decimal

bin/test_decimal.o: test_decimal.cpp
	$(CC) $(CFLAGS) test_decimal.cpp -o bin/test_decimal.o

bin/test_ureal_10: $(SOBJS) bin/test_ureal_10.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_ureal_10.o -o bin/test_ureal_10

bin/test_ureal_10.o: test_ureal_10.cpp
	$(CC) $(CFLAGS) test_ureal_10.cpp -o bin/test_ureal_10.o

bin/test_ureal_2: $(SOBJS) bin/test_ureal_2.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_ureal_2.o -o bin/test_ureal_2

bin/test_ureal_2.o: test_ureal_2.cpp
	$(CC) $(CFLAGS) test_ureal_2.cpp -o bin/test_ureal_2.o

bin/test_ureal_8: $(SOBJS) bin/test_ureal_8.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_ureal_8.o -o bin/test_ureal_8

bin/test_ureal_8.o: test_ureal_8.cpp
	$(CC) $(CFLAGS) test_ureal_8.cpp -o bin/test_ureal_8.o

bin/test_ureal_16: $(SOBJS) bin/test_ureal_16.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_ureal_16.o -o bin/test_ureal_16

bin/test_ureal_16.o: test_ureal_16.cpp
	$(CC) $(CFLAGS) test_ureal_16.cpp -o bin/test_ureal_16.o

bin/test_real_10: $(SOBJS) bin/test_real_10.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_real_10.o -o bin/test_real_10

bin/test_real_10.o: test_real_10.cpp
	$(CC) $(CFLAGS) test_real_10.cpp -o bin/test_real_10.o

bin/test_real_2: $(SOBJS) bin/test_real_2.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_real_2.o -o bin/test_real_2

bin/test_real_2.o: test_real_2.cpp
	$(CC) $(CFLAGS) test_real_2.cpp -o bin/test_real_2.o

bin/test_real_8: $(SOBJS) bin/test_real_8.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_real_8.o -o bin/test_real_8

bin/test_real_8.o: test_real_8.cpp
	$(CC) $(CFLAGS) test_real_8.cpp -o bin/test_real_8.o

bin/test_real_16: $(SOBJS) bin/test_real_16.o
	$(CC) $(LFLAGS) $(SOBJS) bin/test_real_16.o -o bin/test_real_16

bin/test_real_16.o: test_real_16.cpp
	$(CC) $(CFLAGS) test_real_16.cpp -o bin/test_real_16.o



# Source link objects
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
