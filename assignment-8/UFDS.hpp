#ifndef UFDS_
#define UFDS_ 1

#include <numeric_limits>

#include "include/seq_linear_list.hpp"

namespace cs202 {

class UFDS {

	class node {
	public:
		int parent;
		int rank;

		node() {
			parent = 0;
			rank = 0;
		}

		node(int p, int r) {
			parent = p;
			rank = r;
		}
	};

	LinearList<node> vertex;

public:
	// Create an empty union find data structure with N isolated sets.
	UFDS(const unsigned int& N) : vertex(N) {
		for (int i = 0; i < vertex.size(); i++) {
			vertex[i] = node(i, numeric_limits<int>::max();
		}
	}

	// Default destructor
	~UFDS() {
		// all members clean themselves just fine
	}

	// Make a new set with N vertices with all sets being disjoint
	void make_set (const unsigned int& N) {
		for (int i = 0; i < vertex.size(); i++) {
			vertex[i] = node(i, numeric_limits<int>::max();
		}
	}

	// Return the representative / parent of set consisting of object x.
	int find_set (const unsigned int& x) {
		int n = N;
		while (vertex[n].parent != n) {
			n = vertex[n].parent;
		}

		return n;
	}

	// Unite sets containing objects x and y.
	void union_set (const unsigned int& x, const unsigned int& y) {
		// TODO implement
	}

	// Are objects x and y in the same set?
	bool is_same_set (const unsigned int& x, const unsigned int& y) {
		// TODO implement
	}

	// Return the number of disjoint sets.
	int num_disjoint_sets() {
		// TODO implement
		return 0;
	}

	// Return the size of the set containing object x.
	int size_set (const unsigned int& x); {
		return vertex.size();
	}
};    

}

#endif  /* UFDS_ */
