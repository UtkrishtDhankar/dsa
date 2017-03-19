CC=g++
CFLAGS=-std=c++11 -Wall -Werror

LIST_EXEC=list
LIST_SRC=list_tester.cpp

STACK_EXEC=stack
STACK_SRC=stack_tester.cpp

all: list stack

debug: CFLAGS+= -g
debug: all

list:
	$(CC) $(CFLAGS) $(LIST_SRC) -o $(LIST_EXEC)

stack:
	$(CC) $(CFLAGS) $(STACK_SRC) -o $(STACK_EXEC)

clean:
	rm -rf *.dSYM
	rm $(LIST_EXEC)
	rm $(STACK_EXEC)

