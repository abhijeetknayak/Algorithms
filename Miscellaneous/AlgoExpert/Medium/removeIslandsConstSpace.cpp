#include <vector>
using namespace std;

void recursive_helper(vector<vector<int>>& matrix, int row, int col) {
	if (row < 0 || row > matrix.size() - 1) return;
	if (col < 0 || col > matrix[0].size() - 1) return;
	if (matrix[row][col] == 1) {
		matrix[row][col] += 1;
		
		recursive_helper(matrix, row, col - 1);
	  recursive_helper(matrix, row, col + 1);
	  recursive_helper(matrix, row - 1, col);	
	  recursive_helper(matrix, row + 1, col);	
	}
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
	int rows = matrix.size(), cols = matrix[0].size();
	for (int i = 0; i < matrix.size(); i++) {
		if (matrix[i][0] == 1) {
			recursive_helper(matrix, i, 0);
		}
		if (matrix[i][cols - 1] == 1) {
			recursive_helper(matrix, i, cols - 1);			
		}
	}
	
	for (int i = 0; i < matrix[0].size(); i++) {
	  if (matrix[0][i] == 1) {
			recursive_helper(matrix, 0, i);	
		}
		if (matrix[rows - 1][i] == 1) {
			recursive_helper(matrix, rows - 1, i);	
		}	
	}
	
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] != 0)	matrix[i][j] -= 1;
		}
	}
  return matrix;
}
