#include <vector>
#include <unordered_map>

using namespace std;

vector<int> get_closest_location(
	vector<unordered_map<string, bool>> blocks,
	string req) {
	vector<int> result (blocks.size(), INT_MAX);
	if (blocks[0][req]) result[0] = 0;
	for (int i = 1; i < blocks.size(); i++) {
		if (blocks[i][req]) result[i] = 0;
		else if (result[i - 1] < INT_MAX) {
			result[i] = result[i - 1] + 1; 
		} 
	}	
	for (int i = blocks.size() - 2; i >= 0; i--) {
		result[i] = min(result[i], result[i + 1] + 1);
	}
	return result;
}

vector<int> getMaxValues(vector<vector<int>> table) {
	vector<int> result(table[0].size(), 0);
	for (int j = 0; j < table[0].size(); j++) {
		int max_val = INT_MIN;
		for (int i = 0; i < table.size(); i++) {
			max_val = max(max_val, table[i][j]);
		}
		result[j] = max_val;
	}
	return result;
}

int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {
	vector<vector<int>> table;
	for (auto req : reqs) {
		table.push_back(get_closest_location(blocks, req));
	}
	
	for(auto rows: table) {
		for (auto col : rows) {
			cout << col << " "; 
		}
		cout << endl;
	}
	
	vector<int> result = getMaxValues(table);
	int min_val = INT_MAX, min_idx = -1;
	for (int i = 0; i < result.size(); i++) {
		if (result[i] < min_val) {
			min_val = result[i];
			min_idx = i;
		}
	}
	
	return min_idx;
}
