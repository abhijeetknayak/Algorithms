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
    
    int jump_O1Space(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        int last_index = 0, jumps = 1, next_index = 0;
        for (int i = 1; i < n; i++) {
            if (i - last_index <= nums[last_index]) {
                /* Last Index still helps us reach here. Dont increment Jump */
            }
            else {
                /* Use new index now */
                last_index = next_index;
                jumps += 1;
            }
            
            if (i + nums[i] > next_index + nums[next_index]) next_index = i;
        }
        
        return jumps;
    }
};
