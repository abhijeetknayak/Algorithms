class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = 0, high = 0, result = 0;
        for (int i = 0; i < nums.size(); i++) {
            high += nums[i];
            low = max(low, nums[i]);
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cur_sum = 0, subarray_size = 1;
            
            for (int i = 0; i < nums.size(); i++) {
                if (subarray_size > m) {
                    /* Not Possible. Do Something */
                    low = mid + 1; break;
                }
                else if (cur_sum + nums[i] <= mid) {
                    cur_sum += nums[i];
                    if (i == nums.size() - 1) {
                        high = mid - 1;
                        result = mid;
                    }
                }
                else if (nums[i] > mid) {
                    low = mid + 1;
                }
                else {
                    /* Start a new sub array */
                    if (subarray_size + 1 > m) {
                        low = mid + 1; break;
                    }
                    
                    subarray_size += 1;
                    cur_sum = nums[i];
                    if (i == nums.size() - 1) {
                        high = mid - 1;
                        result = mid;
                    }
                }
            }
        }
        return result;
    }
};
