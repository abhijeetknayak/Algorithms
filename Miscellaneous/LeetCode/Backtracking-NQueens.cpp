#include <iostream>
#include <vector>

using namespace std;

bool check_location_valid(vector<vector<int>>matrix, int row, int col) {

	/* Check Row */
	for (int i = 0; i < col; i++) {
		if (matrix[row][i]) return false;
	}

	/* Check Column */
	for (int i = 0; i < row; i++) {
		if (matrix[i][col]) return false;
	}

	/* Check Diagonally - Left Up */
	int i = row - 1, j = col - 1;
	while (i >= 0 && j >= 0) {
		if (matrix[i][j]) return false;
		i--; j--;
	}

	/* Check Diagonally - Right Up */
	i = row - 1; j = col + 1;
	while (i >= 0 && j < matrix[0].size()) {
		if (matrix[i][j]) return false;
		i--; j++;
	}

	/* If we don't return before, the place works for a queen */
	return true;
}

bool recursive_helper(vector<vector<int>>& matrix, int row) {
	if (row == matrix.size()) return true;
	int col = -1;
	int colMax = matrix[0].size();
	for (int i = 0; i < colMax; i++) {
		bool valid = check_location_valid(matrix, row, i);
		if (valid) {
			col = i;
			matrix[row][i] = 1;
			if (recursive_helper(matrix, row + 1)) return true;
			else matrix[row][i] = 0;
		}
	}

	/* If no value fits, Reset  */
	if (col != -1) matrix[row][col] = 0;
	return false;
}

void solveNQueens(vector<vector<int>> matrix) {
	(void)recursive_helper(matrix, 0);
	for (auto row : matrix) {
		for (auto colEle : row) {
			cout << colEle << " ";
		}
		cout << endl;
	}
}

int main() {
	vector<vector<int>> matrix(8, vector<int>(8, 0));
	solveNQueens(matrix);
}

