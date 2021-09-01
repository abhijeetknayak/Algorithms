class Solution {
public:
    void recursive_helper(string s, vector<string>& res, int index) {
        int n = s.size();
        if (index == n) {
            res.push_back(s);
            return;
        }
        
        int val = s[index] - '0';
        if (val >= 0 && val <= 9) {
            recursive_helper(s, res, index + 1);
        }
        else {
            s[index] = toupper(s[index]);
            recursive_helper(s, res, index + 1);

            s[index] = tolower(s[index]);
            recursive_helper(s, res, index + 1);
        }
        
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        recursive_helper(s, res, 0);
        
        return res;
    }
};
