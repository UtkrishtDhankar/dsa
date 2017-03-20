# Assignment 3
Utkrisht Dhankar - B15138

## Compiling
You can use the provided `makefile` to compile everything. It uses `g++` with the C++11 standard.

The command `make` compiles all modules.

## Running

### `list`
Invoke with `./list`. An initially empty linked list is present. The following commands are available to modify/access it.

* `append (number)` appends the number to the end of the linked list.
* `cons (number)` puts number at the start of the linked list
* `remove (number)` removes the first occurrence of the number.
* `appendlist (list size) (number1) (number2) ...` appends a list of size `list size` with the elements `number1`, `number2` and so on.
* `print` prints the contents of the list

### `stack`
Invoke with `./stack`. An initially empty stack is present. The following commands are available to modify/access it.

* `push (number)` pushes number onto the stack
* `pop` pops the top of the stack and prints it
* `top` peeks at the top of the stack without popping it
* `size` prints the size of the stack
* `empty` prints whether the stack is empty

### `queue`
Invoke with `./queue`. An initially empty queue is present. The following commands are available to modify/access it.

* `push (number)` enqueues or pushes number onto the queue
* `pop` dequeues or pops the top of the queue and prints it
* `front` peeks at the front of the queue without popping it
* `size` prints the size of the queue
* `empty` prints whether the queue is empty

### `problem`
This implements a solution to problem 5 from the assignment.
