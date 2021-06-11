#include <vector>
using namespace std;


void recursive_helper(vector<vector<int>>& matrix,
											vector<vector<int>>& visited, int row, int col,
										 bool& del_island) {
	if (row < 0 || row > matrix.size() - 1) return;
	if (col < 0 || col > matrix[0].size() - 1) return;
	if (visited[row][col]) return;
	
	visited[row][col] = 1;
	
	if (matrix[row][col] == 1) {		
		if (row == 0 || row == matrix.size() - 1
				|| col == 0 || col == matrix[0].size() - 1) {
			del_island = false;
		}
	}
	
	if (matrix[row][col]) {
		recursive_helper(matrix, visited, row, col - 1, del_island);
		recursive_helper(matrix, visited, row, col + 1, del_island);
		recursive_helper(matrix, visited, row - 1, col, del_island);	
		recursive_helper(matrix, visited, row + 1, col, del_island);	

	}
	
	if (del_island) matrix[row][col] = 0;
	
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
	vector<vector<int>> visited(matrix.size(),
															vector<int>(matrix[0].size()));
	bool del_island = true;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			del_island = true;
			if (!visited[i][j]) {
				recursive_helper(matrix, visited, i, j, del_island);
			}
		}
	}
  return matrix;
}
