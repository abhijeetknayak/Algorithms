#include <vector>
using namespace std;

void updateQueues(queue<pair<int, int>>& q, queue<pair<int, int>>& queueToUpdate, vector<vector<int>>& matrix) {
	while(!q.empty()) {
		pair<int, int> top = q.front(); q.pop();
		int r = top.first, c = top.second;
		if (r - 1 >= 0 && matrix[r - 1][c] < 0) {
			matrix[r - 1][c] *= -1;
			queueToUpdate.push(make_pair(r - 1, c));
		}
		if (c - 1 >= 0 && matrix[r][c - 1] < 0) {
			matrix[r][c - 1] *= -1;
			queueToUpdate.push(make_pair(r, c - 1));
		}
		if (r + 1 < matrix.size() && matrix[r + 1][c] < 0) {
			matrix[r + 1][c] *= -1;
			queueToUpdate.push(make_pair(r + 1, c));
		}
		if (c + 1 < matrix[0].size() && matrix[r][c + 1] < 0) {
			matrix[r][c + 1] *= -1;
			queueToUpdate.push(make_pair(r, c + 1));
		}
	}
}

int minimumPassesOfMatrix(vector<vector<int>> matrix) {
	queue<pair<int, int>> q1, q2;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] > 0) q1.push(make_pair(i, j));
		}
	}
	bool use_q1 = true, use_q2 = false;
	int count = 0;
	while(!q1.empty() || !q2.empty()) {
		if (use_q1) {
			updateQueues(q1, q2, matrix);
			use_q1 = false; use_q2 = true;
			count += 1;
		}
		else {
			updateQueues(q2, q1, matrix);
			use_q1 = true; use_q2 = false;
			count += 1;
		}
	}
	
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[0].size(); j++) {
			if (matrix[i][j] < 0) return -1;
		}
	}
	
	
  return count - 1;
}
