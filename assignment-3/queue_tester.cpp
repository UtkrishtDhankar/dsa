#include <iostream>
#include <string>
#include <cstdlib>

#include "queue.hpp"

int main()
{
  cs202::queue<int> q;

  std::string command;
  while (std::cin >> command) {
    if (command == "push") {
      int num;
      std::cin >> num;

      q.push(num);
    } else if (command == "pop") {
      std::cout << q.pop();
    } else if (command == "front") {
      std::cout << q.front();
    } else if (command == "size") {
      std::cout << q.size();
    } else if (command == "empty") {
      std::cout << q.empty();
    } else {
      break;
    }
  }

  return 0;
}
