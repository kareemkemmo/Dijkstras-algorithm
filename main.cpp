#include "Graph.hpp"
#include <iostream>
#include <vector>

void testGraph1() {
    std::cout << "=== Testing Graph 1 ===" << std::endl;

    Graph g1;

    // Add vertices to Graph 1
    std::cout << "Adding vertices: 1, 2, 3, 4, 5, 6" << std::endl;
    g1.addVertex("1");
    g1.addVertex("2");
    g1.addVertex("3");
    g1.addVertex("4");
    g1.addVertex("5");
    g1.addVertex("6");

    // Add edges to Graph 1
    std::cout << "Adding edges:" << std::endl;
    g1.addEdge("1", "2", 7);
    g1.addEdge("1", "3", 9);
    g1.addEdge("1", "6", 14);
    g1.addEdge("2", "3", 10);
    g1.addEdge("2", "4", 15);
    g1.addEdge("3", "4", 11);
    g1.addEdge("3", "6", 2);
    g1.addEdge("4", "5", 6);
    g1.addEdge("5", "6", 9);

    // Shortest path before any removals
    std::vector<std::string> path;
    unsigned long distance = g1.shortestPath("1", "5", path);
    std::cout << "Shortest path from 1 to 5:" << std::endl;
    if (distance >= 1e9) {
        std::cout << "No path found." << std::endl;
    } else {
        std::cout << "Distance: " << distance << std::endl;
        std::cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    }

    // Remove edge and test
    std::cout << "Removing edge 3-6" << std::endl;
    g1.removeEdge("3", "6");
    distance = g1.shortestPath("1", "5", path);
    std::cout << "Shortest path from 1 to 5 after removing edge 3-6:" << std::endl;
    if (distance >= 1e9) {
        std::cout << "No path found." << std::endl;
    } else {
        std::cout << "Distance: " << distance << std::endl;
        std::cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    }

    // Remove vertex and test
    std::cout << "Removing vertex 3" << std::endl;
    g1.removeVertex("3");
    distance = g1.shortestPath("1", "5", path);
    std::cout << "Shortest path from 1 to 5 after removing vertex 3:" << std::endl;
    if (distance >= 1e9) {
        std::cout << "No path found." << std::endl;
    } else {
        std::cout << "Distance: " << distance << std::endl;
        std::cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "=== End of Graph 1 Test ===\n" << std::endl;
}

void testGraph2() {
    std::cout << "=== Testing Graph 2 ===" << std::endl;

    Graph g2;

    // Add vertices to Graph 2
    std::cout << "Adding vertices: A, B, C, D, E, F" << std::endl;
    g2.addVertex("A");
    g2.addVertex("B");
    g2.addVertex("C");
    g2.addVertex("D");
    g2.addVertex("E");
    g2.addVertex("F");

    // Add edges to Graph 2
    std::cout << "Adding edges:" << std::endl;
    g2.addEdge("A", "B", 1);
    g2.addEdge("A", "C", 4);
    g2.addEdge("B", "C", 2);
    g2.addEdge("B", "D", 7);
    g2.addEdge("C", "D", 3);
    g2.addEdge("C", "E", 5);
    g2.addEdge("D", "E", 1);
    g2.addEdge("D", "F", 6);
    g2.addEdge("E", "F", 2);

    // Shortest path before any removals
    std::vector<std::string> path;
    unsigned long distance = g2.shortestPath("A", "F", path);
    std::cout << "Shortest path from A to F:" << std::endl;
    if (distance >= 1e9) {
        std::cout << "No path found." << std::endl;
    } else {
        std::cout << "Distance: " << distance << std::endl;
        std::cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    }

    // Remove edge and test
    std::cout << "Removing edge D-E" << std::endl;
    g2.removeEdge("D", "E");
    distance = g2.shortestPath("A", "F", path);
    std::cout << "Shortest path from A to F after removing edge D-E:" << std::endl;
    if (distance >= 1e9) {
        std::cout << "No path found." << std::endl;
    } else {
        std::cout << "Distance: " << distance << std::endl;
        std::cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    }

    // Remove vertex and test
    std::cout << "Removing vertex C" << std::endl;
    g2.removeVertex("C");
    distance = g2.shortestPath("A", "F", path);
    std::cout << "Shortest path from A to F after removing vertex C:" << std::endl;
    if (distance >= 1e9) {
        std::cout << "No path found." << std::endl;
    } else {
        std::cout << "Distance: " << distance << std::endl;
        std::cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "=== End of Graph 2 Test ===\n" << std::endl;
}

int main() {
    testGraph1();
    testGraph2();
    return 0;
}
