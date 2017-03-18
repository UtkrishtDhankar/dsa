// Driver Program for testing `sorting` class
// Author:
// Roll Number:

#include <iostream>
#include <thread>

#include "seq_linear_list.hpp"
#include "sorting.hpp"
#include "timer.hpp"

template<typename Item>
void quickSort(cs202::LinearList<Item>* A, int low, int high) {
  static unsigned int number_of_threads_running = 0;

  if (low < high - 1) {
    int wall = low;
    Item pivot = (*A)[high - 1];

    for (int i = low; i < high; i++) {
      if ((*A)[i] <= pivot) {
        Item temp = (*A)[i];
        (*A)[i] = (*A)[wall];
        (*A)[wall] = temp;
        wall++;
      }
    }

    if (number_of_threads_running < 2) {
      number_of_threads_running += 2;
      std::thread qsort_thread1(quickSort<Item>, A, low, wall - 1);
      std::thread qsort_thread2(quickSort<Item>, A, wall - 1, high);

      qsort_thread1.join(); qsort_thread2.join();
    } else {
      quickSort<Item>(A, low, wall - 1);
      quickSort<Item>(A, wall - 1, high);
    }
  }
}

// Please read the guidelines carefully before writing any piece of code
int main()
{
  int input_size;
  std::cin >> input_size;
  cs202::LinearList<int> l(input_size);
  for (int i = 0; i < input_size; i++) {
		int n;
		std::cin >> n;
		l.push_back(n);
  }

  timer t;
  t.start();
  quickSort<int>(&l, 0, l.size());
  t.stop();

  std::cout << t.last_timing() << std::endl;

  return 0;
}
