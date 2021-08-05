class Solution {
public:
        int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        long int max_val = horizontalCuts[0], h_max = -1;
        for (int i = 1; i < horizontalCuts.size(); i++) {
            if (horizontalCuts[i] - horizontalCuts[i - 1] > max_val) {
                max_val = horizontalCuts[i] - horizontalCuts[i - 1];
            }                
        }
        h_max = max_val;

        max_val = verticalCuts[0];
        for (int i = 1; i < verticalCuts.size(); i++) {
            if (verticalCuts[i] - verticalCuts[i - 1] > max_val) {
                max_val = verticalCuts[i] - verticalCuts[i - 1];
            }                
        }
        long res = max_val * h_max;
        res = res % (long)(1e9 + 7);

        return (int)res;
    }                                                             
};
