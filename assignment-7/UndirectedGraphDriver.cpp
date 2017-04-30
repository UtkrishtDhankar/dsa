#include "UndirectedGraph.hpp"

#include <iostream>
#include <string>

int main() {
    int n;
    std::cout << "Enter the size of the list: ";
    std::cin >> n;

    char ch;
    std::cout << "Enter the mode for the graph (l/m):";
    std::cin >> ch;

    cs202::GraphMode mode;
    if (ch == 'l' || ch == 'L') {
        mode = cs202::LIST;
    } else if (ch == 'm' || ch == 'M') {
        mode = cs202::MATRIX;
    } else {
        throw std::invalid_argument("Mode is invalid.");
    }

    cs202::UndirectedGraph l(n, mode);

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
            // TODO implement peak function for this
        } else {
            break;
        }
    }

    return 0;
}