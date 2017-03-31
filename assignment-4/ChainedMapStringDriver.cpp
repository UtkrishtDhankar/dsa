#include <iostream>
#include <string>

#include "ChainedMap.hpp"

template<>
struct cs202::hash<std::string> {
  // djb2 by Dan Bernstein
  unsigned long long operator() (std::string str) const {
    unsigned long long hash = 5381;

    for (auto elem : str) {
      hash = ((hash << 5) + hash) + elem;
    }

    return hash;
  }
};

int main()
{
  cs202::hash<std::string> hash_func;
  cs202::ChainedMap<std::string, int> map(hash_func);

  std::string command;
  while (std::cin >> command) {
    if (command == "put") {
      std::string key;
      std::cin >> key;

      int val;
      std::cin >> val;

      map.put(key, val);
    } else if (command == "get") {
      std::string key;
      std::cin >> key;

      std::cout << map.get(key) << std::endl;
    } else if (command == "braces") {
      std::string key;
      std::cin >> key;

      int val;
      std::cin >> val;

      map[key] = val;
    } else if (command == "has") {
      std::string key;
      std::cin >> key;

      std::cout << map.has(key) << std::endl;
    } else if (command == "remove") {
      std::string key;
      std::cin >> key;

      map.remove(key);
    } else {
      break;
    }
  }

  return 0;
}
