void recursion_helper(int start_val, int curr_len, int n, int k,
		vector<vector<int>>& result, vector<int>& temp) {
	curr_len += 1;
	for (int i = start_val; i < n + 1; i++) {
		if (curr_len == k) {
			temp.push_back(i);
			result.push_back(temp);
			temp.pop_back();
		}
		else if (curr_len < k) {
			temp.push_back(i);
			recursion_helper(i + 1, curr_len, n, k, result, temp);
			temp.pop_back();
		}
		else return;
	}
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> result;
	vector<int> temp;

    recursion_helper(1, 0, n, k, result, temp);

    return result;
}
