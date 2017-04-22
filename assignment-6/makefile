CC=g++
CFLAGS=-std=c++11 -Wall -Werror

INTERRUPT_EXEC=interrupt
INTERRUPT_SRC=Interrupts.cpp

MPQ_EXEC=mpq
MPQ_SRC=MinPriorityQueueDriver.cpp

all: interrupt mpq

debug: CFLAGS+= -g
debug: all

interrupt:
	$(CC) $(CFLAGS) $(INTERRUPT_SRC) -o $(INTERRUPT_EXEC)

mpq:
	$(CC) $(CFLAGS) $(MPQ_SRC) -o $(MPQ_EXEC)

clean:
	rm -rf *.dSYM
	rm -f $(INTERRUPT_EXEC)
	rm -f $(MPQ_EXEC)