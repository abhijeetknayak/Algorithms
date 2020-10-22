#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> values;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int val = target - nums[i];
            map<int, int>::iterator found = values.find(val);
                
            if (found == values.end()) {
                /* Add this element to the map */
                pair<int, int> p(nums[i], i);
                values.insert(p);
            }
            else {
                result.push_back(i);
                result.push_back(found->second);
            }
        }
        return result;
    }
};