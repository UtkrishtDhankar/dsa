CC=g++
CFLAGS=-std=c++11 -Wall -Werror

UNDIRECTED_EXEC=undirected
UNDIRECTED_SRC=UndirectedGraphDriver.cpp

DIRECTED_EXEC=directed
DIRECTED_SRC=DirectedGraphDriver.cpp

FLOODFILL_EXEC=floodfill
FLOODFILL_SRC=FloodFill.cpp

all: undirected directed floodfill

debug: CFLAGS+= -g
debug: all

undirected:
	$(CC) $(CFLAGS) $(UNDIRECTED_SRC) -o $(UNDIRECTED_EXEC)

directed:
	$(CC) $(CFLAGS) $(DIRECTED_SRC) -o $(DIRECTED_EXEC)

floodfill:
	$(CC) $(CFLAGS) $(FLOODFILL_SRC) -o $(FLOODFILL_EXEC)

clean:
	rm -rf *.dSYM
	rm -f $(UNDIRECTED_EXEC)
	rm -f $(DIRECTED_EXEC)
	rm -f $(FLOODFILL_EXEC)