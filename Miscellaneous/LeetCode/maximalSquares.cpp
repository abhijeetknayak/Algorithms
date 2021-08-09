class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), 0));
        int result = 0;
        for (int i = 0; i < dp.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
            if (dp[i][0] > result) result = dp[i][0];
        }
        for (int i = 0; i < dp[0].size(); i++) {
            dp[0][i] = matrix[0][i] - '0';
            if (dp[0][i] > result) result = dp[0][i];
        }
        
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {                
                if (matrix[i][j] == '1') {
                    if (dp[i - 1][j] != 0 && dp[i][j - 1] != 0
                        && dp[i - 1][j - 1] != 0) {
                        int min_val = min(dp[i - 1][j], dp[i][j - 1]);
                        min_val = min(min_val, dp[i - 1][j - 1]);
                        dp[i][j] = min_val + 1;                 
                    }
                    else dp[i][j] = 1;
                    
                    if (dp[i][j] > result) result = dp[i][j]; 
                    cout << result << endl;

                }

            }
        }
        
        return result * result;
    }
};
