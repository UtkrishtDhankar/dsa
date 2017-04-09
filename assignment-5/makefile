CC=g++
CFLAGS=-std=c++11 -Wall -Werror

BTREE_EXEC=btree
BTREE_SRC=BinaryTreeDriver.cpp

BST_EXEC=bst
BST_SRC=BSTreeDriver.cpp

all: btree bst

debug: CFLAGS+= -g
debug: all

btree:
	$(CC) $(CFLAGS) $(BTREE_SRC) -o $(BTREE_EXEC)

bst:
	$(CC) $(CFLAGS) $(BST_SRC) -o $(BST_EXEC)

clean:
	rm -rf *.dSYM
	rm -f $(BTREE_EXEC)
	rm -f $(BST_EXEC)