#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include <stdexcept>

#include "GraphAdjacencyBase.hpp"
#include "include/list.hpp"
#include "include/seq_linear_list.hpp"

namespace cs202 {

class AdjacencyMatrix : public GraphAdjacencyBase {
private:
	LinearList<int> matrix;
	int v;

	bool is_valid_index(int i, int j) const {
		return (i < v && j < v);
	}

	int index_of(int i, int j) const {
		return v * i + j;
	}

	int& get(int i, int j) {
		if (is_valid_index(i, j)) {
			return matrix[index_of(i, j)];
		} else {
			throw std::invalid_argument("Invalid indices to matrix.");
		}
	}

	const int& const_get(int i, int j) const {
		if (is_valid_index(i, j)) {
			return matrix.at(index_of(i, j));
		} else {
			throw std::invalid_argument("Invalid indices to matrix.");
		}
	}


public:
	AdjacencyMatrix(int in_v) : matrix(in_v * in_v, 0), v(in_v) {

	}

	/* Destructor:
	 * releases all resources acquired by the class
	 */
	virtual ~AdjacencyMatrix() override {
		// no need to do anything, the matrix will delete itself
	}
	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
	virtual bool edgeExits(int i, int j) const override {
		return (const_get(i, j) != 0);
	}
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
	virtual int vertices() const override {
		return v;		
	}
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
	virtual int edges() const override {
		int edges = 0;
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {
				if (edgeExits(i, j)) {
					edges++;
				}
			}
		}

		return edges;
	}
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
	virtual void add(int i, int j, int weight) override {
		get(i, j) = weight;		
	}
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
	virtual void remove(int i, int j) override {
		get(i, j) = 0;
	}
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
	virtual int outdegree(int i) const override {
		int d = 0;

		for (int j = 0; j < v; j++) {
			if (edgeExits(i, j)) {
				d++;
			}
		}	

		return d;
	}
	
	virtual int indegree(int i) const override {
		int edges = 0;
		for (int j = 0; j < vertices(); j++) {
			if (edgeExits(j, i)) {
				edges++;
			}
		}

		return edges;
	}

	virtual const list<GraphEdge> adjacentVertices(int i) const override {
		if (!is_valid_index(i, 0)) {
			throw std::invalid_argument("Invalid index for adjacency list.");
		}

		list<GraphEdge> adjacents;
		for (int j = 0; j < vertices(); j++) {
			if (edgeExits(i, j)) {
				adjacents.append(GraphEdge(j, const_get(i, j)));
			}
		}

		return adjacents;
	}


	const LinearList<int>& peak() const {
		return matrix;
	}
};

}
#endif /* ifndef ADJACENCY_MATRIX */
