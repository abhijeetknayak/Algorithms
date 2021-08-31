class Solution {
public:
    void recursive_helper(vector<int>& nums, vector<vector<int>>& result,
                          vector<int>& temp, int index) {
        if (index >= nums.size()) return;
        temp.push_back(nums[index]);
        for (int i = index + 1; i < nums.size(); i++) {
            recursive_helper(nums, result, temp, i);
        }
        result.push_back(temp);
        temp.pop_back();        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> result {vector<int> {}};
        
        for (int i = 0; i < nums.size(); i++) {
            recursive_helper(nums, result, temp, i);
        }
        
        return result;        
    }
};
