#include "AdjacencyList.hpp"

#include <iostream>
#include <string>

int main() {
    int n;
    std::cout << "Enter the size of the list: ";
    std::cin >> n;

    cs202::AdjacencyList l(n);

    std::string command;
    while (std::cin >> command) {
        if (command == "add") {
            int from, to;
            std::cin >> from >> to;

            l.add(from, to);
        } else if (command == "remove") {
            int from, to;
            std::cin >> from >> to;

            l.remove(from, to);
        } else if (command == "degree") {
            int v;
            std::cin >> v;

            std::cout << l.degree(v) << std::endl;
        } else if (command == "exists") {
            int from, to;
            std::cin >> from >> to;

            std::cout << l.edgeExits(from, to) << std::endl;
        } else if (command == "vertices") {
            std::cout << l.vertices() << std::endl;
        } else if (command == "edges") {
            std::cout << l.edges() << std::endl;
        } else if (command == "peak") {
            const auto& data = l.peak();
            for (int i = 0; i < data.size(); i++) {
                std::cout << i << ": ";

                for (int j = 0; j < data.at(i).length(); j++) {
                    std::cout << data.at(i).at(j) << ", ";
                }
                std::cout << std::endl;
            }
        } else {
            break;
        }
    }

    return 0;
}