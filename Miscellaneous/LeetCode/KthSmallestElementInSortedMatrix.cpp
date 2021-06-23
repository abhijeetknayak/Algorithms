class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        int rows = matrix.size(), cols = matrix[0].size(), counter = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                q.push(-matrix[i][j]);
            }
        }
        
        while(!q.empty()) {
            int top = q.top(); q.pop();
            counter += 1;
            
            if (counter == k) return -top;
        }
        
        return -1;
    }
};
