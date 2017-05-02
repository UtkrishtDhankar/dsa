#include <iostream>
#include <string>

#include "DoubleHashMap.hpp"

namespace cs202 {

template<>
struct hash<std::string> {
private:
  unsigned long long m;
public:
  hash(unsigned long long m_in) : m(m_in) {};

  // djb2 by Dan Bernstein
  unsigned long long operator() (std::string str) const {
    unsigned long long hash = m;

    for (auto elem : str) {
      hash = ((hash << 5) + hash) + elem;
    }

    return hash;
  }
};

}

int main()
{
  cs202::hash<std::string> hash_func(5381);
  cs202::hash<std::string> key_func(11);
  cs202::DoubleHashMap<std::string, int> map(hash_func, key_func);

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
