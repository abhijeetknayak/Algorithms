class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> dp(nums.size(), 0);
        int n = nums.size();
        dp[n - 1] = nums[n - 1];
        
        q.push_back(n - 1);
        
        for (int i = n - 2; i >= 0; i--) {
            if (q.front() - i > k) q.pop_front();
            dp[i] = dp[q.front()] + nums[i];
            
            /* Pop out elements that are smaller than dp[i] */
            while(!q.empty() && dp[q.back()] < dp[i]) q.pop_back();
            
            q.push_back(i);
        }
        
        return dp[0];
    }
};
