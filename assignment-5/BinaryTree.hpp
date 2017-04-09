#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
#include <stdexcept>

namespace cs202 {

template <class Key, class Value>
class BinaryNode
{
public:
    Key key;
    Value val;
    BinaryNode<Key,Value> * root, * left, * right, * parent;

    /* Default constructor. Should assign the default value to key and value
     */
    BinaryNode() {
        root = this;

        left = right = parent = nullptr;

        // key and val should be initialized to their default values
    }

    /* This contructor should assign the key and val from the passed parameters
     */
     BinaryNode(Key in_key, Value in_value,
                BinaryNode<Key, Value>* r, BinaryNode<Key, Value>* p)
          : key(in_key), val(in_value), parent(p), root(r) {
        left = right = nullptr;
    }
};

template<class Key, class Value>
class BinaryTree
{
	/* You can implement your own helper functions whenever required.
	 */

    inline bool get_ith_bit(int num, int i) {
        return (num >> i & 1);
    }

    int current_level = -1; // What level nodes is completely full? At the start, no level is full, so -1
    int nodes_in_next_level = 0; // How many nodes are full in the next level?
    
    BinaryNode<Key, Value>* get_node_to_insert_at() {
        BinaryNode<Key, Value>* node_to_insert_at = root;

        if (current_level == -1) {
            current_level = 0;
            return root;
        }

        for (int counter = current_level; counter > 0; counter--) {
            if (get_ith_bit(nodes_in_next_level, counter)) {
                node_to_insert_at = node_to_insert_at->right;
            } else {
                node_to_insert_at = node_to_insert_at->left;
            }
        }

        nodes_in_next_level++;
        if (nodes_in_next_level >= (1 << (current_level+ 1))) {
            current_level++;
            nodes_in_next_level = 0;
        } 

        return node_to_insert_at;
     }

    void decrement_num_nodes() {
        if (nodes_in_next_level == 0) {
        current_level--;
        nodes_in_next_level = (1 << (current_level + 1)) - 1;
        } else {
            nodes_in_next_level--;
        }
    }

     BinaryNode<Key, Value>* get_node_to_delete_at() {
        if (current_level == -1) {
            return nullptr; // can't delete an element when tree is empty
        } else if (current_level == 0) {
            return root; // Have to delete the root
        }

         decrement_num_nodes();

         auto node_to_deletes_parent = get_node_to_insert_at();

         if (node_to_deletes_parent->right) {
            return node_to_deletes_parent->right;
         } else {
             return node_to_deletes_parent->left;
         }
     }

protected:
    BinaryNode<Key, Value> * root;

    virtual Key find_descendant_with_min_key(BinaryNode<Key, Value>* node) {
        Key min = node->key;
        if (node->left) {
            Key left_min = find_descendant_with_min_key(node->left);
            if (left_min < min) {
                min = left_min;
            }
        }

        if (node->right) {
            Key right_min = find_descendant_with_min_key(node->right);
            if (right_min < min) {
                min = right_min;
            }
        }

        return min;
    }
  
    virtual Key find_descendant_with_max_key(BinaryNode<Key, Value>* node) {
        Key max = node->key;
        if (node->left) {
            Key left_max = find_descendant_with_max_key(node->left);
            if (left_max > max) {
                max = left_max;
            }
        }

        if (node->right) {
            Key right_max = find_descendant_with_max_key(node->right);
            if (right_max > max) {
                max = right_max;
            }
        }

        return max;
    }

    virtual BinaryNode<Key, Value>* find_descendant_just_larger_than_key(BinaryNode<Key, Value>* node, Key key) {
        auto successor = node;

        bool valid_succ = true;
        if (successor->key <= key) {
            valid_succ = false;
        }

        if (node->left) {
            auto left_succ = find_descendant_just_larger_than_key(node->left, key);
            if (left_succ->key > key && (left_succ->key - key < successor->key - key || !valid_succ)) {
                successor = left_succ;
                valid_succ = true;
            }
        }

        if (node->right) {
            auto right_succ = find_descendant_just_larger_than_key(node->right, key);
            if (right_succ->key > key && (right_succ->key - key < successor->key - key || !valid_succ)) {
                successor = right_succ;
                valid_succ = true;
            }
        }

        return successor;
    }

    virtual Key find_descendant_just_smaller_than_key(BinaryNode<Key, Value>* node, Key key) {
        Key predecessor = node->key;

        bool valid_pred = true;
        if (predecessor >= key) {
            valid_pred = false;
        }

        if (node->left) {
            Key left_pred = find_descendant_just_smaller_than_key(node->left, key);
            if (left_pred < key && (key - left_pred < key - predecessor || !valid_pred)) {
                predecessor = left_pred;
                valid_pred = true;
            }
        }

        if (node->right) {
            Key right_pred = find_descendant_just_smaller_than_key(node->right, key);
            if (right_pred < key && (key - right_pred < key - predecessor || !valid_pred)) {
                predecessor = right_pred;
                valid_pred = true;
            }
        }

        return predecessor;
    }

    virtual BinaryNode<Key, Value>* has_child_with_key(BinaryNode<Key, Value>* node, Key k) {
        if (node == nullptr) {
            return nullptr;
        } else if (node->key == k) {
            return node;
        } else {
            BinaryNode<Key, Value>* left = has_child_with_key(node->left, k);
            BinaryNode<Key, Value>* right = has_child_with_key(node->right, k);

            if (left) {
                return left;
            } else if (right) {
                return right;
            } else {
                return nullptr;
            }
        }
    }


     virtual void print_node_in_order(BinaryNode<Key, Value>* node) {
         if (node) {
             print_node_in_order(node->left);
             std::cout << node->key << ": " << node->val << std::endl;
             print_node_in_order(node->right);
         }
     }

     virtual void print_node_post_order(BinaryNode<Key, Value>* node) {
         if (node) {
             print_node_post_order(node->left);
             print_node_post_order(node->right);
             std::cout << node->key << ": " << node->val << std::endl;
         }
     }

     virtual void print_node_pre_order(BinaryNode<Key, Value>* node) {
         if (node) {
             std::cout << node->key << ": " << node->val << std::endl;
             print_node_pre_order(node->left);
             print_node_pre_order(node->right);
         }
     }

public:

    BinaryTree() {
        root = nullptr;
    }

/* Implement get function to retrieve the value corresponding to given key in binary tree.
    */
    Value get(const Key& key) {
        auto node = has_child_with_key(root, key);

        if (node) {
            return node->val;
        } else {
            throw std::out_of_range("Can't get the key, it doesn't exist in the tree");
        }
              
    }

/* Implement remove function that can delete a node in binary tree with given key.
    */
    virtual void remove(const Key& key) {
        // TODO this should probably fix the mess it makes. It doesn't work really
        // This probably messes up the current_level and the nodes_in_next_level
        // This also somehow manages to delete two things at the same time sometimes?
        // Need to debug
        auto node = has_child_with_key(root, key);

        if (!node) {
            throw std::invalid_argument("Can't remove key, it doesn't exist in the tree.");
        }

        auto node_to_swap_with = get_node_to_delete_at();
        if (!node_to_swap_with) {
            throw std::invalid_argument("Can't remove key, couldn't find node to swap it with'");
        } else if (node_to_swap_with == root && current_level == 0 && nodes_in_next_level == 0) {
            // In this case we have to delete the last element in the tree, so we just remove root
            root = nullptr;
            decrement_num_nodes();
            return;
        }

        Key node_key = node->key;
        Value node_value = node->val;

        node->key = node_to_swap_with->key;
        node->val = node_to_swap_with->val;

        node_to_swap_with->key = node_key;
        node_to_swap_with->val = node_value;

        if (node_to_swap_with->parent->left == node_to_swap_with) {
            node_to_swap_with->parent->left = nullptr;   
        } else {
            node_to_swap_with->parent->right = nullptr;   
        }

        decrement_num_nodes();

    }

/* Implement has function which will return true if the given key is present in binary tree
    * otherwise return false.
    */
    virtual bool has(const Key& key) {
        return has_child_with_key(root, key);
    }

/* Implement put function such that newly inserted node keep the tree balanced.
    */
    virtual void put(const Key& key, const Value& value) {
        if(auto existing_node = has_child_with_key(root, key)) {
            existing_node->val = value;
            return;
        }

        auto node = get_node_to_insert_at();

        if (node) {
            if (!node->left) {
                node->left = new BinaryNode<Key, Value>(key, value, root, node);
                node->left->parent = node;
            } else {
                node->right = new BinaryNode<Key, Value>(key, value, root, node);
                node->right->parent = node;
            }
        } else {
            node = new BinaryNode<Key, Value>(key, value, nullptr, node);
            node->root = node;
            root = node;
        }
    }

/*
    * This method print all the key value pairs of the binary tree, as
    * observed in an in order traversal.
    */
    virtual void print_in_order() {
        print_node_in_order(root);        
    }

/*
    * This method print all the key value pairs of the binary tree, as
    * observed in an pre order traversal.
    */
    virtual void print_pre_order() {
       print_node_pre_order(root); 
    }

/*
    * This method print all the key value pairs of the binary tree, as
    * observed in a post order traversal.
    */
    virtual void print_post_order() {
        print_node_post_order(root); 
    }

    /*
     * This method returns the minimum element in the binary tree.
     */
    virtual Key minimum() {
        if (!root) {
            throw std::range_error("Can't find minimum of an empty tree.");
        }

        return find_descendant_with_min_key(root); 
    }

    /*
     * This method returns the maximum element in the binary tree.
     */
    virtual Key maximum() {
        if (!root) {
            throw std::range_error("Can't find maximum of an empty tree.");
        }

        return find_descendant_with_max_key(root); 
    }

    /*
     * This method returns the successor, i.e, the next larget element in the
     * binary tree, after Key.
     */
    virtual Key successor(const Key& key) {
        Key succ = find_descendant_just_larger_than_key(root, key)->key; 
        if (succ > key) {
            return succ;
        } else {
            throw std::invalid_argument("No successor for requested key in node");
        }
    }

    /*
     * This method returns the predessor, ie, the next smallest element in the
     * binary tree, after Key.
     */
    virtual Key predecessor(const Key& key) {
        Key pred = find_descendant_just_smaller_than_key(root, key); 
        if (pred < key) {
            return pred;
        } else {
            throw std::invalid_argument("No predecessor for requested key in node");
        }
    }
};

}

#endif /* ifndef BINARYTREE_HPP */
