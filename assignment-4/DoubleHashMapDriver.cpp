#include <iostream>

#include "DoubleHashMap.hpp"

namespace cs202 {

template<>
struct hash<int> {
  int m;

  hash(int m_in) {m = m_in;}

  unsigned long long operator() (int k) const {
    return (unsigned long long) k % m;
  }
};

}

int main()
{
  cs202::hash<int> hash_func(101);
  cs202::hash<int> offset_func(5);
  cs202::DoubleHashMap<int, int> map(hash_func, offset_func);

  std::string command;
  while (std::cin >> command) {
    if (command == "put") {
      int key;
      std::cin >> key;

      int val;
      std::cin >> val;

      map.put(key, val);
    } else if (command == "get") {
      int key;
      std::cin >> key;

      std::cout << map.get(key) << std::endl;
    } else if (command == "braces") {
      int key;
      std::cin >> key;

      int val;
      std::cin >> val;

      map[key] = val;
    } else if (command == "has") {
      int key;
      std::cin >> key;

      std::cout << map.has(key) << std::endl;
    } else if (command == "remove") {
      int key;
      std::cin >> key;

      map.remove(key);
    } else {
      break;
    }
  }

  return 0;
}
