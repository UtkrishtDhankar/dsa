CC=g++
CFLAGS=-std=c++11 -Wall -Werror

CHAINED_EXEC=chained
CHAINED_SRC=ChainedMapDriver.cpp

all: chained

debug: CFLAGS+= -g
debug: all

chained:
	$(CC) $(CFLAGS) $(CHAINED_SRC) -o $(CHAINED_EXEC)

clean:
	rm -rf *.dSYM
	rm -f $(CHAINED_EXEC)
