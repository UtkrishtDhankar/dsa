CC=g++
CFLAGS=-std=c++11 -Wall -Werror

BTREE_EXEC=btree
BTREE_SRC=BinaryTreeDriver.cpp

all: btree

debug: CFLAGS+= -g
debug: all

btree:
	$(CC) $(CFLAGS) $(BTREE_SRC) -o $(BTREE_EXEC)

clean:
	rm -rf *.dSYM
	rm -f $(BTREE_EXEC)
