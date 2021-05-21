vector<int> BFS(vector<vector<int>> graph, int start) {
	vector<int> explored;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int node = q.front(); q.pop();
		if (find(explored.begin(), explored.end(), node) == explored.end()) {
			explored.push_back(node);
		}		
		
		for (int i = 0; i < graph[node].size(); i++) {
			if (find(explored.begin(), explored.end(), graph[node][i]) == explored.end()) {
				q.push(graph[node][i]);
			}
		}
	}
	return explored;
}
