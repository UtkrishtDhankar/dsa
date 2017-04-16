#ifndef AVL_HPP
#define AVL_HPP 1
#include "BSTree.hpp"

namespace cs202 {

template<class Key, class Value>
class AVLNode : public BinaryNode<Key, Value> {
public:
    int height = 0;

    AVLNode() {
    }

    AVLNode(Key in_key, Value in_value,
            BinaryNode<Key, Value>* r, BinaryNode<Key, Value>* p)
          : BinaryNode<Key, Value> (in_key, in_value, r, p) {
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
    int max(int a, int b) {
        return a > b ? a : b;
    }

    void increase_height_up_tree(AVLNode<Key, Value>* node) {
        while (node->parent) {
            AVLNode<Key, Value>* parent = dynamic_cast<AVLNode<Key, Value>* > (node->parent);
            AVLNode<Key, Value>* parent_left = dynamic_cast<AVLNode<Key, Value>*> (parent->left);
            AVLNode<Key, Value>* parent_right = dynamic_cast<AVLNode<Key, Value>*> (parent->right);
            if (parent_left && parent_right) {
                // Set the parent's height
                parent->height = 1 + max(parent_left->height, parent_right->height);
            } else if (parent_left) {
                parent->height = 1 + parent_left->height;
            } else if (parent_right) {
                parent->height = 1 + parent_right->height;
            } else {
                // we really shouldn't be here
                // TODO throw exception here
            }

            node = parent;
        }
    }

protected:
    // AVLNode<Key, Value>* root;

    virtual AVLNode<Key, Value>* put_under_node(BinaryNode<Key, Value>* node, const Key& key, const Value& value) override {
        if (key == node->key) {
            node->val = value;
            return dynamic_cast<AVLNode<Key, Value>*> (node);
        } else if (key > node->key) {
            if (node->right) {
                return put_under_node(node->right, key, value);
            } else {
                node->right = new AVLNode<Key, Value> (key, value, this->root, node);
                return dynamic_cast<AVLNode<Key, Value>*> (node->right);
            }
        } else if (key < node->key) {
            if (node->left) {
                return put_under_node(node->left, key, value);
            } else {
                node->left = new AVLNode<Key, Value> (key, value, this->root, node);
                return dynamic_cast<AVLNode<Key,Value>*> (node->left);
            }
        } else {
            return nullptr; // something has gone wrong if this happens
        }
    }

public:
    virtual void put(const Key& key, const Value& value) override {
        if (!this->root) {
            this->root = new AVLNode<Key, Value>(key, value, nullptr, nullptr);
            this->root->root = this->root;
            dynamic_cast<AVLNode<Key, Value>* > (this->root)->height = 0;

            // BinaryTree<Key, Value>::root = dynamic_cast<BinaryNode<Key, Value>* > (root);
        } else {
            AVLNode<Key, Value>* inserted_node = put_under_node(this->root, key, value);
            increase_height_up_tree(inserted_node);
        }
    }

    virtual int getHeight() override {
        return dynamic_cast<AVLNode<Key, Value>* > (this->root)->height;
    }

};

}

#endif /* ifndef AVL_HPP */