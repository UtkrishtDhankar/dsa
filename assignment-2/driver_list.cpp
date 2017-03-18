// Driver Program for testing `seqLinearList` class
// Author:
// Roll Number:
#include <iostream>

#include "seq_linear_list.hpp"

// Please read the guidelines carefully before writing any piece of code
int main()
{
  cs202::LinearList<int> l(10);
  l.push_back(3);
  l.push_back(1);
  l.push_back(4);
  l.push_back(2);
  l.push_back(4);
  l.push_back(9);
  l.push_back(0);
  l.push_back(-1);

  for (auto elem : l) {
    std::cout << elem << std::endl;
  }

  l.insert(10, 4);

  for (auto elem : l) {
    std::cout << elem << std::endl;
  }

	return 0;
}
