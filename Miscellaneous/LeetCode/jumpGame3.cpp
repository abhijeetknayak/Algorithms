class Solution {
public:
    void recursive_helper(vector<int>& arr, vector<bool>& dp, int start) {
        dp[start] = true;
        int idx1 = start + arr[start];
        int idx2 = start - arr[start];
        if (idx1 < arr.size() && !dp[idx1]) {
            recursive_helper(arr, dp, idx1);
        }
        if (idx2 >= 0 && !dp[idx2]) {
            recursive_helper(arr, dp, idx2);
        }
    }
    
    bool canReachRecursiveSoln(vector<int>& arr, int start) {
        vector<bool> dp(arr.size(), false);
        recursive_helper(arr, dp, start);
        
        for (int i = 0; i < arr.size(); i++) {
            if (dp[i] && arr[i] == 0) return true;
        }
        
        return false;
    }
};
