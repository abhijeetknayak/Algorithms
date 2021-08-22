class Solution {
public:
    int recursive_helper(vector<int>& arr, int (&dp)[1001], int index, int d) {
        if (dp[index] != -1) return dp[index];
        
        int n = arr.size();
        int result = 1;
        for (int i = index + 1; i <= min(index + d, n - 1) && arr[index] > arr[i]; i++) {
            /* Locations for search on the right side */
            result = max(result, 1 + recursive_helper(arr, dp, i, d));
        }
        
        for (int i = index - 1; i >= max(index - d, 0) && arr[index] > arr[i]; i--) {
            /* Locations on the left */
            result = max(result, 1 + recursive_helper(arr, dp, i, d));
        }
        
        return dp[index] = result;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int dp[1001];
        memset(dp, -1, sizeof(dp));
        
        int result = 1;
        for (int i = 0; i < arr.size(); i++) {
            result = max(result, recursive_helper(arr, dp, i, d));
        }
        return result;
    }
};
