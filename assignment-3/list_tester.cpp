#include <iostream>
#include <string>
#include <cstdlib>

#include "list.hpp"

int main()
{
  list<int> l;

  std::string command;
  while (std::cin >> command) {
    if (command == "append") {
      int number;
      std::cin >> number;
      l.append(number);
    } else if (command == "appendlist") {
      list<int> temp;
      int size;
      std::cin >> size;
      for (int i = 0; i < size; i++) {
        int num;
        std::cin >> num;

        temp.append(num);
      }

      l.append(temp);
    } else if (command == "print") {
      for (unsigned int i = 0; i < l.length(); i++) {
        std::cout << l[i] << " ";
      }
      std::cout << std::endl;
    } else if (command == "cons") {
      int number;
      std::cin >> number;

      l.cons(number);
    } else if (command == "remove") {
      int number;
      std::cin >> number;

      l.remove(number);
    } else {
      break;
    }
  }

  return 0;
}
