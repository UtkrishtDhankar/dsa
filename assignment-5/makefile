CC=g++
CFLAGS=-std=c++11 -Wall -Werror

BTREE_EXEC=btree
BTREE_SRC=BinaryTreeDriver.cpp

BST_EXEC=bst
BST_SRC=BSTreeDriver.cpp

AVL_EXEC=avl
AVL_SRC=AVLDriver.cpp

RBT_EXEC=rb
RBT_SRC=RBTreeDriver.cpp

all: btree bst avl rbt

debug: CFLAGS+= -g
debug: all

btree:
	$(CC) $(CFLAGS) $(BTREE_SRC) -o $(BTREE_EXEC)

avl:
	$(CC) $(CFLAGS) $(AVL_SRC) -o $(AVL_EXEC)

rbt:
	$(CC) $(CFLAGS) $(RBT_SRC) -o $(RBT_EXEC)

bst:
	$(CC) $(CFLAGS) $(BST_SRC) -o $(BST_EXEC)

clean:
	rm -rf *.dSYM
	rm -f $(BTREE_EXEC)
	rm -f $(BST_EXEC)
	rm -f $(AVL_EXEC)
	rm -f $(RBT_EXEC)