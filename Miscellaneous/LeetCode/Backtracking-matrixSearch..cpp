class Solution {
public:
    bool recursive_helper(vector<vector<char>>& board, vector<vector<bool>>& visited,
                          string word, int row, int col, int str_idx) {
        // if (str_idx )
        /* Left Neighbor */
        if (col - 1 >= 0 && !visited[row][col - 1] && board[row][col - 1] == word[str_idx]) {
            visited[row][col - 1] = true;
            if (str_idx == word.size() - 1) return true;
            if (recursive_helper(board, visited, word, row, col - 1, str_idx + 1)) return true;
            visited[row][col - 1] = false;
        }
        
        /* Right Neighbor */
        if (col + 1 < board[0].size() && !visited[row][col + 1] && board[row][col + 1] == word[str_idx]) {
            visited[row][col + 1] = true;
            if (str_idx == word.size() - 1) return true;
            if (recursive_helper(board, visited, word, row, col + 1, str_idx + 1)) return true;
            visited[row][col + 1] = false;
        }
        
        /* Top Neighbor */
        if (row - 1 >= 0 && !visited[row - 1][col] && board[row - 1][col] == word[str_idx]) {
            visited[row - 1][col] = true;
            if (str_idx == word.size() - 1) return true;
            if (recursive_helper(board, visited, word, row - 1, col, str_idx + 1)) return true;
            visited[row - 1][col] = false;
        }
        
        /* Bottom Neighbor */
        if (row + 1 < board.size() && !visited[row + 1][col] && board[row + 1][col] == word[str_idx]) {
            visited[row + 1][col] = true;
            if (str_idx == word.size() - 1) return true;
            if (recursive_helper(board, visited, word, row + 1, col, str_idx + 1)) return true;
            visited[row + 1][col] = false;
        }
        
        return false;        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false)); 
        bool result = false;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (word.size() == 1) return true;
                    visited[i][j] = true;
                    result = recursive_helper(board, visited, word, i, j, 1);
                    if (result == true) return true;
                    visited[i][j] = false;
                }
            }
        }
        
        return false;
    }
};
