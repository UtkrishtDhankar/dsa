/*
 * OpenMap.hpp
 *
 *This is a Hash Table interface using Linear Probing
 */

#ifndef OPENMAP_HPP_
#define OPENMAP_HPP_

#include <stdexcept>

#include "Dictionary.hpp"
#include "include/seq_linear_list.hpp"

namespace cs202
{

template<class Key, class Value>
struct OpenMapData {
  OpenMapData() {
    key = Key(); value = Value();
    deleted = false;
    filled = false;
  }

  OpenMapData(const OpenMapData<Key, Value>& other) {
    key = other.key;
    value = other.value;
    deleted = false;
    filled = false;
  }

  OpenMapData(const Key& k, const Value& v) : key(k), value(v) {
    deleted = false;
    filled = false;
  }

  bool operator==(const OpenMapData<Key, Value>& other) const {
    return (key == other.key && value == other.value && deleted = other.deleted && filled = other.filled);
  }

  Key key;
  Value value;
  bool deleted;
  bool filled;
};

template<class Key, class Value>
class OpenMap  : public Dictionary<Key,Value>
{
private:
    /*
     * Function rehash:
     * Resizes the has table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
	void rehash() {
    // TODO make this
  }


  // Returns the location for a key
  int loc_for_key(Key key) const {
    return key_hash(key) % map.capacity();
  }

  static constexpr size_t default_size = 101;
  LinearList<OpenMapData<Key, Value> > map;
  hash<Key> key_hash;

  unsigned int num_filled;


public:

    /*
     * Constructor: OpenMap
     * Creates a Open Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	OpenMap(hash<Key> hash_func) :
    map(default_size, OpenMapData<Key, Value> ()), key_hash(hash_func)
  {
    num_filled = 0;
  }

    /*
     * Constructor:OpenMap
     * Creates an empty Open Map with the ability to hold atleast num Key value pairs.
     */
	OpenMap(const int& num, hash<Key> hash_func) :
    map(num, OpenMapData<Key, Value> ()), key_hash(hash_func)
  {
    num_filled = 0;
  }

    /*
     * Constructor: Open Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	OpenMap(OpenMap<Key, Value>& ht) :
    map(ht.map), key_hash(ht.key_hash)
  {
    num_filled = 0;
  }

    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~OpenMap() {
    // Nothing to do here, everything cleans itself up
  }

  /*
   * Function : has
   * Returns true if the dictionay contains the key
   * false otherwise. It is search operation
   */
	virtual bool has(const Key& key) {
    bool found = false;

    int num_checked = 0;
    int i = loc_for_key(key);
    for(; num_checked < map.capacity(); i = (i + 1) % map.capacity(), num_checked++) {
      if (map[i].key == key && map[i].filled && !map[i].deleted) {
        found  = true;
        break; // We've found a spot to put it in
      }
    }

    return found;
  }

  /*
   * Function : remove
   * Removes the given key and the corresponding value from the Dictionary if the key is in the dictionary.
   * Does nothing otherwise.
   */
	virtual void remove(const Key& key) {
    bool found = false;

    auto it = map.begin();
    for (; it != map.end(); it++) {
      if ((*it).key == key && (*it).filled && !(*it).deleted) {
        found = true;
        break;
      }
    }

    if (found) {
      (*it).deleted = true;
      (*it).key = Key();
      (*it).value = Value();
    }
  }

  /*
   * Function : get
   * Returns the value associated with the given key.
   * Raises an exception if the key does'nt exist in the dictionary.
   */
	virtual Value& get(const Key& key) {
    bool found = false;

    auto it = map.begin();
    for (; it != map.end(); it++) {
      if ((*it).key == key && (*it).filled && !(*it).deleted) {
        found = true;
        break;
      }
    }

    if (!found) {
      throw std::invalid_argument("Key not found in dictionary.");
    }

    return (*it).value;
  }

  /*
   * Function : put
   * If the key does'nt exist in the dictionary, then insert the given key and value in the dictionary.
   * Otherwise change the value associated with the key to the given value.
   */
	virtual void put(const Key& key, const Value& value) {
    int num_checked = 0;

    if (num_filled == map.capacity()) {
      rehash();
    }

    int i = loc_for_key(key);
    for(; num_checked < map.capacity(); i = (i + 1) % map.capacity(), num_checked++) {
      if (map[i].key == key && map[i].filled && !map[i].deleted) {
        map[i].value = value;
        return; // We're done
      } if (!map[i].filled && !map[i].deleted) {
        break; // We've found a spot to put it in
      }
    }

    // If we're here, then we've found a spot to put the thing in
    map[i].key = key;
    map[i].value = value;
    map[i].filled = true;
  }

    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * OpenMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
	Value& operator[](const Key& key) {
    if (!has(key)) {
      put(key, Value());
    }

    return get(key);
  }
};

template<class Key, class Value>
constexpr size_t OpenMap<Key, Value>::default_size;
}

#endif
