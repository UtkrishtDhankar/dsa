#ifndef AVL_HPP
#define AVL_HPP 1
#include "BSTree.hpp"

namespace cs202 {

template<class Key, class Value>
class AVLNode : public BinaryNode<Key, Value> {
public:
    Key key;
    Value val;
    AVLNode<Key,Value> * root, * left, * right, * parent;

    int height;

    AVLNode() {
        height = 0;
    }

    AVLNode(Key in_key, Value in_value,
                AVLNode<Key, Value>* r, AVLNode<Key, Value>* p)
          : key(in_key), val(in_value), root(r), parent(p) {
        left = right = nullptr;
        height = 0;
    }
};

template <class Key, class Value>
class AVL : public BSTree<Key, Value> {
/*
 * Inherit as much functionality as possible from the BSTree class.
 * Then provide custom AVL Tree functionality on top of that.
 * The AVL Tree should make use of as many BST functions as possible.
 * Override only those methods which are extremely necessary.
 */
/*
 * Apart from that, your code should have the following four functions:
 * getBalance(node) -> To get the balance at any given node;
 * doBalance(node) -> To fix the balance at the given node;
 * rightRotate(node) -> Perform a right rotation about the given node.
 * leftRotate(node) -> Perform a left rotation about the given node.
 *
 * The signature of these functions are not provided in order to provide you
 * some flexibility in how you implement the internals of your AVL Tree. But
 * make sure these functions are there.
 */
private:
    void increase_height_up_tree(AVLNode<Key, Value>* node) {
        while (node->parent) {
            AVLNode<Key, Value>* parent = node->parent;
            if (parent->left && parent->right) {
                // Set the parent's height
                parent->height = 1 
                    + parent->left->height > parent->right->height 
                    ? parent->left->height : parent->right->height;
            } else if (parent->left) {
                parent->height = 1 + parent->left->height;
            } else if (parent->right) {
                parent->height = 1 + parent->right->height;
            } else {
                // we really shouldn't be here
                // TODO throw exception here
            }

            node = parent;
        }
    }

protected:
    AVLNode<Key, Value>* root;

    virtual AVLNode<Key, Value>* put_under_node(AVLNode<Key, Value>* node, const Key& key, const Value& value) {
        if (key == node->key) {
            node->val = value;
            return node;
        } else if (key > node->key) {
            if (node->right) {
                return put_under_node(node->right, key, value);
            } else {
                node->right = new AVLNode<Key, Value> (key, value, this->root, node);
                return node->right;
            }
        } else if (key < node->key) {
            if (node->left) {
                return put_under_node(node->left, key, value);
            } else {
                node->left = new AVLNode<Key, Value> (key, value, this->root, node);
                return node->left;
            }
        } else {
            return nullptr; // something has gone wrong if this happens
        }
    }

public:
    virtual void put(const Key& key, const Value& value) override {
        if (!root) {
            root = new AVLNode<Key, Value>(key, value, nullptr, nullptr);
            root->root = root;
            root->height = 0;
        } else {
            AVLNode<Key, Value>* inserted_node = put_under_node(root, key, value);
            increase_height_up_tree(inserted_node);
        }
    }

};

}

#endif /* ifndef AVL_HPP */