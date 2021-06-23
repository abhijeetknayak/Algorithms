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


class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1], mid = 0;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if (count < k) left = mid + 1;
            else right = mid - 1;            
        }
        
        return left;
    }
};
