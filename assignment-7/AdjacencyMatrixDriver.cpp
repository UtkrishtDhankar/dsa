#include "AdjacencyMatrix.hpp"

#include <iostream>
#include <string>

int main() {
    int n;
    std::cout << "Enter the size of the list: ";
    std::cin >> n;

    cs202::AdjacencyMatrix l(n);

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
        } else if (command == "outdegree") {
            int v;
            std::cin >> v;

            std::cout << l.outdegree(v) << std::endl;
        } else if (command == "indegree") {
            int v;
            std::cin >> v;

            std::cout << l.indegree(v) << std::endl;
        } else if (command == "exists") {
            int from, to;
            std::cin >> from >> to;

            std::cout << l.edgeExits(from, to) << std::endl;
        } else if (command == "vertices") {
            std::cout << l.vertices() << std::endl;
        } else if (command == "edges") {
            std::cout << l.edges() << std::endl;
        } else if (command == "peak") {
            for (int i = 0; i < l.vertices(); i++) {
                std::cout << i << ": ";
                for (int j = 0; j < l.vertices(); j++) {
                    if (l.edgeExits(i, j)) {
                        std::cout << j << ", ";
                    } 
                }
                std::cout << std::endl;
            }
        } else {
            break;
        }
    }

    return 0;
}