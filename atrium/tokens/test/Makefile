SRC_REL_PATH = ..
UTIL_SOBJS = bin/utils.o bin/digit.o 
NUMBER_SOBJS = bin/complex.o	bin/decimal.o	bin/exponent.o bin/exponent_marker.o bin/imag.o bin/num.o	bin/number.o bin/prefix.o bin/real.o bin/suffix.o  bin/token_vector.o bin/uinteger.o bin/ureal.o $(UTIL_SOBJS)
IDENTIFIER_SOBJS = bin/letter.o bin/initial.o bin/subsequent.o bin/identifier.o $(UTIL_SOBJS)
STRING_SOBJS = bin/string.o $(UTIL_SOBJS)
CC = g++
DEBUG = -g
BOOST_FLAGS = -pedantic
CFLAGS = -Wall -c  -std=c++11 $(DEBUG)
LFLAGS = -Wall -pthread 
BOOST_LFLAGS = -lboost_system -lboost_filesystem

all: numbers_tests bin/test_identifier bin/test_string

numbers_tests: bin/test_exponent bin/test_suffix bin/test_uinteger_2 bin/test_uinteger_8\
bin/test_uinteger_10 bin/test_uinteger_16 bin/test_decimal bin/test_ureal_10\
bin/test_ureal_2 bin/test_ureal_8 bin/test_ureal_16\
bin/test_real_10 bin/test_real_2 bin/test_real_8 bin/test_real_16\
bin/test_imag_10 bin/test_imag_2 bin/test_imag_8 bin/test_imag_16\
bin/test_complex_2 bin/test_complex_8 bin/test_complex_16 bin/test_complex_10\
bin/test_num_2 bin/test_num_8 bin/test_num_16 bin/test_num_10

# test executables
bin/test_exponent: $(NUMBER_SOBJS) bin/test_exponent.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_exponent.o -o bin/test_exponent

bin/test_exponent.o: test_exponent.cpp
	$(CC) $(CFLAGS) test_exponent.cpp -o bin/test_exponent.o

bin/test_suffix: $(NUMBER_SOBJS) bin/test_suffix.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_suffix.o -o bin/test_suffix

bin/test_suffix.o: test_suffix.cpp
	$(CC) $(CFLAGS) test_suffix.cpp -o bin/test_suffix.o

bin/test_uinteger_2: $(NUMBER_SOBJS) bin/test_uinteger_2.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_uinteger_2.o -o bin/test_uinteger_2

bin/test_uinteger_2.o: test_uinteger_2.cpp
	$(CC) $(CFLAGS) test_uinteger_2.cpp -o bin/test_uinteger_2.o

bin/test_uinteger_8: $(NUMBER_SOBJS) bin/test_uinteger_8.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_uinteger_8.o -o bin/test_uinteger_8

bin/test_uinteger_8.o: test_uinteger_8.cpp
	$(CC) $(CFLAGS) test_uinteger_8.cpp -o bin/test_uinteger_8.o

bin/test_uinteger_10: $(NUMBER_SOBJS) bin/test_uinteger_10.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_uinteger_10.o -o bin/test_uinteger_10

bin/test_uinteger_10.o: test_uinteger_10.cpp
	$(CC) $(CFLAGS) test_uinteger_10.cpp -o bin/test_uinteger_10.o

bin/test_uinteger_16: $(NUMBER_SOBJS) bin/test_uinteger_16.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_uinteger_16.o -o bin/test_uinteger_16

bin/test_uinteger_16.o: test_uinteger_16.cpp
	$(CC) $(CFLAGS) test_uinteger_16.cpp -o bin/test_uinteger_16.o

bin/test_decimal: $(NUMBER_SOBJS) bin/test_decimal.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_decimal.o -o bin/test_decimal

bin/test_decimal.o: test_decimal.cpp
	$(CC) $(CFLAGS) test_decimal.cpp -o bin/test_decimal.o

bin/test_ureal_10: $(NUMBER_SOBJS) bin/test_ureal_10.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_ureal_10.o -o bin/test_ureal_10

bin/test_ureal_10.o: test_ureal_10.cpp
	$(CC) $(CFLAGS) test_ureal_10.cpp -o bin/test_ureal_10.o

bin/test_ureal_2: $(NUMBER_SOBJS) bin/test_ureal_2.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_ureal_2.o -o bin/test_ureal_2

bin/test_ureal_2.o: test_ureal_2.cpp
	$(CC) $(CFLAGS) test_ureal_2.cpp -o bin/test_ureal_2.o

bin/test_ureal_8: $(NUMBER_SOBJS) bin/test_ureal_8.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_ureal_8.o -o bin/test_ureal_8

bin/test_ureal_8.o: test_ureal_8.cpp
	$(CC) $(CFLAGS) test_ureal_8.cpp -o bin/test_ureal_8.o

bin/test_ureal_16: $(NUMBER_SOBJS) bin/test_ureal_16.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_ureal_16.o -o bin/test_ureal_16

bin/test_ureal_16.o: test_ureal_16.cpp
	$(CC) $(CFLAGS) test_ureal_16.cpp -o bin/test_ureal_16.o

bin/test_real_10: $(NUMBER_SOBJS) bin/test_real_10.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_real_10.o -o bin/test_real_10

bin/test_real_10.o: test_real_10.cpp
	$(CC) $(CFLAGS) test_real_10.cpp -o bin/test_real_10.o

bin/test_real_2: $(NUMBER_SOBJS) bin/test_real_2.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_real_2.o -o bin/test_real_2

bin/test_real_2.o: test_real_2.cpp
	$(CC) $(CFLAGS) test_real_2.cpp -o bin/test_real_2.o

bin/test_real_8: $(NUMBER_SOBJS) bin/test_real_8.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_real_8.o -o bin/test_real_8

bin/test_real_8.o: test_real_8.cpp
	$(CC) $(CFLAGS) test_real_8.cpp -o bin/test_real_8.o

bin/test_real_16: $(NUMBER_SOBJS) bin/test_real_16.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_real_16.o -o bin/test_real_16

bin/test_real_16.o: test_real_16.cpp
	$(CC) $(CFLAGS) test_real_16.cpp -o bin/test_real_16.o

bin/test_imag_2: $(NUMBER_SOBJS) bin/test_imag_2.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_imag_2.o -o bin/test_imag_2

bin/test_imag_2.o: test_imag_2.cpp
	$(CC) $(CFLAGS) test_imag_2.cpp -o bin/test_imag_2.o

bin/test_imag_8: $(NUMBER_SOBJS) bin/test_imag_8.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_imag_8.o -o bin/test_imag_8

bin/test_imag_8.o: test_imag_8.cpp
	$(CC) $(CFLAGS) test_imag_8.cpp -o bin/test_imag_8.o

bin/test_imag_10: $(NUMBER_SOBJS) bin/test_imag_10.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_imag_10.o -o bin/test_imag_10

bin/test_imag_10.o: test_imag_10.cpp
	$(CC) $(CFLAGS) test_imag_10.cpp -o bin/test_imag_10.o

bin/test_imag_16: $(NUMBER_SOBJS) bin/test_imag_16.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_imag_16.o -o bin/test_imag_16

bin/test_imag_16.o: test_imag_16.cpp
	$(CC) $(CFLAGS) test_imag_16.cpp -o bin/test_imag_16.o

bin/test_complex_2: $(NUMBER_SOBJS) bin/test_complex_2.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_complex_2.o -o bin/test_complex_2

bin/test_complex_2.o: test_complex_2.cpp
	$(CC) $(CFLAGS) test_complex_2.cpp -o bin/test_complex_2.o

bin/test_complex_8: $(NUMBER_SOBJS) bin/test_complex_8.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_complex_8.o -o bin/test_complex_8

bin/test_complex_8.o: test_complex_8.cpp
	$(CC) $(CFLAGS) test_complex_8.cpp -o bin/test_complex_8.o

bin/test_complex_16: $(NUMBER_SOBJS) bin/test_complex_16.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_complex_16.o -o bin/test_complex_16

bin/test_complex_16.o: test_complex_16.cpp
	$(CC) $(CFLAGS) test_complex_16.cpp -o bin/test_complex_16.o

bin/test_complex_10: $(NUMBER_SOBJS) bin/test_complex_10.o
	$(CC) $(LFLAGS) $(BOOST_LFLAGS) $(NUMBER_SOBJS) bin/test_complex_10.o -o bin/test_complex_10

bin/test_complex_10.o: test_complex_10.cpp
	$(CC) $(CFLAGS) $(BOOST_FLAGS) test_complex_10.cpp -o bin/test_complex_10.o

bin/test_num_2: $(NUMBER_SOBJS) bin/test_num_2.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_num_2.o -o bin/test_num_2

bin/test_num_2.o: test_num_2.cpp
	$(CC) $(CFLAGS) test_num_2.cpp -o bin/test_num_2.o

bin/test_num_8: $(NUMBER_SOBJS) bin/test_num_8.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_num_8.o -o bin/test_num_8

bin/test_num_8.o: test_num_8.cpp
	$(CC) $(CFLAGS) test_num_8.cpp -o bin/test_num_8.o

bin/test_num_16: $(NUMBER_SOBJS) bin/test_num_16.o
	$(CC) $(LFLAGS) $(NUMBER_SOBJS) bin/test_num_16.o -o bin/test_num_16

bin/test_num_16.o: test_num_16.cpp
	$(CC) $(CFLAGS) test_num_16.cpp -o bin/test_num_16.o

bin/test_num_10: $(NUMBER_SOBJS) bin/test_num_10.o
	$(CC) $(LFLAGS) $(BOOST_LFLAGS) $(NUMBER_SOBJS) bin/test_num_10.o -o bin/test_num_10

bin/test_num_10.o: test_num_10.cpp
	$(CC) $(CFLAGS) $(BOOST_FLAGS) test_num_10.cpp -o bin/test_num_10.o


# ****************************
# Util source
# ****************************
bin/utils.o: $(SRC_REL_PATH)/utils.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/utils.cpp -o bin/utils.o

bin/digit.o: $(SRC_REL_PATH)/digit.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/digit.cpp -o bin/digit.o



# **************************** 
# Number Source link objects
# ****************************
bin/complex.o: $(SRC_REL_PATH)/complex.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/complex.cpp -o bin/complex.o

bin/decimal.o: $(SRC_REL_PATH)/decimal.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/decimal.cpp -o bin/decimal.o

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



# **************************** 
# Identifier test link objects
# ****************************
bin/test_identifier: $(IDENTIFIER_SOBJS) bin/test_identifier.o
	$(CC) $(LFLAGS) $(IDENTIFIER_SOBJS) bin/test_identifier.o -o bin/test_identifier

bin/test_identifier.o: test_identifier.cpp
	$(CC) $(CFLAGS) test_identifier.cpp -o bin/test_identifier.o

bin/test_string: $(STRING_SOBJS) bin/test_string.o
	$(CC) $(LFLAGS) $(STRING_SOBJS) bin/test_string.o -o bin/test_string

bin/test_string.o: test_string.cpp
	$(CC) $(CFLAGS) test_string.cpp -o bin/test_string.o


# **************************** 
# Identifier Source link objects
# ****************************
bin/letter.o: $(SRC_REL_PATH)/letter.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/letter.cpp -o bin/letter.o

bin/initial.o: $(SRC_REL_PATH)/initial.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/initial.cpp -o bin/initial.o

bin/subsequent.o: $(SRC_REL_PATH)/subsequent.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/subsequent.cpp -o bin/subsequent.o

bin/identifier.o: $(SRC_REL_PATH)/identifier.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/identifier.cpp -o bin/identifier.o

bin/symbol.o: $(SRC_REL_PATH)/symbol.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/symbol.cpp -o bin/symbol.o

bin/character.o: $(SRC_REL_PATH)/character.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/character.cpp -o bin/character.o

bin/string.o: $(SRC_REL_PATH)/string.cpp
	$(CC) $(CFLAGS) $(SRC_REL_PATH)/string.cpp -o bin/string.o


clean:
	rm bin/*
