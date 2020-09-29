#include <bits/stdc++.h>
#include "graph-search.h"

using namespace std;

int main() {
	Graph graph(8);
	graph.add_edge(0, 1);
	graph.add_edge(1, 2);
	graph.add_edge(2, 3);
	graph.add_edge(2, 7);
	graph.add_edge(3, 6);
	graph.add_edge(3, 4);
	graph.add_edge(5, 1);
	graph.add_edge(5, 7);
	graph.add_edge(5, 3);
	
	graph.print_graph();
	
	return 0;
}