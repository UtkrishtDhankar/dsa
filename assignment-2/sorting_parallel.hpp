#ifndef _SORTING_HPP
#define _SORTING_HPP 1

#include <thread>

#include "seq_linear_list.hpp"

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

//   template<class Item>
//   void Sort<I;
//     int j = right - 1;
// tem>::insertionSort(LinearList<Item>& A, int low, int high)
//   {
//     for (int i = low + 1; i < high; i++) {
//       Item currentItem = A[i];

//       int j = i;
//       while (j > low && currentItem < A[j - 1]) {
//         A[j] = A[j - 1];
//         j--;
//       }
//       A[j] = currentItem;
//     }
//   }

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
    } while (swapped);
  }

  template<class Item>
  void Sort<Item>::rankSort(LinearList<Item>& A, int low, int high)
  {
    LinearList<Item> ranks(high - low, 0);

    for (int i = low; i < high; i++) {
      for (int j = i; j < high; j++) {
        if (A[j] < A[i]) {
          ranks[i - low]++;
        } else {
          ranks[j - low]++;
        }
      }
    }

    LinearList<Item> copy = A;
    for (int i = low; i < high; i++) {
      A[ranks[i - low] + low - 1] = copy[i];
    }
  }

  template<class Item>
  void Sort<Item>::selectionSort(LinearList<Item>& A, int low, int high)
  {
    for (int i = low; i < high; i++) {
      int minIndex = i;
      for (int j = i + 1; j < high; j++) {
        if (A[j] < A[minIndex]) {
          minIndex = j;
        }
      }

      Item temp = A[minIndex];
      A[minIndex] = A[i];
      A[i] = temp;
    }
  }

  template<class Item>
  void Sort<Item>::mergeSort(LinearList<Item>& A, int low, int high) {
    if (low < high - 1) {
      int middle = (low + high) / 2;

      LinearList<Item> left(middle);
      LinearList<Item> right(high - middle);
      for (int i = 0; i < middle; i++) {
        left.push_back(A[i]);
      }

      for (int i = middle; i < high; i++) {
        right.push_back(A[i]);
      }

      mergeSort(left, 0, left.size());
      mergeSort(right, 0, right.size());

      int i = 0;
      int j = 0;
      int k = 0;
      while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
          A[k] = left[i];
          i++;
        } else {
          A[k] = right[j];
          j++;
        }
        k++;
      }

      while (i < left.size()) {
        A[k] = left[i];
        i++; k++;
      }

      while (j < right.size()) {
        A[k] = right[j];
        j++; k++;
      }
    }
  }

  template<class Item>
  void Sort<Item>::quickSort(LinearList<Item>& A, int low, int high) {
    if (low < high - 1) {
      int wall = low;
      Item pivot = A[high - 1];

      for (int i = low; i < high; i++) {
        if (A[i] <= pivot) {
          Item temp = A[i];
          A[i] = A[wall];
          A[wall] = temp;
          wall++;
        }
      }

      std::thread qsort_thread1(&em>::quickSort, this, A, low, wall - 1);
      std::thread qsort_thread2(&Sort<Item>::quickSort, this, A, wall - 1, high);

      qsort_thread1.join(); qsort_thread2.join();
      // quickSort(A, low, wall - 1);
      // quickSort(A, wall - 1, high);
    }
  }
}

#endif  /* _SORTING_HPP */
