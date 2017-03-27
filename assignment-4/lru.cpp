#include <iostream>

#include "AssociativeCache.hpp"
#include "include/seq_linear_list.hpp"

namespace cs202 {
template<>
struct hash<int> {
  unsigned long long operator() (int k) const {
    return (unsigned long long) k;
  }
};
}

int main()
{
  int m, n;
  std::cin >> m >> n;

  cs202::AssociativeCache<int, unsigned long long> cache(m);
  cs202::LinearList<unsigned long long> memory(n, 0);

  std::string command;
  while (std::cin >> command) {
    if (command == "read") {
      int index;
      std::cin >> index;

      if (!cache.has(index))
        cache.put(index, memory[index]);

      auto data = cache.get(index);
      std::cout << data << std::endl;
    } else if (command == "write") {
      int index;
      std::cin >> index;

      unsigned long long inp;
      std::cin >> inp;
      memory[index] = inp;

      cache.put(index, inp);
    } else if (command == "data") {
      auto data = cache.get_data();

      for (auto elem : data) {
        std::cout << "(" << elem.key << ": " << elem.value << ")";
      }
      std::cout << std::endl;
    } else if (command == "usage") {
      auto usage = cache.get_usage();

      for (auto elem : usage) {
        std::cout << elem << " ";
      }
      std::cout << std::endl;
    } else {
      break;
    }
  }
}

