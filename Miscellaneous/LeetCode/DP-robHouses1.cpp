class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;        
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);        
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        int max_val = max(dp[0], dp[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] - nums[i - 1] + nums[i],
                       dp[i - 2] + nums[i]);
            if (dp[i] > max_val) max_val = dp[i];
        }
        
        return max_val;        
    }
};
