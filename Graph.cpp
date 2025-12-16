#include "Graph.h"

// Constructor
template <typename T>
Graph<T>::Graph(int vertices, bool directed)
    : V(vertices), directed(directed) {
    adjList.resize(V);
}

// Add an edge
template <typename T>
void Graph<T>::addEdge(int u, int v, T weight) {
    if (u == v) {
        return; //no self-edge
    }
    
    adjList[u].add({v, weight});
    if (!directed) {
        adjList[v].add({u, weight});
    }
}

// Get number of nodes
template <typename T>
int Graph<T>::getNumVertices() const{
	return V;
}

// Print the adjacency list
template <typename T>
void Graph<T>::printGraph() const {
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": ";
        vector<pair<int, T>> neighbors = adjList[i].toVector();
        for (const auto& neighbor : neighbors) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
}

// Depth-First Search
template <typename T>
void Graph<T>::DFS(int startVertex, const vector<Event>& events) const {
    if (startVertex < 0 || startVertex >= V) {
        cout << "Invalid start vertex!" << endl;
        return;
    }
    
    vector<bool> visited(V, false);
    cout << "DFS Traversal starting from vertex " << startVertex << ": ";
    DFSRecursive(startVertex, visited, events);
    cout << endl;
}

// DFS Recursive helper function
template <typename T>
void Graph<T>::DFSRecursive(int vertex, vector<bool>& visited, const vector<Event>& events) const {
    visited[vertex] = true;
    cout << "Vertex " << vertex << ":\n" << events[vertex] << endl;
    
    // Visit all unvisited neighbors
    for (const auto& neighbor : adjList[vertex]) {
        int neighborVertex = neighbor.first;
        if (!visited[neighborVertex]) {
            DFSRecursive(neighborVertex, visited, events);
        }
    }
}