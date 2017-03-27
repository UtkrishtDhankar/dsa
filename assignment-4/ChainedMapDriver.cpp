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

  map.put(1, 10);
  map.put(20, 100);

  map.get(1) = 2;
  std::cout << map[1] << " " << map[20]<< std::endl;

  return 0;
}
;
