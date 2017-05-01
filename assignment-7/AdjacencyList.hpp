#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "GraphAdjacencyBase.hpp"
#include "include/list.hpp"
#include "include/seq_linear_list.hpp"

namespace cs202 {

class AdjacencyList : public GraphAdjacencyBase {
private:
	LinearList<list<int> > l;	

	bool is_valid_index(int i, int j) const {
		return (i < vertices() && j < vertices());
	}

public:
	AdjacencyList(int v) : l(v, list<int> ()) {
	}

	/* Destructor:
	 * releases all resources acquired by the class
	 */
	virtual ~AdjacencyList() override {
		// The destructor of list and seq_linear_list will take care of it all
		// TODO make sure those exist and work
	}
	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
	virtual bool edgeExits(int i, int j) const override {
		if (is_valid_index(i, j)) {
			return l.at(i).has(j);
		} else {
			return false;
		}
	}
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
	virtual int vertices() const override {
		return l.size();		
	}
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
	virtual int edges() const override {
		int edges = 0;
		for (int i = 0; i < l.size(); i++) {
			edges += l.at(i).length();
		}

		return edges;
	}
	/*
	 * Function add:
	 * Adds an edge between vertices i and j, from i to j
	 */
	virtual void add(int i, int j) override {
		if (!is_valid_index(i, j)) {
			throw std::invalid_argument("Invalid index for adjacency list.");
		}

		if (!l[i].has(j))
			l[i].append(j);
	}
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j, from i to j
	 */
	virtual void remove(int i, int j) override {
		if (!is_valid_index(i, j)) {
			throw std::invalid_argument("Invalid index for adjacency list.");
		}

		l[i].remove(j);
	}

	virtual int outdegree(int i) const override {
		if (!is_valid_index(i, 0)) {
			throw std::invalid_argument("Invalid index for adjacency list.");
		}

		return l.at(i).length();
	}

	virtual int indegree(int i) const override {
		if (!is_valid_index(i, 0)) {
			throw std::invalid_argument("Invalid index for adjacency list.");
		}

		int edges = 0;
		for (int j = 0; j < vertices(); j++) {
			if (edgeExits(j, i)) {
				edges++;
			}
		}

		return edges;
	}

	virtual const list<int> adjacentVertices(int i) const override {
		if (!is_valid_index(i, 0)) {
			throw std::invalid_argument("Invalid index for adjacency list.");
		}

		return l.at(i);
	}

	const LinearList<list<int> >& peak() const {
		return l;
	}
};

}

#endif /* ifndef ADJACENCY_LIST */