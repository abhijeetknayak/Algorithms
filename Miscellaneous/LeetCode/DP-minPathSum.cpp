class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int dp[rows][cols];
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        
        for (int i = 1; i < cols; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        
        
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        
        return dp[rows - 1][cols - 1];
        
    }
};
