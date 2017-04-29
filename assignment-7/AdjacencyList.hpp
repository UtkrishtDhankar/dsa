#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "GraphAdjacencyBase.hpp"
#include "include/list.hpp"
#include "include/seq_linear_list.hpp"

namespace cs202 {

class AdjacencyList : public GraphAdjacencyBase {
private:
	LinearList<list<int> > l;	

public:
	AdjacencyList(int v) : l(v) {
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
		return l.at(i).has(j);
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
		l[i].append(j);
	}
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j, from i to j
	 */
	virtual void remove(int i, int j) override {
		l[i].remove(j);
	}
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
	virtual int degree(int i) const override {
		return l.at(i).length();
	}

	const LinearList<list<int> >& peak() const {
		return l;
	}
};

}

#endif /* ifndef ADJACENCY_LIST */