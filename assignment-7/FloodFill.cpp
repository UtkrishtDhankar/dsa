#include <iostream>
#include <string>

#include "UndirectedGraph.hpp"

class Point
{
public:
	Point() {}
	Point(int x_in, int y_in) {x = x_in; y = y_in;}

	bool operator==(const Point& other) {
		return (x == other.x && y == other.y);
	}

	int x;
	int y;
};

inline int index_of(int x, int y, int width) {
	return y * width + x;
}

inline Point point_from_index(int index, int width) {
	return Point(index % width, index / width);
}

bool is_inaccessible(Point p, const cs202::LinearList<Point>& inaccessible_points) {
	return inaccessible_points.find(p) != inaccessible_points.size();
}

bool is_valid_point(Point p, int width, int height) {
	return (p.x >= 0 && p.x < width && p.y >= 0 && p.y < height);
}

cs202::UndirectedGraph build_graph(int width, int  height, const cs202::LinearList<Point>& inaccessible_points) {
	cs202::UndirectedGraph graph(width * height, cs202::LIST);

	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (is_inaccessible(Point(x, y), inaccessible_points)) {
				continue; // in this case we don't want to do anything
			}

			// Add all offsets
			for (int xoffset = -1; xoffset <= 1; xoffset++) {
				for (int yoffset = -1; yoffset <=1; yoffset++) {
					Point p(x + xoffset, y + yoffset);
					if (!(xoffset == 0 && yoffset == 0)  // if both offsets are zero then we'd add a self loop
						&& is_valid_point(p, width, height) // must be a valid point to be added
						&& !is_inaccessible(p, inaccessible_points)) { // must be accessible to be added
						
						graph.add(index_of(x, y, width), index_of(p.x, p.y, width));
					}
				}
			}

		}
	}

	return graph;
}

int main()
{
	int width, height; 
	std::cout << "Enter the width and the height of the matrix: ";
	std::cin >> width >> height;

	Point source, dest;
	std::cout << "Enter the source and destination vertices (x, y): ";
	std::cin >> source.x >> source.y >> dest.x >> dest.y;

	int num_inaccessible;
	std::cout << "Enter the number of inaccessible nodes: ";
	std::cin >> num_inaccessible;
	
	cs202::LinearList<Point> inaccessible_points(num_inaccessible);
	for (int i = 0; i < num_inaccessible; i++) {
		Point p;
		std::cin >> p.x >> p.y;

		inaccessible_points.push_back(p);
	}

	cs202::UndirectedGraph graph = build_graph(width, height, inaccessible_points);

	for (int i = 0; i < graph.vertices(); i++) {
		Point p = point_from_index(i, width);
		std::cout << "(" << p.x << ", " << p.y << ") " << ": ";

		cs202::list<int> adjacents = graph.adjacentVertices(i);
		for (auto adjacent : adjacents) {
			Point p = point_from_index(adjacent, width);
			std::cout << "(" << p.x << ", " << p.y << ") ";
		}

		std::cout << std::endl;
	}
}