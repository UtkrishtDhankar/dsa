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
 
private:
    int max(const int& a, const int&b) {
        return a > b ? a : b;
    }
protected:
    
    virtual int height_under_node(BinaryNode<Key, Value>* node) {
        if (node)
            return 1 + max(height_under_node(node->right), height_under_node(node->left));
        else
            return 0;
    }

    virtual int size_under_node(BinaryNode<Key, Value>* node) {
        if (node) {
            return 1 + size_under_node(node->left) + size_under_node(node->right);
        } else {
            return 0;
        }
    }

    virtual BinaryNode<Key, Value>* has_child_with_key(BinaryNode<Key, Value>* node, Key k) override {
        if (node->key == k) {
            return node;
        } else if (k < node->key) {
            if (node->left) {
                return has_child_with_key(node->left, k);
            } else {
                return nullptr;
            }
        } else if (k > node->key) {
            if (node->right) {
                return has_child_with_key(node->right, k);
            } else {
                return nullptr;
            }
        } else {
            return nullptr; // This really shouldn't happen btw
        }
    }

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

    virtual Key find_descendant_with_min_key(BinaryNode<Key, Value>* node) override {
        Key min = node->key;
        if (node->left) {
            min = find_descendant_with_min_key(node->left);
        }

        return min;
    }
  
    virtual Key find_descendant_with_max_key(BinaryNode<Key, Value>* node) override {
        Key max = node->key;

        if (node->right) {
            max = find_descendant_with_max_key(node->right);
        }

        return max;
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
        return height_under_node(this->root);
    }
    /*
    * This method returns the total number of elements in the binary search tree.
    */
    virtual int size() {
        // TODO implement
        return size_under_node(this->root);
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