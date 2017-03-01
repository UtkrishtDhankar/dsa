#ifndef _SORTING_HPP
#define _SORTING_HPP 1

#include <iostream>
#include "seqLinearList.hpp"

namespace cs202 {
  template<class T>
  class Sort{
    public:
      void insertionSort(LinearList<T>& A, int low, int high);
      void bubbleSort(LinearList<T>& A, int low, int high);
      void rankSort(LinearList<T>& A, int low, int high);
      void selectionSort(LinearList<T>& A, int low, int high);
      void mergeSort(LinearList<T>& A, int low, int high);
      void quickSort(LinearList<T>& A, int low, int high);
  };
}

#endif  /* _SORTING_HPP */
