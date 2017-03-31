/*
 * ListMap.hpp
 */

#ifndef LISTMAP_HPP_
#define LISTMAP_HPP_

#include "Dictionary.hpp"
#include "include/list.hpp"

namespace cs202 {

template<class Key, class Value>
struct ListMapData {
  ListMapData() {key = Key(); value = Value();}
  ListMapData(const ListMapData<Key, Value>& other) {key = other.key; value = other.value;}
  ListMapData(const Key& k, const Value& v) : key(k), value(v) {}

  bool operator==(const ListMapData<Key, Value>& other) const {return (key == other.key && value == other.value);}

  Key key;
  Value value;
};

template<class Key, class Value>
class ListMap : public Dictionary<Key, Value>
{
private:
  list<ListMapData<Key, Value> > map;

public:

  /*
   * Constructor.
   */
  ListMap() {

  }

    /*
     * Destructor. Should release all the memory acquired by the dictionary.
     */
	virtual ~ListMap(){

  }
    /*
     * Function : has
     * Returns true if the dictionay contains the key
     * false otherwise. It is search operation
     */
	virtual bool has(const Key& key) {
    bool found = false;

    for (auto it = map.begin(); it != map.end(); it++) {
      if ((*it).key == key) {
        found = true;
        break;
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
      if ((*it).key == key) {
        found = true;
        break;
      }
    }

    if (found) {
      map.remove(*it);
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
    bool found = false;

    auto it = map.begin();
    for (; it != map.end(); it++) {
      if ((*it).key == key) {
        found = true;
        break;
      }
    }

    if (found) {
      (*it).value = value;
    } else {
      map.cons(ListMapData<Key, Value>(key, value));
    }
  }

	Value& operator[](const Key& key) {
    if (!has(key)) {
      put(key, Value());
    }

    return get(key);
  }
};
}


#endif /* DICTIONARY_HPP_ */
