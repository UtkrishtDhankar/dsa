#include <iostream>
#include <string>

#include "UFDS.hpp"

int main()
{
    int n;
    std::cout << "Enter the size of the disjoint set: ";
    std::cin >> n;

    cs202::UFDS u(n);

    std::string command;
    while (std::cin >> command) {
        if (command == "find") {
            int n;
            std::cin >> n;

            std::cout << u.find_set(n) << std::endl;
        } else if (command == "union") {
            int x, y;
            std::cin >> x >> y;

            u.union_set(x, y);
        } else if (command == "num") {
            std::cout << u.num_disjoint_sets() << std::endl;
        } else if (command == "is_same") {
            int x, y;
            std::cin >> x >> y;

            std::cout << u.is_same_set(x, y) << std::endl;
        } else if (command == "size") {
            int n;
            std::cin >> n;

            std::cout << u.size_set(n) << std::endl;
        } else if (command == "parents") {
            cs202::LinearList<int> parents = u.peak_parents();

            for (int elem : parents) {
                std::cout << elem << " ";
            }

            std::cout << std::endl;
        } else if (command == "ranks") {
            cs202::LinearList<int> ranks = u.peak_ranks();

            for (int elem : ranks) {
                std::cout << elem << " ";
            }

            std::cout << std::endl;
        } else {
            break;
        }
    }

    return 0;
}
