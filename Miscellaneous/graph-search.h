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

		void DFS(int source);
};

/* Constructor */
Graph::Graph(int nodes) {
	N = nodes;
	adj = new list<int>[N];
}

void Graph::add_edge(int start, int end) {
	/* Undirected Graph */
	adj[start].push_back(end);
	adj[end].push_back(start);
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

void Graph::BFS(int source) {
	// Starting from the source node, traverse the entire graph
	list<int> frontier;
	bool * explored = new bool[N];

	for (int i = 0; i < N; i++) {
		explored[i] = false;
	}

	explored[source] = true; // Add source node to frontier
	frontier.push_back(source);

	list<int>::iterator i;

	while (!frontier.empty()) {
		int first = frontier.front();
		frontier.pop_front();
		cout << first << endl;

		/* Add all connections from the first node into the frontier */
		for (i = adj[first].begin(); i != adj[first].end(); i++) {
			if (explored[*i] == false) {
				/* New node not in frontier. Add it to the frontier */
				explored[*i] = true;
				frontier.push_back(*i);
			}
		}
	}
}

void Graph::DFS(int source) {
	list<int> frontier;
	bool * explored = new bool[N];

	for (int i = 0; i < N; i++) {
		explored[i] = false;
	}

	explored[source] = true;
	frontier.push_back(source);

	list<int>::iterator i;
	while(!frontier.empty()) {
		int last = frontier.back();
		frontier.pop_back();

		cout << last << endl;

		for (i = adj[last].begin(); i != adj[last].end(); i++) {
			if (explored[*i] == false) {
				explored[*i] = true;
				frontier.push_back(*i);
			}
		}
	}












}
