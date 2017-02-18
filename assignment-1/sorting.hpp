#ifndef SORTING_HPP
#define SORTING_HPP

#include <iostream>

#include "seqLinearList.hpp"

template<class Item>
class Sort{
public:

    // In all these sorting functions, the low value is inclusive, the high is not
    // So if high was 7, all indicies up to 7 but not including 7 would be sorted
    void insertionSort(LinearList<Item>& A, int low, int high);
    void bubbleSort(LinearList<Item>& A, int low, int high);
    void rankSort(LinearList<Item>& A, int low, int high);
    void selectionSort(LinearList<Item>& A, int low, int high);
};


template<class Item>
void Sort<Item>::insertionSort(LinearList<Item>& A, int low, int high)
{
    for (int i = low + 1; i < high; i++) {
        Item currentItem = A[i];

        int j = i;
        while (j > low && currentItem < A[j - 1]) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = currentItem;
    }
}

template<class Item>
void Sort<Item>::bubbleSort(LinearList<Item>& A, int low, int high)
{
    bool swapped = false;
    do {
        swapped = false;

        for (int i = low; i < high - 1; i++) {
            if (A[i + 1] < A[i]) {
                Item temp = A[i + 1];
                A[i + 1] = A[i];
                A[i] = temp;

                swapped = true;
            }
        }

        for (int i = 0; i < A.length(); i++) {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    } while (swapped);
}

template<class Item>
void Sort<Item>::rankSort(LinearList<Item>& A, int low, int high)
{
    
}

template<class Item>
void Sort<Item>::selectionSort(LinearList<Item>& A, int low, int high)
{
    
}

#endif
