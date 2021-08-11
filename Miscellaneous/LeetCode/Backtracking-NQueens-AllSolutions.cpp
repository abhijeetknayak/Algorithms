class Solution {
public:
    bool check_location_valid_str(vector<string>matrix, int row, int col) {
        /* Check Column */
        for (int i = 0; i < row; i++) {
            if (matrix[i][col] == 'Q') return false;
        }

        /* Check Diagonally - Left Up */
        int i = row - 1, j = col - 1;
        while (i >= 0 && j >= 0) {
            if (matrix[i][j] == 'Q') return false;
            i--; j--;
        }

        /* Check Diagonally - Right Up */
        i = row - 1; j = col + 1;
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] == 'Q') return false;
            i--; j++;
        }

        /* If we don't return before, the place works for a queen */
        return true;
    }
    
    void recursive_helper_count_str(vector<string>& matrix, int row, 
                                    vector<vector<string>>& result) {
        if (row == matrix.size()) return;
        for (int i = 0; i < matrix[0].size(); i++) {
            bool valid = check_location_valid_str(matrix, row, i);
            if (valid) {
                matrix[row][i] = 'Q';
                if (row == matrix.size() - 1) {
                    result.push_back(matrix);
                    matrix[row][i] = '.';  continue;
                }			
                recursive_helper_count_str(matrix, row + 1, result);
                matrix[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> matrix(n, std::string (n, '.'));
        
        recursive_helper_count_str(matrix, 0, result);
        
        return result;
    }
};
