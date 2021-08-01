class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int dp[height.size()], water = 0;
        dp[0] = 0;
        for (int i = 1; i < height.size(); i++) {
            dp[i] = max(height[i - 1], dp[i - 1]);
        }
        dp[height.size() - 1] = 0;
        int max_h = 0;
        for (int i = height.size() - 2; i >= 0; i--) {
            max_h = max(max_h, height[i + 1]);
            dp[i] = min(max_h, dp[i]);
        }
        for (int i = 1; i < height.size() - 1; i++) {
            int rem_h = dp[i] - height[i];
            if (rem_h > 0) water += rem_h;
        }
        return water; 
    }
};
