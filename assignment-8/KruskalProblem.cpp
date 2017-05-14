#include <iostream>

#include "UndirectedGraph.hpp"

int main() {
    int numberOfTestCases;

    std::cin >> numberOfTestCases;

    for (int j = 0; j < numberOfTestCases; j++) {
        int numberOfVertices;
        int numberOfEdges;
        
        std::cin >> numberOfVertices >> numberOfEdges;
        cs202::UndirectedGraph graph(numberOfVertices, cs202::GraphMode::LIST);

        for (int i = 0; i < numberOfEdges; i++) {
            int source, dest, cost;
            std::cin >> source >> dest >> cost;

            graph.add(source, dest, cost);
        }

        cs202::UndirectedGraph mst = graph.kruskal();

        int numberOfQuestions;
        std::cin >> numberOfQuestions;

        int numberOfPositives = 0;

        for (int i = 0; i < numberOfQuestions; i++) {
            int source, dest;
            std::cin >> source >> dest;

            if (mst.edgeExits(source, dest)) {
                numberOfPositives++;
            }
        }

        std::cout << numberOfPositives << std::endl;
    }

    return 0;
}