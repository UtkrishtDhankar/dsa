#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "include/queue.hpp"
#include "include/stack.hpp"

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

	virtual list<int> adjacentVertices(int i) const override {
		return g->adjacentVertices(i);
	}

	/*
	 * Function dfs:
	 * Does a depth first traversal of the entire graph.
	 * Runs the given function work, with the value of each vertex.
	 */
	virtual LinearList<int> dfs(int source, void (*work)(int&)) override {
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

			for (int i = source; i < vertices(); i++) {
				if (color[i] == WHITE) {
					source = i;
					break;
				}
			}
		}

		return pred;
	}
	/*
	 * Function bfs:
	 * Does a breadth first traversal of the entire graph.
	 * Runs the given function work, with the value of each vertex.
	 */
	virtual LinearList<int> bfs(int source, void (*work)(int&)) override {
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

		return pred;
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