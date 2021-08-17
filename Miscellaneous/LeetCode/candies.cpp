class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res(candies.size(), false);
        int max_val = INT_MIN;
        for (int i = 0; i < candies.size(); i++) {
            max_val = max(max_val, candies[i]);
        }
        
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= max_val) {
                res[i] = true;
            }
        }
        
        return res;
    }
};
