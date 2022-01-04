#include <vector>
using namespace std;

vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
	int num_items = items.size();
	if (num_items == 0) return {{0}, {}};
	
	// Construct Values vector
	vector<vector<int>> values(num_items + 1, vector<int> (capacity + 1, 0));
	
	for (int i = 1; i < values.size(); i++) {
		// Loop over the items
		int weight = items[i - 1][1];
		int value = items[i - 1][0];
		for (int j = 0; j < values[0].size(); j++) {
			// Loop over the capacities
			if (weight <= j) {
				// Current item fits in the bag
				values[i][j] = max(values[i - 1][j], value + values[i - 1][j - weight]);
			}
			else {
				values[i][j] = values[i - 1][j];
			}
		}
	}
	
	vector<vector<int>> result = {{}, {}};
	
	// Find which items were used
	int row_idx = num_items, col_idx = capacity;
	while(row_idx > 0) {
		if (values[row_idx][col_idx] == values[row_idx - 1][col_idx]) {
			//Item was not used. Decrement row Idx, column idx stays the same
			row_idx = row_idx - 1;
		}
		else {
			// Item was used
			result[1].push_back(row_idx - 1);
			col_idx -= items[row_idx - 1][1];
			row_idx -= 1;
		}
		if (row_idx == 0) break;
	}
	result[0].push_back(values[num_items][capacity]);
	return result;
}
