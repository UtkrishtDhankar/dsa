CC=g++
CFLAGS=-std=c++11

UNDIRECTED_EXEC=undirected
UNDIRECTED_SRC=UndirectedGraphDriver.cpp

DIRECTED_EXEC=directed
DIRECTED_SRC=DirectedGraphDriver.cpp

PRIM_EXEC=prim
PRIM_SRC=PrimProblem.cpp

KRUSKAL_EXEC=kruskal
KRUSKAL_SRC=KruskalProblem.cpp

all: undirected directed prim kruskal

debug: CFLAGS+= -g
debug: all

undirected:
	$(CC) $(CFLAGS) $(UNDIRECTED_SRC) -o $(UNDIRECTED_EXEC)

directed:
	$(CC) $(CFLAGS) $(DIRECTED_SRC) -o $(DIRECTED_EXEC)

prim:
	$(CC) $(CFLAGS) $(PRIM_SRC) -o $(PRIM_EXEC)

kruskal:
	$(CC) $(CFLAGS) $(KRUSKAL_SRC) -o $(KRUSKAL_EXEC)

clean:
	rm -rf *.dSYM
	rm -f $(UNDIRECTED_EXEC)
	rm -f $(DIRECTED_EXEC)
	rm -f $(KRUSKAL_EXEC)
	rm -f $(PRIM_EXEC)