class Solution {
public:
    void reverse(vector<int>& nums, int left, int right) {
        while(left < right) {
            swap(nums[left], nums[right]);
            left++; right--;
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int idx = -1, min_val = INT_MAX, idx_repl = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] >= nums[i + 1]) continue;
            else { idx = i; }
        }
        
        if (idx == -1) {
            /* Monotonically decreasing array */
            // sort(nums.begin(), nums.end());
            reverse(nums, 0, nums.size() - 1);
        }
        else {
            for (int i = idx + 1; i < nums.size(); i++) {
                /* Find next value greater than nums[idx] */
                if (nums[i] > nums[idx] && nums[i] <= min_val) {
                    min_val = nums[i];
                    idx_repl = i;
                }
            }
            swap(nums[idx], nums[idx_repl]);
            // sort(nums.begin() + idx + 1, nums.end());
            reverse(nums, idx + 1, nums.size() - 1);
        }
        
    }
};
