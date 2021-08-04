class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0 && p.size() == 0) return true;
        else if (p.size() == 0) return false;
        vector<vector<bool>> dp(p.size() + 1, vector<bool> (s.size() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i < dp.size(); i++) {
            if (p[i - 1] == '*') dp[i][0] = dp[i - 1][0];
        }
        
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (p[i - 1] == s[j - 1]
                    || p[i - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if (p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1] | dp[i - 1][j - 1];
                }                
            }
        }
        
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};
