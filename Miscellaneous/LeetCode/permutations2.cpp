class Solution {
public:
    void recursive_helper(vector<int>& current,
                          map<int, int>& dict, int n,
                          vector<vector<int>>& result) {
        if (current.size() == n) {
            result.push_back(current); return;
        }
        
        for (auto key : dict) {
            if (key.second == 0) continue;
            
            current.push_back(key.first);
            dict[key.first] -= 1;
            
            recursive_helper(current, dict, n, result);
            
            current.pop_back();
            dict[key.first] += 1;
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> dict;
        vector<int> current;
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++) {
            if (dict.find(nums[i]) == dict.end()) {
                dict[nums[i]] = 1;
            }
            else dict[nums[i]] += 1;
        }
        
        recursive_helper(current, dict, nums.size(), result);
        return result;
    }
};
