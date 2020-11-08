#include <bits/stdc++.h>

using namespace std;

int longestValidParentheses1(string s) {
	int max_len = 0, cur_len = 0;
    stack<char> st;

    int n = s.length();
    if (n == 0) return 0;

    for (int i = 0; i < n; i++) {
    	/* Add char to stack. If its a closing one, check if the top has the opening one */
    	if (s[i] == '(') {
    		cur_len = 0;
    		st.push(s[i]);
    	}
    	else {
    		if (st.empty()) {
    			cur_len = 0;
    		}
    		else {
    			char ch = st.top();
    			if (ch == '(') {
    				cur_len += 2;
    				st.pop();
    			}
    		}
    	}

    	if (cur_len > max_len)
    		max_len = cur_len;
    }

    return max_len;
}

int longestValidParentheses(string s) {
	int max_len = 0;
    stack<int> st;

    int n = s.length();
    if (n == 0) return 0;

    for (int i = 0; i < n; i++) {
    	/* Add index to stack. If its a closing one, pop the last added element and calculate length */
    	if (s[i] == '(') {
    		st.push(i);
    	}
    	else {
    		if (!st.empty()) {
    			int top = st.top();
    			st.pop();
    			max_len = max(max_len, i - top + 1);
    		}
    	}
    }

    return max_len;
}

int main() {
	string s = "()(()";
	cout << longestValidParentheses(s) << endl;

	return 0;


}
