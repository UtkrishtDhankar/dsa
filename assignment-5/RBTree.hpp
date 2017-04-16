#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "BSTree.hpp"
/* The color enumeration.
 * Please use this and not integers or characters to store the color of the node
 * in your red black tree.
 * Also create a class RBTNode which should inherit from BinaryNode and has the attribute color in it. 
 */
enum Color { RED, BLACK };

namespace cs202 {

template<class Key, class Value>
class RBNode : public BinaryNode<Key, Value> {
public:
	
	Color c;

	RBNode() {
		c = BLACK;
	}

	RBNode(Key in_key, Value in_value, BinaryNode<Key, Value>* r, BinaryNode<Key, Value>* p)
		: BinaryNode<Key, Value> (in_key, in_value, r, p) {
		c = BLACK;
	}

	RBNode(Key in_key, Value in_value, Color c_in, BinaryNode<Key, Value>* r, BinaryNode<Key, Value>* p)
		: BinaryNode<Key, Value> (in_key, in_value, r, p) {
		c = c_in;	
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

typedef RBNode<Key, Value> node_ptr ;

/* Function insertRBFixup
*
* Used for:
* Used after an insertion in the rb tree.
* It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
*/
void insertRBFixup(node_ptr root);

/* Function deleteRBFixup
* Used for:
* Used after a deletion in the rb tree.
* It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
*/
void deleteRBFixup(node_ptr root);

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
};

}
#endif /* ifndef RBTree_HPP_ */