#ifndef UFDS_
#define UFDS_ 1

#include <limits>

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

	void link(int x, int y) {
		if (vertex[x].rank > vertex[y].rank) {
			vertex[y].parent = x;
		} else {
			vertex[x].parent = y;
			if (vertex[x].rank == vertex[y].rank) {
				vertex[y].rank++;
			}
		}
	}

public:
	// Create an empty union find data structure with N isolated sets.
	UFDS(const unsigned int& N) : vertex(N) {
		make_set(N);
	}

	// Default destructor
	~UFDS() {
		// all members clean themselves just fine
	}

	// Make a new set with N vertices with all sets being disjoint
	void make_set (const unsigned int& N) {
		for (int i = 0; i < vertex.size(); i++) {
			vertex[i] = node(i, 0);
		}
	}

	// Return the representative / parent of set consisting of object x.
	int find_set (const unsigned int& x) {
		int n = x;
		while (vertex[n].parent != n) {
			n = vertex[n].parent;
		}

		return n;
	}

	// Unite sets containing objects x and y.
	void union_set (const unsigned int& x, const unsigned int& y) {
		link(find_set(x), find_set(y));
	}

	// Are objects x and y in the same set?
	bool is_same_set (const unsigned int& x, const unsigned int& y) {
		return (find_set(x) == find_set(y));
	}

	// Return the number of disjoint sets.
	int num_disjoint_sets() {
		int num = 0;
		for (int i = 0; i < vertex.size(); i++) {
			if (vertex[i].parent == i) {
				num++;
			}
		}

		return num;
	}

	// Return the size of the set containing object x.
	int size_set (const unsigned int& x) {
		int size = 0;
		for (int i = 0; i < vertex.size(); i++) {
			if (find_set(x) == find_set(i)) {
				size++;
			}
		}

		return size;
	}

	LinearList<int> peak_parents() {
		LinearList<int> parents;
		for (int i = 0; i < vertex.size(); i++) {
			parents.push_back(vertex[i].parent);
		}

		return parents;
	}

	LinearList<int> peak_ranks() {
		LinearList<int> ranks;
		for (int i = 0; i < vertex.size(); i++) {
			ranks.push_back(vertex[i].rank);
		}

		return ranks;
	}
};    

}

#endif  /* UFDS_ */
