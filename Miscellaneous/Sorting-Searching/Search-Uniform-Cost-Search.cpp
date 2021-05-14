#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void uniform_cost_search(vector<vector<vector<int>>> graph, int start) {
	priority_queue<pair<int, int>> queue;
	map<int, int> visited_nodes;

	queue.push(make_pair(0, start));

	while (!queue.empty()) {
		pair<int, int> queue_top = queue.top();
		queue.pop();

		int greedy_cost = queue_top.first;
		int index = queue_top.second;
		if (visited_nodes.find(index) != visited_nodes.end()) continue;

		visited_nodes[index] = -1 * greedy_cost;

		for (int i = 0; i < graph[index].size(); i++) {
			int neighbor = graph[index][i][0];
			/* Process the unexplored nodes */
			int cost = visited_nodes[index] + graph[index][i][1];
			queue.push(make_pair(-1 * cost, neighbor));
		}
	}

	for (auto it : visited_nodes) {
		cout << it.first << " -> " << it.second << endl;
	}
}

int main() {
	vector<vector<vector<int>>> graph { {{1, 2}, {3, 5}}, {{6, 1}}, {{1, 4}}, {{1,5}, {4, 2}, {6, 6}}, {{2, 4}, {5, 5}},
		{{2, 6}, {6, 3}}, {{4, 7}} };
	uniform_cost_search(graph, 0);
	return 0;
}
