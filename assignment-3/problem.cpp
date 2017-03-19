#include <iostream>

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

  return 0;
}
