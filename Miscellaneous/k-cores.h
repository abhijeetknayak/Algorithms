#include <bits/stdc++.h>

using namespace std;

class Graph {
	int N;  // Number of vertices
	list<int> * adj;  // Adjacency list representation+


	public:
	    Graph(int vertices);  // Constructor
	    void add_edge(int start, int end);  // Directed edge
	    void DFS(int source, int end);
	    void find_k_cores();
};

Graph::Graph(int vertices) {
	N = vertices;
	adj = new list<int>[N];
}

void Graph::add_edge(int start, int end) {
	/* Undirected graph */
	adj[start].push_back(end);
	adj[end].push_back(start);
}

void Graph::DFS(int source, int end) {
	/* Recursive implementation */
	list<int>::iterator i;
}

void Graph::find_k_cores() {


}



