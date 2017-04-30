#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "AbstractGraph.hpp"
#include "GraphAdjacencyBase.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"


namespace cs202 {

class UndirectedGraph : AbstractGraph {
private:
	GraphAdjacencyBase* g;
	GraphMode m;

public:
	/*
	 * Constructor: UndirectedGraph
	 *
	 * Parameters: mode
	 * Used to decide which representation to use
	 * 'm' for AdjacencyMatrix
	 * 'l' for AdjacencyList
	 */
	UndirectedGraph(int vertices, GraphMode mode) {
		m = mode;

		if (mode == LIST) {
			g = new AdjacencyList(vertices);
		} else if (mode == MATRIX) {
			g = new AdjacencyMatrix(vertices);
		} else {
			throw std::invalid_argument("Invalid mode for DirectedGraph");
		}
	}
	/* Destructor:
	 * releases all resources acquired by the class
	 */
	virtual ~UndirectedGraph() {

	}
	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
	virtual bool edgeExits(int i, int j) const override {
		return (g->edgeExits(i, j) || g->edgeExits(j, i));
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
		g->add(j, i);
	}
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
	virtual void remove(int i, int j) override {
		g->remove(i, j);
		g->remove(j, i);
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
	 * Returns the degree of the vertex.
	 */
	int degree(int i) {
		return g->outdegree(i);
	}
};

}
#endif /* ifndef UNDIRECTED_GRAPH */