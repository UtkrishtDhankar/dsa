#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "AbstractGraph.hpp"
#include "GraphAdjacencyBase.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"

namespace cs202 {

 /* 
  * A class to represent a directed graph.
  */
class DirectedGraph : AbstractGraph {
private:
	GraphAdjacencyBase* g;
	GraphMode m;

public:
	/*
	 * Constructor: DirectedGraph
	 *
	 * Parameters: mode
	 * Used to decide which representation to use
	 * 'm' for AdjacencyMatrix
	 * 'l' for AdjacencyList
	 */
	DirectedGraph(int numVertices, GraphMode mode) {
		m = mode;

		if (mode == LIST) {
			g = new AdjacencyList(numVertices);
		} else if (mode == MATRIX) {
			g = new AdjacencyMatrix(numVertices);
		} else {
			throw std::invalid_argument("Invalid mode for DirectedGraph");
		}
	}

	/* Destructor:
	 * releases all resources acquired by the class
	 */
	virtual ~DirectedGraph() {

	}
	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
	virtual bool edgeExits(int i, int j) const override {
		return g->edgeExits(i, j);
	}
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
	virtual int edges() const override {
		return g->edges();
	}
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
	virtual int vertices() const override {
		return g->vertices();	
	}
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
	virtual void add(int i, int j) override {
		g->add(i, j);
	}
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
	virtual void remove(int i, int j) override {
		g->remove(i, j);
	}
	/*
	 * Function dfs:
	 * Does a depth first traversal of the entire graph.
	 * Runs the given function work, with the value of each vertex.
	 */
	virtual void dfs(void (*work)(int&)) override {

	}
	/*
	 * Function bfs:
	 * Does a breadth first traversal of the entire graph.
	 * Runs the given function work, with the value of each vertex.
	 */
	virtual void bfs(void (*work)(int&)) override {
		
	}
	/*
	 * Function: indegree
	 * Returns the indegree of a vertex
	 */
	int indegree(int i) {
		// TODO implement this
		return g->indegree(i);	
	}
	/*
	 * Function: outdegree
	 * Returns the outdegree of a vertex.
	 */
	int outdegree(int j) {
		return g->outdegree(j);
	}
};

}
#endif /* ifndef DIRECTED_GRAPH */