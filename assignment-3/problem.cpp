#include <iostream>
#include <string>

#include "queue.hpp"

int main(int argc, char* argv[])
{
  std::string usage_str = "usage: problem NUMBER RULE\n\n"
    "NUMBER\t the number of children in the game.\n"
    "RULE\t the elimination rule\n";

  if (argc != 3) {
    std::cout << usage_str;
    return 1;
  }

  int num = std::stoi(argv[1]);
  int rule = std::stoi(argv[2]);

  cs202::queue<int> q;

  for (int i = 0; i < num; i++) {
    q.push(num - i);
  }

  for (int i = 1; i < num; i++) {
    for (int j = 1; j < rule; j++) {
      q.push(q.pop());
    }

    q.pop();
  }

  std::cout << q.pop() << std::endl;

  return 0;
}
