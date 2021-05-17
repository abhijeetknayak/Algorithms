bool revise(vector<vector<int>> graph, vector<vector<int>>& domains, int start, int end) {
	bool allowed = false, modified = false;
	vector<int> new_domain = domains[start];
	for (int i = 0; i < domains[start].size(); i++) {
		allowed = false;
		for (int j = 0; j < domains[end].size(); j++) {
			if (domains[end][j] != domains[start][i]) { allowed = true; break; }
			else allowed = false;
		}
		if (allowed == false) {
			modified = true;
			int value = domains[start][i];
			new_domain.erase(new_domain.begin() + i);
		}
	}
	domains[start] = new_domain;

	return modified;
}

void populate_arcs(vector<vector<int>> graph, queue<pair<int, int>>& arcs) {
	vector<int> explored;
	queue<int> frontier;
	frontier.push(0);

	while (!frontier.empty()) {
		int node = frontier.front(); frontier.pop();
		if (find(explored.begin(), explored.end(), node) != explored.end()) continue;
		explored.push_back(node);

		for (int i = 0; i < graph[node].size(); i++) {
			arcs.push(make_pair(node, graph[node][i]));
			if (find(explored.begin(), explored.end(), graph[node][i]) == explored.end()) {
				frontier.push(graph[node][i]);
			}			
		}
	}
}

bool arc_consistency(vector<vector<int>> graph, vector<vector<int>>& domains) {
	queue<pair<int, int>> arcs;
	populate_arcs(graph, arcs);

	while (!arcs.empty()) {
		pair<int, int> p = arcs.front(); arcs.pop();
		if (revise(graph, domains, p.first, p.second)) {
			/* Domain revised. Add arcs to queue, exit is domain size is 0 */
			if (domains[p.first].size() == 0) return false;

			for (int i = 0; i < graph[p.first].size(); i++) {
				if (graph[p.first][i] != p.second) {
					arcs.push(make_pair(graph[p.first][i], p.first));
				}
			}
		}
	}

	return true;
}

int main() {
	vector<vector<int>> graph{ {1, 2, 4}, {0, 4}, {0, 3, 4, 5}, {2, 5}, {0, 1, 2, 5}, {2, 3, 4} };
	vector<vector<int>> domains{ {1, 2, 3}, {1}, {1, 3}, {1, 2, 3}, {1, 3}, {1, 2, 3} };
	cout << arc_consistency(graph, domains) << endl;
	for (int i = 0; i < domains.size(); i++) {
		cout << "Domain for Node " << i << ": ";
		for (int j = 0; j < domains[i].size(); j++) {
			cout << domains[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}


