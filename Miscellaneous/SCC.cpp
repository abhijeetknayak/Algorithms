#include <bits/stdc++.h>
#include "SCC.h"

using namespace std;

int main() {

	Graph g(5);

    g.add_edge(1, 0);
    g.add_edge(0, 2);
    g.add_edge(2, 1);
    g.add_edge(0, 3);
    g.add_edge(3, 4);

    g.get_SCC();

	return 0;
}
