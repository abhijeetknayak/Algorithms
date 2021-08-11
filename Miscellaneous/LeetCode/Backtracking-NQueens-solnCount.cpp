class Solution {
public:
    bool check_location_valid(vector<vector<int>>matrix, int row, int col) {

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
    
    void recursive_helper_count(vector<vector<int>>& matrix, int row, int& count) {
        if (row == matrix.size()) {
            count++; return; 
        }
        int colMax = matrix[0].size();
        for (int i = 0; i < colMax; i++) {
            bool valid = check_location_valid(matrix, row, i);
            if (valid) {
                matrix[row][i] = 1;
                recursive_helper_count(matrix, row + 1, count);
                matrix[row][i] = 0;
            }
        }
    }
    
    int totalNQueens(int n) {
        int count = 0;
        vector<vector<int>> m(n, vector<int>(n, 0));
	    recursive_helper_count(m, 0, count);
        return count;
    }
};
