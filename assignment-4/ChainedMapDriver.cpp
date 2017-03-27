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
}
