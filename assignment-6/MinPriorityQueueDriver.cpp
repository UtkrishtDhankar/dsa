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
        } else if (command == "peak") {
            const cs202::LinearList<int>& heap = q.peak();

            for (int i = 0; i < heap.size(); i++) {
                std::cout << heap.copy_at(i) << " ";
            }
            std::cout << std::endl;
        } else if (command == "decrease") {
            size_t pos;
            int elem;
            std::cin >> pos >> elem;

            q.heap_decrease_key(pos, elem);
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