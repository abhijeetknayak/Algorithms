    vector<string> result;
    void recursive_helper(string s, int n1, int n2, int n) {

        if (n1 > n || n2 > n || n2 > n1) return;
        if (s.size() == n * 2) {
            result.push_back(s);
            return;
        }

        recursive_helper(s + '(' , n1 + 1, n2,  n);
        recursive_helper(s + ')', n1, n2 + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        string s = "(";
        if (n == 0) return result;
        if (n == 1) {
            result.push_back("()");
            return result;
        }

        recursive_helper(s, 1, 0, n);
        
        return result;
    }
