class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<bool> dp(s.size(), false);
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty() && s[st.top()] == '(') {
                    dp[i] = true;
                    dp[st.top()] = true; st.pop();
                }
            }
        }
        
        int max_len = 0;
        string str = "";
        
        for (int i = 0; i <= s.size(); i++) {
            if (i < s.size() && dp[i] == true) str += s[i];
            else {
                int len = str.size();
                if (len > max_len) max_len = len;
                str = "";
            }
        }
                
        return max_len;
    }
};
