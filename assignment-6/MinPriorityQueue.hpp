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

	inline bool has_left_child(const size_t& pos) {
		return left_child(pos) <= heap.size();
	}

	inline bool has_right_child(const size_t& pos) {
		return right_child(pos) <= heap.size();
	}

	inline T& get(const size_t& i) {
		// This is i - 1 as our index starts with 1, not 0
		return heap[i - 1];
	}

	inline bool is_property_violated_at(const size_t& pos) {
		return ((has_left_child(pos) && get(left_child(pos)) < get(pos)) || (has_right_child(pos) && get(right_child(pos)) < get(pos)));

	}

	inline size_t find_pos_of_min_child(const size_t& pos) {
		size_t min = pos;
		if (has_left_child(pos) && get(left_child(pos)) < get(min)) {
			min = left_child(pos);
		}
		if (has_right_child(pos) && get(right_child(pos)) < get(min)) {
			min = right_child(pos);
		}

		return min;
	}

	inline void swap_positions(const size_t& pos1, const size_t& pos2) {
		T temp = get(pos1);
		get(pos1) = get(pos2);
		get(pos2) = temp;

	}

	// heapifies the heap at position pos 
	void heapify(const size_t& pos) {
		size_t cur = pos;

		while (is_property_violated_at(cur)) {
			size_t min_child = find_pos_of_min_child(cur);

			swap_positions(min_child, cur);

			cur = min_child;
		}
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
		while (index > 1 && get(parent(index)) > get(index)) {
			T temp = get(index);
			get(index) = get(parent(index));
			get(parent(index)) = temp;

			index = parent(index);
		}
	}

	// get the minimum element from the heap
	inline T minimum() {
		return get(1);
	}

	// return the minimum element from the heap and remove it
	// as well
	T extract_min() {
		// TODO also remove this minimum element
		T min = minimum();

		swap_positions(1, get_heap_size());
		heap.erase_pos(get_heap_size() - 1);

		heapify(1);

		return min;
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