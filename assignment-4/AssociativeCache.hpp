#ifndef ASSOCIATIVE_HPP_
#define ASSOCIATIVE_HPP_

#include <stdexcept>
#include <iostream>
#include <limits>

#include "Dictionary.hpp"
#include "include/seq_linear_list.hpp"

namespace cs202
{

template<class Key, class Value>
struct AssociativeCacheData {
  AssociativeCacheData() {
    key = Key(); value = Value();
    filled = false;
  }

  AssociativeCacheData(const AssociativeCacheData<Key, Value>& other) {
    key = other.key;
    value = other.value;
    filled = other.filled;
  }

  AssociativeCacheData(const Key& k, const Value& v) : key(k), value(v) {
    filled = false;
  }

  bool operator==(const AssociativeCacheData<Key, Value>& other) const {
    return (key == other.key && value == other.value && filled = other.filled);
  }

  Key key;
  Value value;
  bool filled;
};

template<class Key, class Value>
class AssociativeCache : public Dictionary<Key,Value>
{
private:
  LinearList<AssociativeCacheData<Key, Value> > map;
  LinearList<int> usage;

public:

    /*
     * Constructor:OpenMap
     * Creates an empty Open Map with the ability to hold atleast num Key value pairs.
     */
	AssociativeCache(const int& num) :
    map(num, AssociativeCacheData<Key, Value> ()), usage(num, 0)
  {}

    /*
     * Constructor: Open Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	AssociativeCache(AssociativeCache<Key, Value>& ht) :
    map(ht.map), usage(ht.usage)
  {
  }

    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~AssociativeCache() {
    // Nothing to do here, everything cleans itself up
  }

  const LinearList<AssociativeCacheData<Key, Value> >& get_data() {return map;}
  const LinearList<int>& get_usage() {return usage;}

  /*
   * Function : has
   * Returns true if the dictionay contains the key
   * false otherwise. It is search operation
   */
	virtual bool has(const Key& key) {
    bool found = false;

    for(auto elem : map) {
      if (elem.key == key && elem.filled) {
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

    int i = 0;
    for (; i < map.size(); i++) {
      if (map[i].key == key && map[i].filled) {
        found = true;
        break;
      }
    }

    if (found) {
      map[i].filled = false;
      usage[i] = map.capacity();
    }
  }

  /*
   * Function : get
   * Returns the value associated with the given key.
   * Raises an exception if the key does'nt exist in the dictionary.
   */
	virtual Value& get(const Key& key) {
    bool found = false;

    int i = 0;
    for(; i < map.size(); i++) {
      if (map[i].key == key && map[i].filled) {
        found = true;
        break;
      }
    }

    if (!found) {
      throw std::invalid_argument("Key not found in dictionary.");
    }

    for (auto elem : usage) {
      elem++;
    }
    usage[i] = 0;

    return map[i].value;
  }

  /*
   * Function : put
   * If the key does'nt exist in the dictionary, then insert the given key and value in the dictionary.
   * Otherwise change the value associated with the key to the given value.
   */
	virtual void put(const Key& key, const Value& value) {
    int max = std::numeric_limits<int>::min();
    int max_index = -1;

    for (int i = 0; i < usage.size(); i++) {
      if (usage[i] > max) {
        max = usage[i];
        max_index = i;
      }
    }

    for (auto& elem : usage) {
      elem++;
    }
    usage[max_index] = 0;

    map[max_index] = AssociativeCacheData<Key, Value> (key, value);
    map[max_index].filled = true;
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
}

#endif
