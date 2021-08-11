class Solution {
public:
    bool check_location_valid(vector<int> matrix, int row, int col) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i] == -1) return true;
            if (matrix[i] - col == i - row
                || matrix[i] - col == row - i
                || matrix[i] == col) return false;
        }
        return true;
    }
    
    void recursive_helper_count(vector<int>& matrix, int row, int& count) {
        if (row == matrix.size()) { return; }
        
        int colMax = matrix.size();
        for (int i = 0; i < colMax; i++) {
            bool valid = check_location_valid(matrix, row, i);
            if (valid) {
                matrix[row] = i;
                if (row == colMax - 1) { 
                    count++; matrix[row] = -1;
                    continue;
                }
                recursive_helper_count(matrix, row + 1, count);
                matrix[row] = -1;
            }
        }
    }
    
    int totalNQueens(int n) {
        int count = 0;
        vector<int> m(n, -1);
        
	    recursive_helper_count(m, 0, count);
        return count;
    }
};
