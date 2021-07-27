#include <vector>
#include <unordered_map>

using namespace std;

vector<int> get_closest_location(
	vector<unordered_map<string, bool>> blocks,
	string req) {
	vector<int> result (blocks.size(), numeric_limits<int>::max);
	for (int i = 1; i < blocks.size(); i++) {
		if (blocks[i][req]) result[i] = 0;
		else result[i] = result[i - 1] + 1;
	}
	
	for (int i = blocks.size() - 2; i >= 0; i--) {
		blocks[i] = min(blocks[i], blocks[i + 1]);
	}
	
}

vector<int> getMaxValues(vector<vector<int>> table) {
	vector<int> result(table[0].size(), 0);
	for (int i = 0; i < table.size(); i++) {
		int max_val = INT_MIN;
		for (int j = 0; j < table[0].size(); j++) {
			max_val = max(max_val, table[i][j]);
		}
		result[i] = max_val;
	}
	return result;
}

int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {
	vector<vector<int>> table;
	for (auto req : reqs) {
		table.push_back(get_closest_location(blocks, req));
	}
	
	vector<int> result = getMaxValue(table);
	int min_val = INT_MAX, min_idx = -1;
	for (int i = 0; i < result.size(); i++) {
		if (result[i] < min_val) {
			min_val = result[i];
			min_idx = i;
		}
	}
	
	return min_idx;
}
