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
 
 protected:
    virtual void put_under_node(BinaryNode<Key, Value>* node, const Key& key, const Value& value) {
        if (key == node->key) {
            node->val = value;
        } else if (key > node->key) {
            if (node->right) {
                put_under_node(node->right, key, value);
            } else {
                node->right = new BinaryNode<Key, Value> (key, value, this->root, node);
            }
        } else if (key < node->key) {
            if (node->left) {
                put_under_node(node->left, key, value);
            } else {
                node->left = new BinaryNode<Key, Value> (key, value, this->root, node);
            }
        }
    }

 public:
    virtual void put(const Key& key, const Value& value) override {
        if (!this->root) {
            this->root = new BinaryNode<Key, Value> (key, value, nullptr, nullptr);
            this->root= this->root;
        } else {
            put_under_node(this->root, key, value);
        }
    }

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
        this->print_in_order();
    }
};

}

#endif /* ifndef BSTREE_HPP */