#include "MinPriorityQueue.hpp"

#include <iostream>
#include <string>

int main() {
    cs202::MinPriorityQueue<int> q;

    std::string command;
    while (std::cin >> command) {
        if (command == "insert") {
            int key;
            std::cin >> key;

            q.insert(key);
        } else if (command == "extract") {
            std::cout << q.extract_min() << std::endl;
        } else if (command == "min") {
            std::cout << q.minimum() << std::endl;
        } else {
            break;
        }
    }

    return 0;
}