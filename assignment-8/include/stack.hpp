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

#include <stdexcept>

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
    this->cons(t);
  }
  /*
    * Returns the element at the top of the stack.
    * Also removes the top element from the stack.
    */
  T pop() {
    if (this->first_) {
      T data = this->first_->data_;
      this->remove(this->first_->data_);

      return data;
    } else {
      throw std::range_error("Stack empty, can't pop.");
    }
  }
  /*
    * Returns the element at the top of the stack.
    * Does not remove the top element.
    */
  T top() const {
    if (!this->first_) {
      throw std::range_error("Stack empty, can't see top.");
    }
    return this->first_->data_;
  }
  /*
    * Returns the number of elements currently in the stack.
    */
  int size() const {
    return this->length();
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
  virtual ~stack() {
    // Don't need to do anything here, list cleans up for us
  }
};
}

#endif
