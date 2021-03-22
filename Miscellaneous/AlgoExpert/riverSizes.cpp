void explore_neighbors(vector<vector<int>>& matrix, int i, int j, int& ret, int rows, int cols) {
	if (((j - 1) >= 0) && (matrix[i][j - 1])) {
		/* Left Neighbor valid */
		ret += 1; matrix[i][j - 1] = 0;
		explore_neighbors(matrix, i, j - 1, ret, rows, cols);
	}
	if (((j + 1) < cols) && (matrix[i][j + 1])) {
		/* Right Neighbor valid */
		ret += 1; matrix[i][j + 1] = 0;
		explore_neighbors(matrix, i, j + 1, ret, rows, cols);
	}
	if (((i - 1) >= 0) && (matrix[i - 1][j])) {
		/* Up Neighbor valid */
		ret += 1; matrix[i - 1][j] = 0;
		explore_neighbors(matrix, i - 1, j, ret, rows, cols);
	}
	if (((i + 1) < rows) && (matrix[i + 1][j])) {
		/* Down Neighbor valid */
		ret += 1; matrix[i + 1][j] = 0;
		explore_neighbors(matrix, i + 1, j, ret, rows, cols);
	}
}

vector<int> riverSizes(vector<vector<int>> matrix) {

	/* Get rows and columns of matrix */
	int rows = matrix.size(), cols = 0, ret = 0;
	if (rows != 0) cols = matrix[0].size();

	vector <int> result;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == 1) {
				/* River: Change value and explore neighbors */
				ret += 1;
				matrix[i][j] = 0;
				explore_neighbors(matrix, i, j, ret, rows, cols);
				result.push_back(ret);
			}
			ret = 0;
		}
	}
  return result;
}
