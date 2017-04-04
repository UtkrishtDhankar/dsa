#include "BinaryTree.hpp"

#include <iostream>
#include <string>

int main() {
    cs202::BinaryTree<int, int> bt;


    std::string command;
    while (std::cin >> command) {
        if (command == "put") {
            int key;
            std::cin >> key;

            int val;
            std::cin >> val;

            bt.put(key, val);

        } else if (command == "has") {
            int key;
            std::cin >> key;

            std::cout << bt.has(key) << std::endl;
        }
    }
}
