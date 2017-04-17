
#include "RBTree.hpp"

#include <iostream>
#include <string>

int main() {
    cs202::RBTree<int, int> bt;

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
        } else if (command == "get") {
            int key;
            std::cin >> key;

            std::cout << bt.get(key) << std::endl;
        } else if (command == "remove") {
            int key;
            std::cin >> key;

            bt.remove(key);
        } else if (command == "preorder") {
            bt.print_pre_order();
        } else if (command == "inorder") {
            bt.print_in_order();
        } else if (command == "postorder") {
            bt.print_post_order();
        } else if (command == "print") {
            bt.print();
        } else if (command == "max") {
            std::cout << bt.maximum() << std::endl;
        } else if (command == "min") {
            std::cout << bt.minimum() << std::endl;
        } else if (command == "height") {
            std::cout << bt.getHeight() << std::endl;
        } else if (command == "bheight") {
            std::cout << bt.blackHeight() << std::endl;
        } else if (command == "size") {
            std::cout << bt.size() << std::endl;
        } else if (command == "successor") {
            int key;
            std::cin >> key;

            std::cout << bt.successor(key) << std::endl;
        } else if (command == "predecessor") {
            int key;
            std::cin >> key;

            std::cout << bt.predecessor(key) << std::endl;
        } else {
            break;
        }
    }

    return 0;
}
