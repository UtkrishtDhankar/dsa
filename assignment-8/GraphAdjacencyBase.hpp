#ifndef GRAPH_ADJACENCY_BAG
#define GRAPH_ADJACENCY_BAG 1

#include "include/list.hpp"

namespace cs202 {

class GraphEdge {
public:
	int dest;
	int weight;

	GraphEdge() {
		dest = weight = 0;
	}

	GraphEdge(int d, int w) {
		dest = d; weight = w;
	}

	// Use this for comparing if edges have equal destinations
	// Useful because it helps with easily reusing old code
	bool operator==(const GraphEdge& other) {
		return dest == other.dest;
	}
};

/*
 * A base class which can denote any Graph Adjacency representation.
 * Subclasse by AdjacencyMatrix and AdjacencyList
 * Use this class in your graphs to be able to select any representation as desired by the user.
 */
class GraphAdjacencyBase {
public:
	/* Destructor:
	 * releases all resources acquired by the class
	 */
	virtual ~GraphAdjacencyBase() {

	}

	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
	virtual bool edgeExits(int i, int j) const = 0;
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
	virtual int vertices() const = 0;
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
	virtual int edges() const = 0;
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
	virtual void add(int i, int j, int weight) = 0;
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
	virtual void remove(int i, int j) = 0;
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
	virtual int indegree(int i) const = 0;

	virtual int outdegree(int i) const = 0;

	virtual const list<GraphEdge> adjacentVertices(int i) const = 0;
};

}

#endif /* ifndef GRAPH_ADJACENCY_BAG */
