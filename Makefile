main: main.o caesar.o vigenere.o decrypt.o
	g++ -o main main.o caesar.o vigenere.o decrypt.o

tests: tests.o caesar.o vigenere.o decrypt.o
	g++ -o tests tests.o caesar.o vigenere.o decrypt.o

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o

test-ascii.o: test-ascii.cpp
	g++ -Wall -c test-ascii.cpp

decrypt.o: decrypt.cpp decrypt.h
	g++ -Wall -c decrypt.cpp

caesar.o: caesar.cpp caeser.h
	g++ -Wall -c caesar.cpp

vigenere.o: vigenere.cpp vigenere.h
	g++ -Wall -c vigenere.cpp

main.o: main.cpp caeser.h vigenere.h decrypt.h
	g++ -Wall -c main.cpp

tests.o: tests.cpp doctest.h caeser.h vigenere.h decrypt.h
	g++ -std=c++11 -Wall -c tests.cpp

help:
	@echo "Targets: "
	@echo " main (default) - compile main and run with ./main"
	@echo " tests - compile all tests and run with ./tests"
	@echo " test-ascii - compile test-ascii and run with ./test-ascii"
	@echo " clean - remove all object and executable files"

clean:
	rm -f *o a.out main tests test-ascii
