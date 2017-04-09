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

    virtual BinaryNode<Key, Value>* find_descendant_just_larger_than_key(BinaryNode<Key, Value>* node, Key key) override {
        BinaryNode<Key, Value>* successor = nullptr;

        BinaryNode<Key, Value>* current = has_child_with_key(this->root, key);
        if (!current) {
            throw std::invalid_argument("Can't find successor to key that doesn't exist.");
        }

        if (current->right) {
            auto temp = current->right;
            while (temp->left)
                temp = temp->left;

            successor = temp;
        } else {
            auto temp = current;
            while (temp->parent && temp->parent->left != temp) {
                temp = temp->parent;
            }

            successor = temp->parent;
        }

        return successor;
    }

    virtual BinaryNode<Key, Value>* find_descendant_just_smaller_than_key(BinaryNode<Key, Value>* node, Key key) override {
        BinaryNode<Key, Value>* predecessor = nullptr;

        BinaryNode<Key, Value>* current = has_child_with_key(this->root, key);
        if (!current) {
            throw std::invalid_argument("Can't find successor to key that doesn't exist.");
        }

        if (current->left) {
            auto temp = current->left;
            while (temp->right)
                temp = temp->right;

            predecessor = temp;
        } else {
            auto temp = current;
            while (temp->parent && temp->parent->right != temp) {
                temp = temp->parent;
            }

            predecessor = temp->parent;
        }

        return predecessor;
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

    virtual void remove(const Key& key) override {
        auto node_to_remove = has_child_with_key(this->root, key);

        if (!node_to_remove) {
            throw std::runtime_error("Can't remove a nonexisting key");
        }

        if (!node_to_remove->left && !node_to_remove->right) {
            // node is leaf
            if (node_to_remove->parent) {
                if (node_to_remove->parent->left == node_to_remove) {
                    node_to_remove->parent->left = nullptr;
                } else if (node_to_remove->parent->right == node_to_remove) {
                    node_to_remove->parent->right = nullptr;
                }
            } else {
                // node_to_remove must be the root
                this->root = nullptr;
            }

            delete node_to_remove;
        } else if (node_to_remove->left && node_to_remove->right) {
            // node has two children
            auto successor = find_descendant_just_larger_than_key(this->root, node_to_remove->key);
            node_to_remove->key = successor->key;
            node_to_remove->val = successor->val;

            if (successor->parent->left == successor) {
                successor->parent->left = nullptr;
            } else {
                successor->parent->right = nullptr;
            }

            delete successor;
        } else {
            // node has one child
            BinaryNode<Key, Value>* child;
            if (node_to_remove->left) {
                child = node_to_remove->left;
            } else {
                child = node_to_remove->right;
            }

            if (node_to_remove->parent->left == node_to_remove) {
                node_to_remove->parent->left = child;
            } else {
                node_to_remove->parent->right = child;
            }

            delete node_to_remove;
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