// Purpose: 
// Author: 
// Date of Creation: 
// Bugs:

#ifndef MIN_PRIORITY_QUEUE
#define MIN_PRIORITY_QUEUE 1
#include "include/seq_linear_list.hpp"

namespace cs202{
 	
template<typename T>
class MinPriorityQueue{
	// Primary container used in MinPriorityQueue
	LinearList<T> heap;

	// return the parent of an element
	inline size_t parent(const size_t& pos) {
		return pos / 2;
	}

	// return the left child of an element
	inline size_t left_child(const size_t& pos) {
		return 2 * pos;
	}

	// return the right child of an element
	inline size_t right_child(const size_t& pos) {
		return 2 * pos + 1;
	}

	inline T& get_ith_elem(const size_t& i) {
		// This is i - 1 as our index starts with 1, not 0
		return heap[i - 1];
	}

	// heapifies the heap at position pos 
	void heapify(const size_t& pos) {
		// TODO implement
	}

	// build a heap from elements of a LinearList container 
	void build_heap(const LinearList<T>& v) {
		// TODO implement
	}

public:
	// default constructor
	MinPriorityQueue() : 
		heap(4) {
		// Nothing to do here
	}

	// construct a heap from the elements of a LinearList
	MinPriorityQueue(const LinearList<T>& v) {
		build_heap(v);
	}

	// insert a value to the heap
	void insert(const T& a) {
		heap.push_back(a);

		size_t index = heap.size();
		while (index > 1 && get_ith_elem(parent(index)) > get_ith_elem(index)) {
			T temp = get_ith_elem(index);
			get_ith_elem(index) = get_ith_elem(parent(index));
			get_ith_elem(parent(index)) = temp;

			index = parent(index);
		}
	}

	// get the minimum element from the heap
	inline T minimum() {
		return get_ith_elem(1);
	}

	// return the minimum element from the heap and remove it
	// as well
	T extract_min() {
		// TODO also remove this minimum element
		return minimum();
	}

	// return the heap size
	inline size_t get_heap_size() {
		return heap.size();
	}


	// check if MinPriorityQueue is empty
	inline bool empty() {
		return heap.empty();
	}

	// heap_decrease_key function
	void heap_decrease_key(const size_t& pos) {
		// TODO find out what this is and implement it
	}
};

}

#endif 