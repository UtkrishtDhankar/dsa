#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include <iostream>

#include "include/queue.hpp"
#include "include/stack.hpp"
#include "include/MinPriorityQueue.hpp"
#include "include/sorting.hpp"

#include "AbstractGraph.hpp"
#include "GraphAdjacencyBase.hpp"
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "UFDS.hpp"

namespace cs202 {

class MSTEdge {
public:
	int source;
	int dest;
	int weight;

	MSTEdge() {
		source = dest = weight = 0;
	}

	MSTEdge(int s, int d, int w) {
		source = s;
		dest = d;
		weight = w;
	}

	bool operator<(const MSTEdge& other) {
		return weight < other.weight;
	}

	bool operator>(const MSTEdge& other) {
		return weight > other.weight;
	}

	bool operator==(const MSTEdge& other) {
		return weight == other.weight;
	}

	bool operator<=(const MSTEdge& other) {
		return (*this < other || *this == other);
	}

	bool operator>=(const MSTEdge& other) {
		return (*this > other || *this == other);
	}
};

class PrimVertex {
public:
	int vertex;
	int key;

	PrimVertex() {
		vertex = key = 0;
	}

	PrimVertex(int v, int k) {
		vertex = v;
		key = k;
	}

	PrimVertex(const PrimVertex& other) {
		vertex = other.vertex;
		key = other.key;
	}

	void operator=(const PrimVertex& other) {
		vertex = other.vertex;
		key = other.key;
	}

	bool operator<(const PrimVertex& other) {
		return key < other.key;
	}

	bool operator>(const PrimVertex& other) {
		return key > other.key;
	}

	bool operator==(const PrimVertex& other) {
		return (vertex == other.vertex);
	}
};

class UndirectedGraph : AbstractGraph {
private:
	GraphAdjacencyBase* g;
	GraphMode m;

	LinearList<MSTEdge> getEdges() {
		LinearList<MSTEdge> edges;
		for (int i = 0; i < vertices(); i++) {
			list<GraphEdge> adjacents = adjacentVertices(i);	
			for (auto adjacent : adjacents) {
				if (i < adjacent.dest) {
					edges.push_back(MSTEdge(i, adjacent.dest, adjacent.weight));
				}
			}
		}

		Sort<MSTEdge> s;
		s.quickSort(edges, 0, edges.size());

		return edges;
	}

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
	virtual void add(int i, int j, int weight) override {
		g->add(i, j, weight);
		g->add(j, i, weight);
	}
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
	virtual void remove(int i, int j) override {
		g->remove(i, j);
		g->remove(j, i);
	}

	virtual list<GraphEdge> adjacentVertices(int i) const override {
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
				list<GraphEdge> adjacents = g->adjacentVertices(current);
				for (GraphEdge adjacent : adjacents) {
					if (color[adjacent.dest] == WHITE) {
						s.push(adjacent.dest);
						color[adjacent.dest] = GRAY;
						pred[adjacent.dest] = current;
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
			list<GraphEdge> adjacents = g->adjacentVertices(current);
			for (GraphEdge adjacent : adjacents) {
				if (color[adjacent.dest] == WHITE) {
					q.push(adjacent.dest);
					color[adjacent.dest] = GRAY;
					pred[adjacent.dest] = current;
				}
			}

			work(current);
		}

		return pred;
	}

	UndirectedGraph kruskal() {

		UndirectedGraph mst(vertices(), GraphMode::LIST);
		UFDS disjointSet(vertices());

		LinearList<MSTEdge> edges = getEdges();
		for (int i = 0; i < edges.size(); i++) {
			if (disjointSet.find_set(edges[i].source) != disjointSet.find_set(edges[i].dest)) {
				mst.add(edges[i].source, edges[i].dest, edges[i].weight);
				disjointSet.union_set(edges[i].source, edges[i].dest);
			}
		}

		return mst;
	}

	void print_heap(MinPriorityQueue<PrimVertex>& heap) {
		const LinearList<PrimVertex> heap_arr = heap.peak();
		for(int i = 0; i < vertices(); i++){
			std::cout << heap_arr.copy_at(i).vertex << ": " << heap_arr.copy_at(i).key << ", ";
		}
		std::cout << std::endl;
	}

	void print_arr(const LinearList<int>& arr) {
		for (int i = 0; i < arr.size(); i++) {
			std::cout << arr.copy_at(i) << ", ";
		}
		std::cout << std::endl;
	}

	UndirectedGraph prim() {
		LinearList<int> pred(vertices(), -2);
		LinearList<int> s(vertices(), 0);
		LinearList<int> key(vertices(), std::numeric_limits<int>::max());

		MinPriorityQueue<PrimVertex> heap;
		for (int i = 0; i < vertices(); i++) {
			heap.insert(PrimVertex(i, std::numeric_limits<int>::max()));
		}

		int pos = heap.position_of(PrimVertex(0, 0));
		heap.heap_decrease_key(pos, PrimVertex(0, 0));

		key[0] = 0;
		pred[0] = -1;
		
		while (!heap.empty()) {
			PrimVertex min = heap.extract_min();
			s[min.vertex] = 1;
			std::cout << "Examining " << min.vertex << "\n";

			list<GraphEdge> adjacents = adjacentVertices(min.vertex);
			for (GraphEdge adjacent : adjacents) {
				if (s[adjacent.dest] == 0) {
					if (key[adjacent.dest] > adjacent.weight) {
                        pos = heap.position_of(PrimVertex(adjacent.dest, key[adjacent.dest]));
						heap.heap_decrease_key(pos, PrimVertex(adjacent.dest, adjacent.weight));
						key[adjacent.dest] = adjacent.weight;
						pred[adjacent.dest] = min.vertex;

						std::cout << "Pred "; print_arr(pred);
						std::cout << "Keys "; print_arr(key);
						std::cout << "Heap "; print_heap(heap);
					}
				}
			}

		}

		for (int i = 0; i < vertices(); i++) {
			std::cout << pred[i] << " ";
		}
		std::cout << std::endl;

		UndirectedGraph mst(vertices(), GraphMode::LIST);
		for (int i = 1; i < vertices(); i++) {
			mst.add(i, pred[i], key[i]);	
		}

		return mst;
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
