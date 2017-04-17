#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "BSTree.hpp"
namespace cs202 {

/* The color enumeration.
 * Please use this and not integers or characters to store the color of the node
 * in your red black tree.
 * Also create a class RBTNode which should inherit from BinaryNode and has the attribute color in it. 
 */
enum Color { RED, BLACK };

/* 
 * What kind of child is this?
 */
enum ChildType { LEFT, RIGHT, ROOT};

template<class Key, class Value>
class RBNode : public BinaryNode<Key, Value> {
public:
    
    Color color;

    RBNode() {
        color = BLACK;
    }

    RBNode(Key in_key, Value in_value, BinaryNode<Key, Value>* r, BinaryNode<Key, Value>* p)
        : BinaryNode<Key, Value> (in_key, in_value, r, p) {
        color = BLACK;
    }

    RBNode(Key in_key, Value in_value, Color c_in, BinaryNode<Key, Value>* r, BinaryNode<Key, Value>* p)
        : BinaryNode<Key, Value> (in_key, in_value, r, p) {
        color = c_in;	
    }

    RBNode<Key, Value>* get_parent() {return dynamic_cast<RBNode<Key, Value>*> (this->parent);}
    RBNode<Key, Value>* get_root() {return dynamic_cast<RBNode<Key, Value>*> (this->root);}
    RBNode<Key, Value>* get_left() {return dynamic_cast<RBNode<Key, Value>*> (this->left);}
    RBNode<Key, Value>* get_right() {return dynamic_cast<RBNode<Key, Value>*> (this->right);}
};

template <class Key, class Value>
class RBTree : public BSTree<Key, Value> {
    /* 
        Inherit as many functions as possible from BSTree.
        Only override those which absolutely need it.
        Also make sure that all inherited functions work correctly in the context of a red black tree.
        node_ptr in the following piece of code refers to a pointer to the node you may be using for your red black tree.
        Use a typedef to refer to a pointer to your node via node_ptr
    */

    typedef RBNode<Key, Value>* node_ptr;

    // this returns the color of a node
    Color get_color_of(node_ptr node) {
        if (node) {
            return node->color;
        } else {
            return BLACK;
        }
    }

    void set_color_of(node_ptr node, Color c) {
        if (!node) {
            if (c == BLACK) {
                return;
            } else {
                throw std::invalid_argument("Can't set color of NIL node to black.");
            }
        } else {
            node->color = c;
        }
    }

    ChildType get_child_type_of(node_ptr node) {
        if (!node) {
            throw std::invalid_argument("Can't find child type of nullptr.");
        }

        if (node->get_parent()) {
            if (node->get_parent()->get_left() == node) {
                return LEFT;
            } else {
                return RIGHT;
            }
        } else {
            return ROOT;
        }
    }

    node_ptr get_sibling_of(node_ptr node) {
        ChildType ct = get_child_type_of(node);
        if (ct == LEFT) {
            return node->get_parent()->get_right();
        } else if (ct == RIGHT) {
            return node->get_parent()->get_left();
        } else {
            // ROOTs don't have siblings
            return nullptr;
        }
    }

    node_ptr get_uncle_of(node_ptr node) {
        if (!node) {
            return nullptr;
        } else {
            return get_sibling_of(node->get_parent());
        }
    }

    /* Function insertRBFixup
    *
    * Used for:
    * Used after an insertion in the rb tree.
    * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
    */
    void insertRBFixup(node_ptr node) {
        auto cur = node;
        auto parent = cur->get_parent();
        while (get_color_of(parent) == RED) {
            parent = cur->get_parent();
            auto uncle = get_uncle_of(cur);
            auto grandparent = parent->get_parent();
            
            // CASE 1
            if (get_child_type_of(parent) == LEFT && get_color_of(parent) == RED && get_color_of(uncle) == RED) {
                set_color_of(parent, BLACK);
                set_color_of(uncle, BLACK);
                set_color_of(grandparent, RED);

                cur = grandparent;
            } 

            // CASE 4, mirror of CASE 1
            else if (get_child_type_of(parent) == RIGHT && get_color_of(parent) == RED && get_color_of(uncle) == RED) {
                set_color_of(parent, BLACK);
                set_color_of(uncle, BLACK);
                set_color_of(grandparent, RED);

                cur = grandparent;
            }
            
            // CASE 2
            else if (get_child_type_of(cur) == RIGHT && get_child_type_of(parent) == LEFT && get_color_of(parent) == RED && get_color_of(uncle) == BLACK) {
                this->left_rotation_at(parent);

                cur = parent; // lead to case 3
            }

            // CASE 3
            else if (get_child_type_of(cur) == LEFT && get_child_type_of(parent) == LEFT && get_color_of(parent) == RED && get_color_of(uncle) == BLACK) {
                this->right_rotation_at(grandparent);

                set_color_of(parent, BLACK);
                set_color_of(parent->get_left(), RED);
                set_color_of(parent->get_right(), RED);
            }

            // CASE 5, mirror of case 2
            else if (get_child_type_of(cur) == LEFT && get_child_type_of(parent) == RIGHT && get_color_of(parent) == RED && get_color_of(uncle) == BLACK) {
                this->right_rotation_at(parent);

                cur = parent; // lead to case 6
            }

            // CASE 6, mirror of case 3
            else if (get_child_type_of(cur) == RIGHT && get_child_type_of(parent) == RIGHT && get_color_of(parent) == RED && get_color_of(uncle) == BLACK) {
                this->left_rotation_at(grandparent);

                set_color_of(parent, BLACK);
                set_color_of(parent->get_left(), RED);
                set_color_of(parent->get_right(), RED);
            }

            else {
                // this only happens when we've modified an element instead of trying to add a new one
                // so we just return
                return;
            }
        }
    }

    /* Function deleteRBFixup
    * Used for:
    * Used after a deletion in the rb tree.
    * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
    */
    void deleteRBFixup(node_ptr root);

protected:
    virtual node_ptr put_under_node(BinaryNode<Key, Value>* node, const Key& key, const Value& value) override {
        if (key == node->key) {
            node->val = value;
            return dynamic_cast<node_ptr> (node);
        } else if (key > node->key) {
            if (node->right) {
                return put_under_node(node->right, key, value);
            } else {
                node->right = new RBNode<Key, Value>(key, value, RED, this->root, node);
                return dynamic_cast<node_ptr> (node->right);
            }
        } else if (key < node->key) {
            if (node->left) {
                return put_under_node(node->left, key, value);
            } else {
                node->left = new RBNode<Key, Value>(key, value, RED, this->root, node);
                return dynamic_cast<node_ptr> (node->left);
            }
        } else {
            return nullptr; // something has gone wrong if this happens
        }
    }
public:
    /* Function : blackHeight
    * 
    * Returns:
    * the black height of the red black tree which begins at node_ptr root
    */
    int blackHeight(node_ptr root);	
    /*
    * Apart from these functions, also provide functions for rotations in the tree.
    * The signature of the rotation functions is omitted to provide you flexibility in how you implement the internals of your node.
    */

    virtual void put(const Key& key, const Value& value) override {
        if (!this->root) {
            this->root = new RBNode<Key, Value> (key, value, BLACK, nullptr, nullptr);
            this->root->root = this->root;
        } else {
            auto inserted_node = put_under_node(this->root, key, value);
            insertRBFixup(inserted_node);
        }
    }

};

}
#endif /* ifndef RBTree_HPP_ */