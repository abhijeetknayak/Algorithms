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


