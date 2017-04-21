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
        } else if (command == "build") {
            int size;
            std::cin >> size;

            cs202::LinearList<int> l(size);
            for (int i = 0; i < size; i++) {
                int x;
                std::cin >> x;

                l.push_back(x);
            }

            q = cs202::MinPriorityQueue<int>(l);
        } else {
            break;
        }
    }

    return 0;
}