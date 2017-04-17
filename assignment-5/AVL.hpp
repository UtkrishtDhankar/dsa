#ifndef AVL_HPP
#define AVL_HPP 1
#include "BSTree.hpp"

namespace cs202 {

template<class Key, class Value>
class AVLNode : public BinaryNode<Key, Value> {
public:
    int height;

    AVLNode() {
        height = 1;
    }

    AVLNode(Key in_key, Value in_value,
            BinaryNode<Key, Value>* r, BinaryNode<Key, Value>* p)
          : BinaryNode<Key, Value> (in_key, in_value, r, p) {
        height = 1;
    }

    AVLNode<Key, Value>* get_parent() {return dynamic_cast<AVLNode<Key, Value>*> (this->parent);}
    AVLNode<Key, Value>* get_root() {return dynamic_cast<AVLNode<Key, Value>*> (this->root);}
    AVLNode<Key, Value>* get_left() {return dynamic_cast<AVLNode<Key, Value>*> (this->left);}
    AVLNode<Key, Value>* get_right() {return dynamic_cast<AVLNode<Key, Value>*> (this->right);}
};

template <class Key, class Value>
class AVL : public BSTree<Key, Value> {

private:
    int max(int a, int b) {
        return a > b ? a : b;
    }

    int get_height_of(AVLNode<Key, Value>* node) {
        if (node) {
            if (node->get_left() && node->get_right()) {
                return 1 + max(node->get_left()->height, node->get_left()->height);
            } else if (node->get_left()) {
                return 1 + node->get_left()->height;
            } else if (node->get_right()) {
                return 1 + node->get_right()->height;
            } else {
                return 1;
            }
        } else {
            return 0;
        }
    }

    // fixes the height of a node, assuming the height of it's subtrees is correct
    void fix_height_of_node(AVLNode<Key, Value>* node) {
        node->height = 1 + max(get_height_of(node->get_left()), get_height_of(node->get_right()));
    }

    void increase_height_up_tree(AVLNode<Key, Value>* node) {
        while (node->parent) {
            AVLNode<Key, Value>* parent = dynamic_cast<AVLNode<Key, Value>* > (node->parent);

            parent->height = get_height_of(parent);

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

    int compute_balance_factor(AVLNode<Key, Value>* node) {
        if (node->left && node->right) {
            return get_height_of(node->get_left()) - get_height_of(node->get_right());
        } else if (node->get_left()) {
            return get_height_of(node->get_left());
        } else {
            return - get_height_of(node->get_right());
        }
    }

    void fixup_at(AVLNode<Key, Value>* inserted_node) {
        AVLNode<Key, Value>* cur = inserted_node;
        
        if (!cur) {
            return;
        }

        while (cur->parent) {
            cur = cur->get_parent();
            int bf = compute_balance_factor(cur);

            if (bf == 2) {
                AVLNode<Key, Value>* left = cur->get_left();
                if (compute_balance_factor(left) == 1) {
                    this->right_rotation_at(cur);

                    fix_height_of_node(cur);
                    fix_height_of_node(left);
                } else {
                    if (compute_balance_factor(left) == -1) {
                        this->left_rotation_at(left);
                    }
                    this->right_rotation_at(cur);

                    fix_height_of_node(cur);
                    fix_height_of_node(left);
                    fix_height_of_node(cur->get_parent());
                }
            } else if (bf == -2) {
                AVLNode<Key, Value>* right = cur->get_right();
                if (compute_balance_factor(right) == -1) {
                    this->left_rotation_at(cur);

                    fix_height_of_node(cur);
                    fix_height_of_node(right);
                } else {
                    if (compute_balance_factor(right) == 1) {
                        this->right_rotation_at(right);
                    }
                    this->left_rotation_at(cur);

                    fix_height_of_node(cur);
                    fix_height_of_node(right);
                    fix_height_of_node(cur->get_parent());
                }
            } else {
                fix_height_of_node(cur);
            }
        }
    }

public:
    virtual void put(const Key& key, const Value& value) override {
        if (!this->root) {
            this->root = new AVLNode<Key, Value>(key, value, nullptr, nullptr);
            this->root->root = this->root;
            dynamic_cast<AVLNode<Key, Value>* > (this->root)->height = 1;

            // BinaryTree<Key, Value>::root = dynamic_cast<BinaryNode<Key, Value>* > (root);
        } else {
            AVLNode<Key, Value>* inserted_node = put_under_node(this->root, key, value);
            increase_height_up_tree(inserted_node);
            fixup_at(inserted_node);
        }
    }

    virtual void remove(const Key& key) override {
        auto node_to_remove = this->has_child_with_key(this->root, key);
        auto parent = node_to_remove->parent;

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

            parent = node_to_remove->parent;
            delete node_to_remove;
        } else if (node_to_remove->left && node_to_remove->right) {
            // node has two children
            auto successor = this->find_descendant_just_larger_than_key(this->root, node_to_remove->key);
            node_to_remove->key = successor->key;
            node_to_remove->val = successor->val;

            if (successor->parent->left == successor) {
                successor->parent->left = nullptr;
            } else {
                successor->parent->right = nullptr;
            }

            parent = successor->parent;
            delete successor;
        } else {
            // node has one child
            BinaryNode<Key, Value>* child;
            if (node_to_remove->left) {
                child = node_to_remove->left;
            } else {
                child = node_to_remove->right;
            }

            if (node_to_remove->parent) {
                if (node_to_remove->parent->left == node_to_remove) {
                    node_to_remove->parent->left = child;
                } else {
                    node_to_remove->parent->right = child;
                }
            } else {
                this->root = child;
                child->root = child;
            }

            parent = node_to_remove->parent;
            delete node_to_remove;
        }

        auto avl_parent = dynamic_cast<AVLNode<Key, Value>*> (parent);
        fixup_at(avl_parent);
    }

    virtual int getHeight() override {
        AVLNode<Key, Value>* avl_root = dynamic_cast<AVLNode<Key, Value>* > (this->root);

        return avl_root->height;
    }
    

};

}

#endif /* ifndef AVL_HPP */