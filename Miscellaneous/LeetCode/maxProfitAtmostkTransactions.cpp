int maxProfit(vector<int>& prices) {
    int k = 2;
    int n = prices.size();
    int dp[k + 1][n], m_b = 0, m_b1 = 0;

    for(int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= k; i++) {
        m_b1 = -INT_MAX;
        for(int j = 1; j < n; j++) {
            m_b1 = max(m_b1, dp[i - 1][j - 1] - prices[j - 1]);
            dp[i][j] = max(dp[i][j - 1], m_b1 + prices[j]);
        }
    }
  
    return dp[k][n - 1];
}
