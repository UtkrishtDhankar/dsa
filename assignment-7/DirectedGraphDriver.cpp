#include "DirectedGraph.hpp"

#include <iostream>
#include <fstream>
#include <string>

void print_node(int& node) {
    std::cout << node << " ";
}

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

    cs202::DirectedGraph l(n, mode);

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
        } else if (command == "indegree") {
            int v;
            std::cin >> v;

            std::cout << l.indegree(v) << std::endl;
        } else if (command == "read") {
            l = cs202::DirectedGraph(n, mode);

            std::string filename;
            std::cin >> filename;

            std::ifstream f;
            f.open(filename);
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    int num;
                    f >> num;

                    if (num) {
                        l.add(x, y);
                    }
                }
            }
        } else if (command == "outdegree") {
            int v;
            std::cin >> v;

            std::cout << l.outdegree(v) << std::endl;
        } else if (command == "exists") {
            int from, to;
            std::cin >> from >> to;

            std::cout << l.edgeExits(from, to) << std::endl;
        } else if (command == "vertices") {
            std::cout << l.vertices() << std::endl;
        } else if (command == "edges") {
            std::cout << l.edges() << std::endl;
        } else if (command == "bfs") {
            int source;
            std::cin >> source;            

            l.bfs(source, &print_node);
            std::cout << std::endl;
        } else if (command == "dfs") {
            int source;
            std::cin >> source;            

            l.dfs(source, &print_node);
            std::cout << std::endl;
        } else if (command == "display") {
            for (int i = 0; i < l.vertices(); i++) {
                std::cout << i << ": ";
                cs202::list<int> adjacents = l.adjacentVertices(i);

                for (auto adjacent : adjacents) {
                    std::cout << adjacent << " ";
                }

                std::cout << std::endl;
            }
        } else {
            break;
        }
    }

    return 0;
}