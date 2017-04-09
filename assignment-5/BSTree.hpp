#ifndef BSTREE_HPP
#define BSTREE_HPP 1
#include "BinaryTree.hpp"

namespace cs202 {

template <class Key, class Value>
class BSTree : public BinaryTree<Key, Value> {

/* Inherit as many functions as possible from BinaryTree.
 * Only override those where you can decrease the time complexity and where you absolutely need to do it.
 * Also make sure that all inherited functions work correctly in the context of a binary search tree.
 */
 public:
    /*
    * This method returns the current height of the binary search tree.
    */
    virtual int getHeight() {
        // TODO implement
        return 0;
    }
    /*
    * This method returns the total number of elements in the binary search tree.
    */
    virtual int size() {
        // TODO implement
        return 0;
    }
    /*
    * This method prints the key value pairs of the binary search tree, sorted by
    * their keys.
    */
    virtual void print() {
        // TODO implement
    }
};

}

#endif /* ifndef BSTREE_HPP */