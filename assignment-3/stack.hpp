/*
 * stack.hpp
 *
 * define your methods in coherence with the following
 * function signatures
 *
 * use the abstraction of linked lists
 * to implement the functionality of stacks
 *
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include "list.hpp"

namespace cs202
{
template<typename T>
class stack : protected list<T>
{
public:
  /*
    * Constructs a new stack.
    */
  stack() : list<T>() {}
  /*
    * Pushes t to on the top of the stack.
    */
  void push(const T& t) {
    cons(t);
  }
  /*
    * Returns the element at the top of the stack.
    * Also removes the top element from the stack.
    */
  T pop() {
    if (first_) {
      T data = first_->data_;
      remove(first_->data_);

      return data;
    } else {
      // TODO throw exception
    }
  }
  /*
    * Returns the element at the top of the stack.
    * Does not remove the top element.
    */
  T top() const {
    if (!first_) {
      // TODO throw exception
    }
    return first_->data_;
  }
  /*
    * Returns the number of elements currently in the stack.
    */
  int size() const {
    return length();
  }
  /*
    * Returns a boolean indicating whether the stack is empty or not.
    */

  inline bool empty() {
    return (size() == 0);
  }
  /*
    * Destructor
    * Fress the memory occupied by the stack elements.
    */
  virtual ~stack();
};
}

#endif
