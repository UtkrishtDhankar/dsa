CC=g++
CFLAGS=-std=c++11 -Wall -Werror

LIST_EXEC=list
LIST_SRC=list_tester.cpp

all: list

debug: CFLAGS+= -g
debug: all

list:
	$(CC) $(CFLAGS) $(LIST_SRC) -o $(LIST_EXEC)

clean:
	rm -rf *.dSYM
	rm $(LIST_EXEC)

