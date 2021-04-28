#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
	int r1 = 0, c1 = 0, r2 = matrix.size() - 1, c2 = matrix[0].size() - 1;
	
	while(r1 < r2 && c1 < c2) {
		int m1 = r1 + (r2 - r1) / 2;
		int m2 = c1 + (c2 - c1) / 2;
		
		if (matrix[m1][m2] == target) return vector<int>{m1, m2};
		else if (matrix[m1][m2] > target) {
			r2 = m1; c2 = m2;
		}
		else {
			r1 = m1 + 1;
			c1 = m2 + 1;
		}
	}
	
	for (int i = 0; i <= c1; i++) {
		if (matrix[r1][i] == target) return vector<int> {r1, i};
	}
	
	for(int i = 0; i <= r1; i++) {
		if (matrix[i][c1] == target) return vector<int> {i, c1};
	} 
  return vector<int> {-1, -1};
}
