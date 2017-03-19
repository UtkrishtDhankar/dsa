#include <iostream>
#include <string>
#include <cstdlib>

#include "stack.hpp"

int main()
{
  cs202::stack<int> s;

  std::string command;
  while (std::cin >> command) {
    if (command == "push") {
      int num;
      std::cin >> num;

      s.push(num);
    } else if (command == "pop") {
      std::cout << s.pop() << std::endl;
    } else if (command == "top"){
      std::cout << s.top() << std::endl;
    } else if (command == "size"){
      std::cout << s.size() << std::endl;
    } else if (command == "empty") {
      std::cout << s.empty() << std::endl;
    } else {
      break;
    }
  }

  return 0;
}
