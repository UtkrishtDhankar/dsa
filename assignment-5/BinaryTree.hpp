#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

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
                BinaryNode<Key, Value>* root, BinaryNode<Key, Value>* p)
          : key(in_key), val(in_value), parent(p) {
        root = this;

        left = right = nullptr;
    }
};

template<class Key, class Value>
class BinaryTree
{
	/* You can implement your own helper functions whenever required.
	 */

     int size = -1;

     BinaryNode<Key, Value>* get_node_to_insert_at() {
          BinaryNode<Key, Value>* node_to_insert_at = root;

          if (size > -1) {
               unsigned char first_non_zero_bit = 31;

               while (!((1 << first_non_zero_bit) & (size >> first_non_zero_bit)) && first_non_zero_bit)
                    first_non_zero_bit--;

               int num_bits_left = first_non_zero_bit;
               while (num_bits_left > 0) {
                    if ((1 << num_bits_left) & (size >> num_bits_left)) {
                         node_to_insert_at = node_to_insert_at->right;
                    } else {
                         node_to_insert_at = node_to_insert_at->left;
                    }

                    num_bits_left--;
               }
          }

          return node_to_insert_at;
     }

protected:
    BinaryNode<Key,Value> * root;

public:

     BinaryTree() {
          root = nullptr;
     }

    /* Implement get function to retrieve the value corresponding to given key in binary tree.
     */
     Value get(const Key& key) {
          // TODO implement
          return Key();
     }

    /* Implement remove function that can delete a node in binary tree with given key.
     */
     virtual void remove(const Key& key) {
          
     }

    /* Implement has function which will return true if the given key is present in binary tree
     * otherwise return false.
     */
     virtual bool has(const Key& key) {
          // TODO implement
          return false;
     }

    /* Implement put function such that newly inserted node keep the tree balanced.
     */
     virtual void put(const Key& key, const Value& value) {
          // TODO check if tree already has key. If so, set node to that value

          auto node = get_node_to_insert_at();

          if (node) {
               if (!node->left) {
                    node->left = new BinaryNode<Key, Value>(key, value, root, node);
                    node = node->left;
               } else {
                    node->right = new BinaryNode<Key, Value>(key, value, root, node);
                    node = node->right;
               }
          } else {
               node = new BinaryNode<Key, Value>(key, value, nullptr, node);
               node->root = node;
               root = node;
          }

          size++;
     }

    /*
     * This method print all the key value pairs of the binary tree, as
     * observed in an in order traversal.
     */
     virtual void print_in_order() {
          
     }

    /*
     * This method print all the key value pairs of the binary tree, as
     * observed in an pre order traversal.
     */
     virtual void print_pre_order() {
          
     }

    /*
     * This method print all the key value pairs of the binary tree, as
     * observed in a post order traversal.
     */
     virtual void print_post_order() {
          
     }

    /*
     * This method returns the minimum element in the binary tree.
     */
     virtual Key minimum() {
          
          // TODO implement
          return Key();
          
     }

    /*
     * This method returns the maximum element in the binary tree.
     */
     virtual Key maximum() {
          // TODO implement
          return Key();
     }

    /*
     * This method returns the successor, i.e, the next larget element in the
     * binary tree, after Key.
     */
     virtual Key successor(const Key& key) {
          // TODO implement
          return Key();
     }

    /*
     * This method returns the predessor, ie, the next smallest element in the
     * binary tree, after Key.
     */
     virtual Key predecessor(const Key& key) {
          // TODO implement
          return Key();
     }
};

}

#endif /* ifndef BINARYTREE_HPP */
