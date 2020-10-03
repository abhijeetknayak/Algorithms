#include <bits/stdc++.h>

using namespace std;

class Graph {
	int N;  // Number of vertices
	list<int> * adj;  // Adjacency list representation

	public:
	    Graph(int vertices);  // Constructor
	    void add_edge(int start, int end);  // Directed edge
	    void DFS(int source, bool explored[]);
	    int find_mother_vertex();
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

int Graph::find_mother_vertex(void) {
	int mother_vertex;
	bool * explored = new bool[N];

	for (int i = 0; i < N; i++)
		explored[i] = false;

	for (int i = 0; i < N; i++) {
		if (!explored[i]) {
			DFS(i, explored);
			mother_vertex = i;
		}
	}

	for (int i = 0; i < N; i++)
		explored[i] = false;

	/* Perform a DFS from the mother vertex and check if all vertices are reached */
	DFS(mother_vertex, explored);

	for (int i = 0; i < N; i++)
		if (!explored[i])  // Some vertex is unreachable
			return -1;
	return mother_vertex;
}

