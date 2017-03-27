CC=g++
CFLAGS=-std=c++11 -Wall -Werror

CHAINED_EXEC=chained
CHAINED_SRC=ChainedMapDriver.cpp

LIST_EXEC=list
LIST_SRC=ListMapDriver.cpp

all: chained list

debug: CFLAGS+= -g
debug: all

chained:
	$(CC) $(CFLAGS) $(CHAINED_SRC) -o $(CHAINED_EXEC)

list:
	$(CC) $(CFLAGS) $(LIST_SRC) -o $(LIST_EXEC)

clean:
	rm -rf *.dSYM
	rm -f $(CHAINED_EXEC)
	rm -f $(LIST_EXEC)
