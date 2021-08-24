class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0') return 0;
        int dp[101], val = 0, prev_val = 0;
        
        dp[0] = 1;
        if (s.size() >= 2) {
            dp[1] = 1;
            val = s[1] - '0';
            prev_val = s[0] - '0';
            if (val == 0) {
                if (prev_val <= 2) dp[1] = 1;
                else return 0;
            }
            else if (prev_val != 0 && 
                prev_val * 10 + val <= 26) {
                dp[1] = 2;
            }
        }
        
        for (int i = 2; i < s.size(); i++) {
            if (s[i] == '0') {
                val = s[i - 1] - '0';
                if (val > 2 || val == 0) return 0;
                else if (i >= 2) {
                    dp[i] = dp[i - 2];
                }
                else dp[i] = 1;
            }
            else {
                /* Non zero character */
                dp[i] = dp[i - 1];
                
                val = s[i] - '0';
                prev_val = s[i - 1] - '0';
                if (prev_val != 0 && 
                    prev_val * 10 + val <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        
        return dp[s.size() - 1];
    }
};
