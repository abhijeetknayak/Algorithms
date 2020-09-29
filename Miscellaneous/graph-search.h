#include <bits/stdc++.h>

using namespace std;

class Graph {
	int N;  // Number of nodes
	
	list<int> *adj;  // Adjacency list
	
	public:
		Graph(int N);
		
		void add_edge(int start, int end);
		
		void print_graph();

		void BFS(int source);	
};

/* Constructor */
Graph::Graph(int nodes) {
	N = nodes;
	adj = new list<int>[N];
}

void Graph::add_edge(int start, int end) {
	adj[start].push_back(end);
}

void Graph::print_graph() {
	for (int i = 0; i < N; i++) {
		cout << i << " -> ";
		for (auto element : adj[i]) {
			cout << element << " -> ";
		}
		cout << "END" << endl;
	}
}
