#include <bits/stdc++.h>
#include "mother-vertex.h"

using namespace std;

int main() {
    Graph g(7);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(4, 1);
    g.add_edge(6, 4);
    g.add_edge(5, 6);
    g.add_edge(5, 2);
    g.add_edge(6, 0);

    int mother_vertex = g.find_mother_vertex();

    cout << mother_vertex << endl;

	return 0;
}
