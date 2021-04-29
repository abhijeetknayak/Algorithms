#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
	int row = 0, col = matrix[0].size() - 1;
	while(row >= 0 && col >= 0) {
		if (matrix[row][col] == target) return vector<int> {row, col};
		else if (matrix[row][col] > target) col--;
		else row++;
	}
  return vector<int> {-1, -1};
}
