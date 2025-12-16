#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <utility>  // For std::pair
#include "LinkedBagDS/LinkedBag.h"
#include "Event.h"

using namespace std;

// Template class for a Graph
template <typename T>
class Graph {
public:
    // Constructor
    Graph(int vertices, bool directed = false);

    // Add an edge
    void addEdge(int u, int v, T weight = T());

    // Get number of nodes
    int getNumVertices() const;

    // Print the adjacency list
    void printGraph() const;
    
    // -----------------------------------------------------
    // Depth First Search
    void DFS(int startVertex, const vector<Event>& events) const;
    
private:
    // DFS Recursive helper function
    void DFSRecursive(int vertex, vector<bool>& visited, const vector<Event>& events) const;
    int V; // Number of vertices
    bool directed; // Whether the graph is directed or undirected
    vector<LinkedBag<pair<int, T>>> adjList; // Adjacency list
};

// Include the implementation of template functions
#include "Graph.cpp"

#endif // GRAPH_H
