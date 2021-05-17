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
