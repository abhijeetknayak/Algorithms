class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        if (nums.size() == 0) return dp; 
        
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = nums[i - 1] * dp[i - 1];
        }
        int rp = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {       
            rp *= nums[i + 1];
            dp[i] *= rp;
        }
        return dp;
    }
};
