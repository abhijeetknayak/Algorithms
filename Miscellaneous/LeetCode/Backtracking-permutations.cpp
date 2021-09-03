class Solution {
public:
    void recursive_helper(vector<int>& nums, vector<bool>& used,
                          vector<vector<int>>& result, vector<int>& temp) {
        if (temp.size() == nums.size()) result.push_back(temp);
        
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                temp.push_back(nums[i]);
                used[i] = true;
                recursive_helper(nums, used, result, temp);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        vector<int> temp;
        
        recursive_helper(nums, used, result, temp);
        
        return result;
    }
};
