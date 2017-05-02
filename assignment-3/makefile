CC=g++
CFLAGS=-std=c++11

LIST_EXEC=list
LIST_SRC=list_tester.cpp

STACK_EXEC=stack
STACK_SRC=stack_tester.cpp

QUEUE_EXEC=queue
QUEUE_SRC=queue_tester.cpp

PROBLEM_EXEC=problem
PROBLEM_SRC=problem.cpp


all: list stack queue problem

debug: CFLAGS+= -g
debug: all

list:
	$(CC) $(CFLAGS) $(LIST_SRC) -o $(LIST_EXEC)

stack:
	$(CC) $(CFLAGS) $(STACK_SRC) -o $(STACK_EXEC)

queue:
	$(CC) $(CFLAGS) $(QUEUE_SRC) -o $(QUEUE_EXEC)

problem:
	$(CC) $(CFLAGS) $(PROBLEM_SRC) -o $(PROBLEM_EXEC)

clean:
	rm -rf *.dSYM
	rm -f $(LIST_EXEC)
	rm -f $(STACK_EXEC)
	rm -f $(QUEUE_EXEC)
	rm -f $(PROBLEM_EXEC)

