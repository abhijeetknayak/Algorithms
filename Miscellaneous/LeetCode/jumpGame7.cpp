class Solution {
public:    
    bool canReach(string s, int minJump, int maxJump) {
        long n = s.size();
        if (s[n - 1] == '1') return false;
        
        queue<long> dp;
        long max_index_added = 0;
        dp.push(0);
        
        while(!dp.empty()) {
            long top = dp.front(); dp.pop();
            if (top >= n) continue;
            
            long min_idx = max(top + minJump, max_index_added + 1);
            long max_idx = min(top + maxJump, n - 1);
            
            for (long j = min_idx; j <= max_idx; j++) {
                if (s[j] == '0') {
                    if (j == n - 1) return true;
                    dp.push(j);
                }
            }
            max_index_added = max_idx;
        }
        
        return false;
    }
};
