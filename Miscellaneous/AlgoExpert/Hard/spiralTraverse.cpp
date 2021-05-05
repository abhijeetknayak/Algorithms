#include <vector>

using namespace std;

vector<int> zigzagTraverse(vector<vector<int>> array) {
	vector<int> result;
	bool down = 1; // Down
	
	result.push_back(array[0][0]);
	int i = 1, row = 0, col = 0, n_rows = array.size(), n_cols = array[0].size();
	
	while(i < n_rows * n_cols) {
		if (down) {
			if (col == 0) {
				if (row == n_rows - 1) { col++; down = 0; }
				else { row++; down = 0; }				
			}
			else if (row == n_rows - 1) { col++; down = 0; }
			else { col--; row++; }
			result.push_back(array[row][col]);
		}
		else {
			if (row == 0) {
				if (col == n_cols - 1) { row++; down = 1; }
				else { col++; down = 1; }				
			}
			else if (col == n_cols - 1) { row++; down = 1; }
			else { col++; row--; }
			result.push_back(array[row][col]);
		}
		
		i++;
	}
  return result;
}
