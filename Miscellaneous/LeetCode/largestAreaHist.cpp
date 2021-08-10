class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> lb(heights.size(), 0), rb(heights.size(), 0);
        lb[0] = -1; rb[heights.size() - 1] = heights.size();
        
        st.push(0);
        for (int i = 1; i < heights.size(); i++) {
            /* Update Left Boundary */
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }            
            if (st.empty()) {
                lb[i] = -1;
            }
            else { lb[i] = st.top(); }            
            st.push(i);
        }
        
        while(!st.empty()) { st.pop(); }
        st.push(heights.size() - 1);
        
        for (int i = heights.size() - 2; i >= 0; i--) {
            /* Update Right Boundary */
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }            
            if (st.empty()) {
                rb[i] = heights.size();
            }
            else { rb[i] = st.top(); }            
            st.push(i);
        }
        
        int max_area = 0;
        /* Calculate Area */
        for (int i = 0; i < lb.size(); i++) {
            max_area = max(max_area, heights[i] * (rb[i] - lb[i] - 1));
        }
        
        return max_area;
    }
};
