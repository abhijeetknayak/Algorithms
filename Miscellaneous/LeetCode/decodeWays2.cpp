class Solution {
public:
    int numDecodings(string s) {
        const unsigned int M = 1000000007;
        if (s.size() == 0 || s[0] == '0') return 0;
        if (s.size() == 1) {
            if (s[0] == '*') return 9;
            else if (s[0] == '0') return 0;
            else return 1;
        }
        
        unsigned long long dp[1000001], val = 0, prev_val = 0;
        if (s[0] == '*') {
            dp[0] = 9;
            if (s[1] == '*') dp[1] = 96;
            else if (s[1] == '0') dp[1] = 2;
            else {
                val = s[1] - '0';
                if (val <= 6) dp[1] = dp[0] + 2;
                else dp[1] = dp[0] + 1;
            }
        }
        else {
            /* First character not zero or '*' */
            dp[0] = 1;
            if (s[1] == '*') {
                if (s[0] == '1') dp[1] = 18;
                else if (s[0] == '2') dp[1] = 15;
                else dp[1] = 9;
            }
            else {
                val = s[1] - '0'; prev_val = s[0] - '0';
                if (val == 0) {
                    if (prev_val == 0 || prev_val > 2) return 0;
                    dp[1] = dp[0];
                }
                else {
                    dp[1] = dp[0];
                    if (prev_val * 10 + val <= 26) dp[1]++;
                }
                
            }
        }
        
        for (int i = 2; i < s.size(); i++) {
            if (s[i] == '*') {
                if (s[i - 1] == '*') dp[i] = (dp[i - 1] * 9 + dp[i - 2] * 15) % M;
                else if (s[i - 1] == '1')
                    dp[i] = ((dp[i - 1] + dp[i - 2]) * 9) % M;
                else if (s[i - 1] == '2')
                    dp[i] = (dp[i - 1] * 9 + dp[i - 2] * 6) % M;
                else dp[i] = (dp[i - 1] * 9) % M;
            }
            else if (s[i] == '0') {
                if (s[i - 1] == '*') 
                    dp[i] = (dp[i - 2] * 2) % M;
                else {
                    prev_val = s[i - 1] - '0';
                    if (prev_val > 2 || prev_val == 0) return 0;
                    else dp[i] = dp[i - 2];
                }
            }
            else {
                if (s[i - 1] == '*') {
                    val = s[i] - '0';
                    if (val <= 6) dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % M;
                    else dp[i] = (dp[i - 1] + dp[i - 2]) % M;
                }
                else if (s[i - 1] == '0') dp[i] = dp[i - 1];
                else {
                    /* Characters at i and i - 1 are non zero numbers */
                    dp[i] = dp[i - 1];
                    val = s[i] - '0'; prev_val = s[i - 1] - '0';
                    if (prev_val * 10 + val <= 26) dp[i] = (dp[i] + dp[i - 2]) % M;
                }
            }
            
        }
        
        
        return dp[s.size() - 1] % M;
    }
};
