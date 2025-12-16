#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Graph.h"
#include "Event.h"

using namespace std;
int main() {
	srand(static_cast<unsigned>(time(nullptr)));
	// Create a list of Events
	// Add 10 distinct events to the vector
	// TO DO 
    vector<Event> events;
    events.push_back(Event("Concert A", "Live music performance", 4.5, 120));
    events.push_back(Event("Concert B", "Rock concert night", 4.2, 98));
    events.push_back(Event("Festival C", "Outdoor music festival", 4.8, 300));
    events.push_back(Event("Play D", "Stage theater play", 4.0, 75));
    events.push_back(Event("Show E", "Comedy show", 4.6, 110));
    events.push_back(Event("Game F", "Sports game", 4.3, 200));
    events.push_back(Event("Opera G", "Opera performance", 4.7, 60));
    events.push_back(Event("Expo H", "Technology expo", 4.1, 180));
    events.push_back(Event("Movie I", "Premiere screening", 4.4, 250));
    events.push_back(Event("Talk J", "Guest speaker event", 4.9, 90));
	// Initialize a graph with n vertices (where n is the number of events) 
	//	 Indicate whether it is directed or undirected 
	// TO DO 
    // undirected graph because purchased toegther is mutual
    Graph<int> eventGraph(static_cast<int>(events.size()), false);

	// Add 15-20 edges (eventA, eventB, weight)
	// TO DO 
    auto w = []() { return rand() % 10 + 1; };

	// 16 edges
    eventGraph.addEdge(0, 1, w());
    eventGraph.addEdge(0, 2, w());
    eventGraph.addEdge(0, 9, w());
    eventGraph.addEdge(1, 3, w());
    eventGraph.addEdge(1, 4, w());
    eventGraph.addEdge(2, 5, w());
    eventGraph.addEdge(2, 6, w());
    eventGraph.addEdge(2, 8, w());
    eventGraph.addEdge(3, 7, w());
    eventGraph.addEdge(3, 5, w());
    eventGraph.addEdge(4, 6, w());
    eventGraph.addEdge(4, 8, w());
    eventGraph.addEdge(5, 9, w());
    eventGraph.addEdge(6, 7, w());
    eventGraph.addEdge(7, 8, w());
    eventGraph.addEdge(8, 9, w());

	// Display all events
	cout << "\n=== Event Ticket System - All Events ===" << endl;
	for (size_t i = 0; i < events.size(); ++i) {
		cout << "Vertex " << i << ":" << endl;
		cout << events[i] << endl;
	}

	// Print the adjacency list
	cout << "\n=== Graph Adjacency List (Vertex: Connected Vertices with Weights) ===" << endl;
	eventGraph.printGraph();
    
	// Perform DFS traversal from different starting vertices
	cout << "\n=== DFS Traversals ===" << endl;
	eventGraph.DFS(0, events);  // Starting from vertex 0
	eventGraph.DFS(5, events);  // Starting from vertex 5
	eventGraph.DFS(9, events);  // Starting from vertex 9
    
	return 0;
}
