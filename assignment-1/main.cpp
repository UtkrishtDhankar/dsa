#include <iostream>

#include "sorting.hpp"

int main()
{
    LinearList<int> list(10);

    list.insert(0, 4);
    list.insert(1, 3);
    list.insert(2, 1);
    list.insert(3, 2);

    int x;
    list.deleteElement(1, x);

    for (int i = 0; i < list.length(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    Sort<int> sort;
    sort.rankSort(list, 0, list.length());

    for (int i = 0; i < list.length(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
