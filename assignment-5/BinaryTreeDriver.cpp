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
        } else if (command == "preorder") {
            bt.print_pre_order();
        } else if (command == "inorder") {
            bt.print_in_order();
        } else if (command == "postorder") {
            bt.print_post_order();
        }
    }
}
