#include <bits/stdc++.h>

using namespace std;

class Graph {
	int N;  // Number of vertices
	list<int> * adj;  // Adjacency list representation

	public:
	    Graph(int vertices);  // Constructor
	    void add_edge(int start, int end);  // Directed edge
	    void DFS(int source, bool explored[]);
	    void find_transitive_matrix();
};

Graph::Graph(int vertices) {
	N = vertices;
	adj = new list<int>[N];
}

void Graph::add_edge(int start, int end) {
	/* Add Directed edges */
	adj[start].push_back(end);
}

void Graph::DFS(int source, bool explored[]) {
	/* Recursive implementation */
	explored[source] = true;
	list<int>::iterator i;
	for (i = adj[source].begin(); i != adj[source].end(); i++) {
		if (explored[*i] == false) {
			DFS(*i, explored);
		}
	}
}



