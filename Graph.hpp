#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

// Graph class inheriting from GraphBase
class Graph : public GraphBase {
private:
    // Adjacency list: vertex -> list of {neighbor, weight} pairs
    std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned long> > > adjList;

public:
    // Add a vertex to the graph
    void addVertex(std::string label);

    // Remove a vertex and its edges
    void removeVertex(std::string label);

    // Add an edge with a specified weight between two vertices
    void addEdge(std::string label1, std::string label2, unsigned long weight);

    // Remove an edge between two vertices
    void removeEdge(std::string label1, std::string label2);

    // Compute the shortest path using Dijkstra's algorithm
    unsigned long shortestPath(std::string startLabel, std::string endLabel, 
                               std::vector<std::string>& path);
};

#endif
