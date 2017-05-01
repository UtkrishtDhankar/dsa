#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "include/queue.hpp"
#include "include/stack.hpp"

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
	virtual void dfs(int source, void (*work)(int&)) override {
		if (source >= vertices() || source < 0) {
			throw std::invalid_argument("Source for DFS must be a valid vertex.");
		}

		stack<int> s;
		LinearList<int> pred(vertices(), -1); // Having a predecessor of -1 means that it has no predecessor
		LinearList<int> color(vertices(), WHITE);
		int nodes_visited = 1;

		while (nodes_visited <= vertices()) {
			color[source] = GRAY;
			s.push(source);

			while (!s.empty()) {
				int current = s.pop();
				color[current] = BLACK;
				nodes_visited++;

				// Get all adjacent nodes of current into the q
				list<int> adjacents = g->adjacentVertices(current);
				for (int adjacent : adjacents) {
					if (color[adjacent] == WHITE) {
						s.push(adjacent);
						color[adjacent] = GRAY;
						pred[adjacent] = current;
					}
				}

				work(current);
			}

			for (int i = 0; i < vertices(); i++) {
				if (color[i] == WHITE) {
					source = i;
					break;
				}
			}
		}
	}
	/*
	 * Function bfs:
	 * Does a breadth first traversal of the entire graph.
	 * Runs the given function work, with the value of each vertex.
	 */
	virtual void bfs(int source, void (*work)(int&)) override {
		if (source >= vertices() || source < 0) {
			throw std::invalid_argument("Source for BFS must be a valid vertex.");
		}

		queue<int> q;
		LinearList<int> pred(vertices(), -1); // Having a predecessor of -1 means that it has no predecessor
		LinearList<int> color(vertices(), WHITE);

		color[source] = GRAY;
		q.push(source);

		while (!q.empty()) {
			int current = q.pop();
			color[current] = BLACK;

			// Get all adjacent nodes of current into the q
			list<int> adjacents = g->adjacentVertices(current);
			for (int adjacent : adjacents) {
				if (color[adjacent] == WHITE) {
					q.push(adjacent);
					color[adjacent] = GRAY;
					pred[adjacent] = current;
				}
			}

			work(current);
		}
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