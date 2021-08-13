class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        vector<double> dp(nums.size(), 0.0);
        vector<double> first_row(nums.size(), 0.0), temp(nums.size(), 0.0);
        
        first_row[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            first_row[i] = first_row[i - 1] + nums[i];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = first_row[i] / (i + 1);
        }
        
        for (int k_idx = 1; k_idx < k; k_idx++) {
            temp[0] = dp[0];
            for (int i = 0; i < nums.size(); i++) {
                for (int j = 0; j < i; j++) {
                    double val = dp[j] + (first_row[i] - first_row[j]) / (i - j);
                    temp[i] = max(temp[i], val);
                }
            }
            
            for (int i = 0; i < nums.size(); i++) {
                dp[i] = temp[i];
            }
        }
        
        return dp[nums.size() - 1];
    }
};
