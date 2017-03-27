CC=g++
CFLAGS=-std=c++11 -Wall -Werror

CHAINED_EXEC=chained
CHAINED_SRC=ChainedMapDriver.cpp

LIST_EXEC=list
LIST_SRC=ListMapDriver.cpp

OPEN_EXEC=open
OPEN_SRC=OpenMapDriver.cpp

DOUBLE_EXEC=double
DOUBLE_SRC=DoubleHashMapDriver.cpp

all: chained list open double

debug: CFLAGS+= -g
debug: all

chained:
	$(CC) $(CFLAGS) $(CHAINED_SRC) -o $(CHAINED_EXEC)

list:
	$(CC) $(CFLAGS) $(LIST_SRC) -o $(LIST_EXEC)

open:
	$(CC) $(CFLAGS) $(OPEN_SRC) -o $(OPEN_EXEC)

double:
	$(CC) $(CFLAGS) $(DOUBLE_SRC) -o $(DOUBLE_EXEC)

clean:
	rm -rf *.dSYM
	rm -f $(CHAINED_EXEC)
	rm -f $(LIST_EXEC)
	rm -f $(OPEN_EXEC)
	rm -f $(DOUBLE_EXEC)
