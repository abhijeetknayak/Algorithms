#include <bits/stdc++.h>

using namespace std;

void add_edge(vector<int> nodes[], int start, int end) {
	/* Add connected nodes to vector */
	nodes[start].push_back(end);
	nodes[end].push_back(start);	
}

print_graph(vector <int> nodes[], int N) {
	for (int i = 0; i < N; i++) {
		cout << i << " -> ";
		for (auto element : nodes[i]) {
			cout << element << " -> ";			
		}
		cout << endl;	
	}	
}

int main() {
	int N = 0;
	cin >> N;
	
	/* Array of Nodes */
	vector<int> nodes[N];
	
	add_edge(nodes, 0, 1);
	add_edge(nodes, 0, 2);
	add_edge(nodes, 1, 2);
	add_edge(nodes, 2, 3);
	add_edge(nodes, 1, 4);
	add_edge(nodes, 8, 4);
	add_edge(nodes, 4, 5);
	add_edge(nodes, 5, 1);
	add_edge(nodes, 2, 6);
	add_edge(nodes, 2, 8);
	add_edge(nodes, 7, 6);
	
	print_graph(nodes, N);
	
	return 0;
}