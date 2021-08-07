class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int result = nums[0];
        int max_prod = 1, min_prod = 1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                max_prod = 1; min_prod = 1;
                if (nums[i] > result) result = nums[i];
            }
            else {
                int temp = max(max_prod * nums[i],
                              min_prod * nums[i]);
                temp = max(temp, nums[i]);
                
                min_prod = min(max_prod * nums[i],
                              min_prod * nums[i]);
                min_prod = min(min_prod, nums[i]);
                max_prod = temp;
                if (max_prod > result) {
                    result = max_prod;
                }
            }
        }
        return result;
    }
};
