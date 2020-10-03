#include <bits/stdc++.h>

using namespace std;

class Graph {
	int N;  // Number of vertices
	list<int> * adj;  // Adjacency list representation

	public:
	    Graph(int vertices);  // Constructor
	    void add_edge(int start, int end);  // Directed edge
	    void DFS(int source, bool explored[]);
	    void fill_stack(int source, bool explored[], stack<int> &s);
	    Graph reverse_graph();
	    void get_SCC();
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
	cout << source << " ";
	list<int>::iterator i;
	for (i = adj[source].begin(); i != adj[source].end(); i++) {
		if (explored[*i] == false) {
			DFS(*i, explored);
		}
	}
}

void Graph::fill_stack(int source, bool explored[], stack<int> &s) {
	/* Recursive implementation */
	explored[source] = true;
	list<int>::iterator i;
	for (i = adj[source].begin(); i != adj[source].end(); i++) {
		if (explored[*i] == false) {
			fill_stack(*i, explored, s);
		}
	}
	s.push(source);  // Earliest finishing time will be at the end
}

void Graph::get_SCC(void) {
	bool * explored = new bool[N];
	for (int i = 0; i < N; i++) {
		explored[i] = false;
	}

	stack<int> order;
	for (int i = 0; i < N; i++) {
		if (!explored[i])
			fill_stack(i, explored, order);
	}

	Graph reverse = reverse_graph();

	for (int i = 0; i < N; i++) {
		explored[i] = false;
	}

	while (!order.empty()) {
		int source = order.top();
		order.pop();

		if (!explored[source]) {
			reverse.DFS(source, explored);
			cout << endl;  // New SCC
		}



	}
}
Graph Graph::reverse_graph(void) {
	Graph output(N);
	for (int n = 0; n < N; n++) {
		list<int>::iterator i;
		for (i = adj[n].begin(); i != adj[n].end(); i++) {
			output.adj[*i].push_back(n);
		}
	}

	return output;
}
