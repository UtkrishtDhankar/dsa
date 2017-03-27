#include <iostream>

#include "ChainedMap.hpp"

template<>
struct cs202::hash<int> {
unsigned long long operator() (int k) const {
  return (unsigned long long) k;
}
};

int main()
{
  cs202::hash<int> hash_func;
  cs202::ChainedMap<int, int> map(hash_func);

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
    } else {
      break;
    }
  }

  return 0;
}
;
