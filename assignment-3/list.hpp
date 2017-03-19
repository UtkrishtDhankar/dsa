/*
 * queue.hpp
 *
 * functionality of a singly linked-list
 *
 * define your methods in coherence with the following
 * function signatures
 */

#ifndef LIST_HPP
#define LIST_HPP 1

#include <cstddef>
#include <stdexcept>

namespace cs202
{

template<class T>
struct node {
  node() {
    next_ = nullptr;
  }

  node(const T& data) : data_(data) {
    next_ = nullptr;
  }

  T data_;
  node* next_;
};

template<class T>
class list {
  public:
    /*
     * Primary contructor.
     * Should construct an empty list.
     * Size of the created list should be zero.
     */
    list() {
      first_ = nullptr;
      size_ = 0;
    }

    /*
     * Secondary constructor.
     * Creates a new list which is a copy of the provided list.
     */
    list(const list<T> & x) {
      size_ = 0;
      first_ = nullptr;
      append(x);
    }

    /*
     * Frees all the memory acquired by the list.
     */
    virtual ~list() {
      node<T>* cur = first_;
      while (cur != nullptr) {
        node<T>* next = cur->next_;
        delete cur;
        cur = next;
      }
    }

    /*
     * adds value at the end of the list.
     */
    void append(const T& value) {
      node<T>* new_node = new node<T> (value);
      node<T>* end = get_end();

      if (end) {
        end->next_ = new_node;
      } else {
        first_ = new_node;
      }

      size_++;
    }

    /*
     * Returns the length of the list.
     */
    inline size_t length() const {
      return size_;
    }

    /*
     * Returns a boolean indicating whether the list is empty.
     */
    inline bool empty() const {
      return (size_ == 0);
    }

    /*
     * Adds a value to the front of the list.
     */
    void cons(const T& value) {
      node<T>* new_node = new node<T> (value);
      new_node->next_ = first_;

      first_ = new_node;

      size_++;
    }

    /*
     * Removes the first occurence of the value from list.
     */
    void remove(const T & x) {
      node<T>* cur = first_;
      node<T>* prev = nullptr;

      bool found = false;
      while (cur != nullptr) {
        if (cur->data_ == x) {
          found = true;
          break;
        }

        prev = cur;
        cur = cur->next_;
      }

      if (found) {
        if (prev) {
          prev->next_ = cur->next_;
        } else if (cur == first_) {
          first_ = cur->next_;
        }

        if (cur) {
          delete cur;
        }
      }

      size_--;
    }

    /*
      * Appends the given list x at the end of the current list.
      */
    void append(list<T>& x) {
      node<T>* end = get_end();
      node<T>* cur = x.first_;

      if (end == nullptr) {
        node<T>* new_node = new node<T>(cur->data_);
        first_ = new_node;
        end = new_node;

        cur = cur->next_;
      }

      while (cur != nullptr) {
        node<T>* new_node = new node<T>(cur->data_);
        end->next_ = new_node;
        end = new_node;

        cur = cur->next_;
      }

      size_ += x.length();
    }

    T operator[](unsigned int i) {
      if (i >= size_) {
        throw std::range_error("Can't access that element, it's out of bounds");
      }

      node<T>* cur = first_;
      for (unsigned int j = 0; j < i; j++) {
        cur = cur->next_;
      }

      return cur->data_;
    }

  protected:
    node<T>* first_;
    std::size_t size_;

    node<T>* get_end() {
      node<T>* end = first_;
      while (end != nullptr && end->next_ != nullptr) {
        end = end->next_;
      }

      return end;
    }
};
}

#endif
