/*
 * ChainedMap.hpp
 *
 */

#ifndef CHAINEDMAP_HPP_
#define CHAINEDMAP_HPP_

#include "Dictionary.hpp"
#include "include/list.hpp"
#include "include/seq_linear_list.hpp"

#include <functional>
#include <stdexcept>

namespace cs202
{

template<class Key, class Value>
struct ChainedMapData {
  ChainedMapData() {}
  ChainedMapData(const Key& k, const Value& v) : key(k), value(v) {}

  bool operator==(const ChainedMapData<Key, Value>& other) const {return (key == other.key && value == other.value);}

  Key key;
  Value value;
};

template<class Key, class Value>
class ChainedMap  : public Dictionary<Key,Value>
{
  // Returns the location for a key
  int loc_for_key(Key key) const {
    return key_hash(key) % table.size();
  }

  const size_t default_size = 101;
  LinearList<list<ChainedMapData<Key, Value> > > table;
  hash<Key> key_hash;


public:
    /*
     * Constructor: ChainedMap
     * Creates a Chained Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	ChainedMap(hash<Key> hash_functor) : table(default_size) {
    key_hash = hash_functor;
    // Empty linked lists have been created in each element of the table
  }
    /*
     * Constructor:ChainedMap
     * Creates an empty Chained Map with the ability to hold atleast num Key value pairs.
     */

	ChainedMap(const int& num, hash<Key> hash_functor) : table(num) {
    key_hash = hash_functor;
    // A table of size num has been created. It's up to the user to provide a size that's
    // performance efficient.
  }

    /*
     * Constructor: Chained Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	ChainedMap(ChainedMap<Key, Value>& ht) : table(ht.table) {
    // We've copied the table, nothing else is needed
  }

    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~ChainedMap() {
    // No resources to clean up
  }

    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * ChainedHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	Value& operator[](const Key& key) {
    if (!has(key)) {
      // This requires that value has a default constructor
      // won't work for everything.
      put(key, Value());
    } else {
      return get(key);
    }
  }

  /*
   * Function : has
   * Returns true if the dictionay contains the key
   * false otherwise. It is search operation
   */
	virtual bool has(const Key& key) {
    int loc = loc_for_key(key);

    list<ChainedMapData<Key, Value> > list_to_search = table[loc];

    bool contains = false;
    for (auto elem : list_to_search) {
      if (elem.key == key) {
        contains = true;
        break;
      }
    }

    return contains;
  }

  /*
   * Function : remove
   * Removes the given key and the corresponding value from the Dictionary if the key is in the dictionary.
   * Does nothing otherwise.
   */
	virtual void remove(const Key& key) {
    int loc = loc_for_key(key);

    bool found = false;
    auto it = table[loc].begin();
    for (;it != table[loc].end(); it++) {
      if ((*it).key == key) {
        found = true;
        break;
      }
    }

    if (found) {
      table[loc].remove(*it);
    }
  }

  /*
   * Function : get
   * Returns the value associated with the given key.
   * Raises an exception if the key doesn't exist in the dictionary.
   */
	virtual Value& get(const Key& key) {
    int loc = loc_for_key(key);

    list<ChainedMapData<Key, Value> > list_to_search = table[loc];

    bool found = false;
    auto it = list_to_search.begin();
    for (; it != list_to_search.end(); it++) {
      if ((*it).key == key) {
        found = true;
        break;
      }
    }

    if (found) {
      return (*it).value;
    } else {
      throw std::invalid_argument("Given key does not exist.");
    }
  }

  /*
   * Function : put
   * If the key does'nt exist in the dictionary, then insert the given key and value in the dictionary.
   * Otherwise change the value associated with the key to the given value.
   */
	virtual void put(const Key& key, const Value& value) {
    int loc = loc_for_key(key);

    list<ChainedMapData<Key, Value> > list_to_search = table[loc];

    bool contains_pair = false;
    bool contains_key_only = false;
    auto it = list_to_search.begin();
    for (; it != list_to_search.end(); it++) {
      if ((*it).key == key) {
        if ((*it).value == value) {
          contains_pair = true;
        } else {
          contains_key_only = true;
        }
        break;
      }
    }

    if (contains_key_only) {
      (*it).value = value;
    } else if (contains_pair) {
      // Do nothing, we already have all the things
    } else {
      list_to_search.cons(ChainedMapData<Key, Value>(key, value));
    }
  }
};
}

#endif /* CHAINEDMAP_HPP_ */
