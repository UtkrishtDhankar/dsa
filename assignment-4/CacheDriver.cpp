#include <iostream>

#include "AssociativeCache.hpp"

int main()
{
  cs202::AssociativeCache<int, int> map(2);

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
