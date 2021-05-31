class Solution {
public:
    int jump(vector<int>& nums) {
      /* DP Solution */
        int dp[nums.size()];
        for (int i = 1; i < nums.size(); i++) dp[i] = INT_MAX;
        dp[0] = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (j - i <= nums[i]) {
                    dp[j] = min(dp[j], dp[i] + 1);                   
                }                
            }
        }
        return dp[nums.size() - 1];
    }
};
