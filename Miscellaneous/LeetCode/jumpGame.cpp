class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int max_index = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i > max_index) return false;
            else if (i + nums[i] > max_index) max_index = i + nums[i];
            
            if (max_index >= nums.size() - 1) return true;
        }
        
        return false;
    }
};
