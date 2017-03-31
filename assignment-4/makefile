CC=g++
CFLAGS=-std=c++11 -Wall -Werror

CHAINED_EXEC=chained
CHAINED_SRC=ChainedMapDriver.cpp

CHAINED_STRING_EXEC=chained_str
CHAINED_STRING_SRC=ChainedMapStringDriver.cpp

LIST_EXEC=list
LIST_SRC=ListMapDriver.cpp

LIST_STRING_EXEC=list_str
LIST_STRING_SRC=ListMapStringDriver.cpp

OPEN_EXEC=open
OPEN_SRC=OpenMapDriver.cpp

OPEN_STRING_EXEC=open_str
OPEN_STRING_SRC=OpenMapStringDriver.cpp

DOUBLE_EXEC=double
DOUBLE_SRC=DoubleHashMapDriver.cpp

DOUBLE_STRING_EXEC=double_str
DOUBLE_STRING_SRC=DoubleHashMapStringDriver.cpp

LRU_EXEC=lru
LRU_SRC=lru.cpp

all: chained list open double lru open_str double_str chained_str list_str

debug: CFLAGS+= -g
debug: all

chained:
	$(CC) $(CFLAGS) $(CHAINED_SRC) -o $(CHAINED_EXEC)

chained_str:
	$(CC) $(CFLAGS) $(CHAINED_STRING_SRC) -o $(CHAINED_STRING_EXEC)

list:
	$(CC) $(CFLAGS) $(LIST_SRC) -o $(LIST_EXEC)

list_str:
	$(CC) $(CFLAGS) $(LIST_STRING_SRC) -o $(LIST_STRING_EXEC)

open:
	$(CC) $(CFLAGS) $(OPEN_SRC) -o $(OPEN_EXEC)

open_str:
	$(CC) $(CFLAGS) $(OPEN_STRING_SRC) -o $(OPEN_STRING_EXEC)

double:
	$(CC) $(CFLAGS) $(DOUBLE_SRC) -o $(DOUBLE_EXEC)

double_str:
	$(CC) $(CFLAGS) $(DOUBLE_STRING_SRC) -o $(DOUBLE_STRING_EXEC)

lru:
	$(CC) $(CFLAGS) $(LRU_SRC) -o $(LRU_EXEC)


clean:
	rm -rf *.dSYM
	rm -f $(CHAINED_EXEC)
	rm -f $(CHAINED_STRING_EXEC)
	rm -f $(LIST_EXEC)
	rm -f $(LIST_STRING_EXEC)
	rm -f $(OPEN_EXEC)
	rm -f $(OPEN_STRING_EXEC)
	rm -f $(DOUBLE_STRING_EXEC)
	rm -f $(DOUBLE_EXEC)
	rm -f $(LRU_EXEC)
