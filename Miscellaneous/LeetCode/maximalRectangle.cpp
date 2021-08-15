class Solution {
public:
    int maxAreaHist(vector<int> heights) {
        int max_area = INT_MIN;
        stack<int> st;
        int n = heights.size();
        vector<int> lb(n, 0), rb(n, 0);
        st.push(0);
        lb[0] = -1;
        for (int i = 1; i < n; i++) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            
            if (st.empty()) lb[i] = -1;
            else { lb[i] = st.top(); }
            
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        st.push(n - 1);
        rb[n - 1] = n;
        
        for (int i = n - 2; i >= 0; i--) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            
            if (st.empty()) rb[i] = n;
            else { rb[i] = st.top(); }
            
            st.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            max_area = max(max_area, heights[i] * (rb[i] - lb[i] - 1));
        }
        
        return max_area;        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<int> heights(matrix[0].size(), 0);
        int max_area = INT_MIN;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                }
                else {
                    heights[j] += 1;
                }
            }
            max_area = max(max_area, maxAreaHist(heights));
        }
        
        return max_area;
    }
};
