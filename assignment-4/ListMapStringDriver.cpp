#include <iostream>
#include <string>

#include "ListMap.hpp"

int main()
{
  cs202::ListMap<std::string, int> map;

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
