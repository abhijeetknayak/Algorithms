class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int, vector<int>>> q;
        for (int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                q.push(make_pair(-(nums1[i] + nums2[j]), vector<int> {nums1[i], nums2[j]}));
            }            
        }
        
        int counter = 0;
        
        while(!q.empty()) {
            counter += 1;
            pair<int, vector<int>> top = q.top(); q.pop();
            result.push_back(top.second);
            
            if (counter == k) break;
        }
        return result;
    }
};
