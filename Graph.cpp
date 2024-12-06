#include "Graph.hpp"

// Add a vertex to the graph
void Graph::addVertex(std::string label) {
    // Check if the vertex already exists in the adjacency list
    if (adjList.find(label) == adjList.end()) {
        // Create an empty adjacency list entry for the new vertex
        adjList[label] = std::vector<std::pair<std::string, unsigned long> >();
    }
}

// Remove a vertex and all associated edges
void Graph::removeVertex(std::string label) {
    // Erase the vertex from the adjacency list
    adjList.erase(label);

    // Iterate through all vertices in the adjacency list
    for (std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned long> > >::iterator it = adjList.begin();
         it != adjList.end(); ++it) {
        // Get the adjacency list of the current vertex
        std::vector<std::pair<std::string, unsigned long> >& neighbors = it->second;

        // Loop through the adjacency list to remove edges pointing to the removed vertex
        for (size_t i = 0; i < neighbors.size(); ++i) {
            if (neighbors[i].first == label) {
                // Remove the edge and break the loop
                neighbors.erase(neighbors.begin() + i);
                break;
            }
        }
    }
}

// Add an edge between two vertices with a specified weight
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
    // Check if both vertices exist and that the edge is not self-loop
    if (adjList.find(label1) != adjList.end() && adjList.find(label2) != adjList.end() && label1 != label2) {
        // Add the edge from label1 to label2
        adjList[label1].push_back(std::make_pair(label2, weight));
        // Add the edge from label2 to label1 (undirected graph)
        adjList[label2].push_back(std::make_pair(label1, weight));
    }
}

// Remove an edge between two vertices
void Graph::removeEdge(std::string label1, std::string label2) {
    // Check if both vertices exist
    if (adjList.find(label1) != adjList.end() && adjList.find(label2) != adjList.end()) {
        // Remove the edge from label1 to label2
        std::vector<std::pair<std::string, unsigned long> >& neighbors1 = adjList[label1];
        for (size_t i = 0; i < neighbors1.size(); ++i) {
            if (neighbors1[i].first == label2) {
                neighbors1.erase(neighbors1.begin() + i);
                break;
            }
        }

        // Remove the edge from label2 to label1
        std::vector<std::pair<std::string, unsigned long> >& neighbors2 = adjList[label2];
        for (size_t i = 0; i < neighbors2.size(); ++i) {
            if (neighbors2[i].first == label1) {
                neighbors2.erase(neighbors2.begin() + i);
                break;
            }
        }
    }
}

// Compute the shortest path using Dijkstra's algorithm
unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, 
                                  std::vector<std::string>& path) {
    // Define a priority queue to store {distance, vertex} pairs
    typedef std::pair<unsigned long, std::string> PQElement;
    std::priority_queue<PQElement, std::vector<PQElement>, std::greater<PQElement> > pq;

    // Map to store the shortest known distance to each vertex
    std::unordered_map<std::string, unsigned long> distances;

    // Map to store predecessors for path reconstruction
    std::unordered_map<std::string, std::string> predecessors;

    // Initialize distances to "infinity" (a very large number)
    for (std::unordered_map<std::string, std::vector<std::pair<std::string, unsigned long> > >::iterator it = adjList.begin();
         it != adjList.end(); ++it) {
        distances[it->first] = 1e9; // Simulate infinity
    }
    distances[startLabel] = 0; // Distance to the starting vertex is 0

    // Add the start vertex to the priority queue with distance 0
    pq.push(std::make_pair(0, startLabel));

    // Process the priority queue
    while (!pq.empty()) {
        // Get the vertex with the smallest distance
        PQElement current = pq.top();
        pq.pop();

        unsigned long currentDistance = current.first;
        std::string currentVertex = current.second;

        // Stop if we have reached the destination vertex
        if (currentVertex == endLabel) break;

        // Iterate through all neighbors of the current vertex
        std::vector<std::pair<std::string, unsigned long> >& neighbors = adjList[currentVertex];
        for (size_t i = 0; i < neighbors.size(); ++i) {
            std::string nextVertex = neighbors[i].first;
            unsigned long weight = neighbors[i].second;

            // Calculate the new distance to the neighbor
            unsigned long newDistance = currentDistance + weight;
            if (newDistance < distances[nextVertex]) {
                // Update the shortest known distance to the neighbor
                distances[nextVertex] = newDistance;
                // Update the predecessor of the neighbor
                predecessors[nextVertex] = currentVertex;
                // Add the neighbor to the priority queue
                pq.push(std::make_pair(newDistance, nextVertex));
            }
        }
    }

    // Reconstruct the shortest path
    path.clear();
    std::string step = endLabel;
    while (step != startLabel) {
        // If the destination is unreachable, return "infinity"
        if (predecessors.find(step) == predecessors.end()) return 1e9;
        path.insert(path.begin(), step); // Add the vertex to the path
        step = predecessors[step];      // Move to the predecessor
    }
    path.insert(path.begin(), startLabel); // Add the start vertex to the path

    // Return the shortest distance to the destination
    return distances[endLabel];
}
