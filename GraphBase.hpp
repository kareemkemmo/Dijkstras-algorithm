#ifndef GRAPHBASE_H
#define GRAPHBASE_H

#include <vector>
#include <string>

// Abstract base class for the Graph
class GraphBase {
public:
    // Add a vertex to the graph
    virtual void addVertex(std::string label) = 0;

    // Remove a vertex and its associated edges
    virtual void removeVertex(std::string label) = 0;

    // Add an edge between two vertices with a given weight
    virtual void addEdge(std::string label1, std::string label2, unsigned long weight) = 0;

    // Remove an edge between two vertices
    virtual void removeEdge(std::string label1, std::string label2) = 0;

    // Compute the shortest path from startLabel to endLabel using Dijkstra's algorithm
    // Stores the path in the vector and returns the total weight of the path
    virtual unsigned long shortestPath(std::string startLabel, std::string endLabel, 
                                       std::vector<std::string>& path) = 0;
};

#endif
