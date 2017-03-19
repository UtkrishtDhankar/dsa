/*
 * queue.hpp
 *
 * define your methods in coherence with the following
 * function signatures
 * use the abstraction of linked lists
 * to implement the functionality of queues
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include "list.hpp"


namespace cs202
{
template <class T>
class queue : protected list<T>
{
public:
  /*
   * Constructs a new queue.
   */
  queue() {
    // nothing to see here, list handles everything
  }

  /*
   * Pushes t to at the back of the queue.
   */
  void push(const T& t) {
    this->append(t);
  }

  /*
   * Returns the element at the front of the queue.
   * Also removes the front element from the queue.
   */
  T pop() {
    this->remove(this->first_->data_);
  }

  /*
   * Returns the element at the front of the queue.
   * Does not remove the front element.
   */
  T front() {
    return this->first_->data_;
  }

  /*
   * Returns the number of elements currently in the queue.
   */
  inline int size() {
    return this->length();
  }

  /*
   * Returns a boolean indicating whether the queue is empty or not.
   */
  inline bool empty() {
    return (size() == 0);
  }

  /*
   * Destructor
   * Fress the memory occupied by the queue elements.
   */
  virtual ~queue() {
    // Nothing to do here, all's handled by the base class
  }
};
}
#endif
