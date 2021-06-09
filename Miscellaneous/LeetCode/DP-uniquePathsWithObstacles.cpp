class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        bool valid = true;
        if (obstacleGrid[0][0] == 1) return 0;
        
        for (int i = 0; i < rows; i++) {
            if (valid && obstacleGrid[i][0] != 1) obstacleGrid[i][0] = 1;
            else { 
                obstacleGrid[i][0] = 0; valid = false;
            }
        }
        
        valid = true;
        for (int i = 1; i < cols; i++) {
            if (valid && obstacleGrid[0][i] != 1) obstacleGrid[0][i] = 1;
            else { 
                obstacleGrid[0][i] = 0; valid = false;
            }
        }
        
        for (int j = 1; j < cols; j++) {
            for (int i = 1; i < rows; i++) {
                if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
                else obstacleGrid[i][j] = obstacleGrid[i - 1][j] + 
                    obstacleGrid[i][j - 1];
            }
        }
        
        return obstacleGrid[rows - 1][cols - 1];
    }
};
