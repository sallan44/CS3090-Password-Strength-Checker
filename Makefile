CC = g++
CFLAGS = -Wall
SRC = ./src

test:
	./PWChecker

PWChecker: $(SRC)/PasswordChecker.cpp
	$(CC) -std=c++11 $(CFLAGS) -o PWChecker $(SRC)/PasswordChecker.cpp

clean:
	rm -f *.o