#include <bits/stdc++.h>

using namespace std;

class Graph {
	int N;  // Number of vertices
	list<int> * adj;  // Adjacency list representation
	bool ** tc;  // [V * V] matrix to store transitive closure matrix

	public:
	    Graph(int vertices);  // Constructor
	    void add_edge(int start, int end);  // Directed edge
	    void DFS(int source, int end);
	    void find_transitive_matrix();
};

Graph::Graph(int vertices) {
	N = vertices;
	adj = new list<int>[N];
	tc = new bool * [N];
	for (int i = 0; i < N; i++) {
		tc[i] = new bool[N];
		memset(tc[i], false, sizeof(bool) * N);
	}

}

void Graph::add_edge(int start, int end) {
	/* Add Directed edges */
	adj[start].push_back(end);
}

void Graph::DFS(int source, int end) {
	/* Recursive implementation */
	tc[source][end] = true;
	list<int>::iterator i;
	for (i = adj[source].begin(); i != adj[source].end(); i++) {
		if (!tc[source][*i]) {
			DFS(source, *i);
		}
	}
}

void Graph::find_transitive_matrix(void) {
	for (int i = 0; i < N; i++)
		DFS(i, i);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << tc[i][j] << " ";
		}
		cout << endl;
	}
}



