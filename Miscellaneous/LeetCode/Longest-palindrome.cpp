#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    bool table[n][n];
    int max_length = 1, start = 0;

    memset(table, 0, sizeof(table));

    for (int i = 0; i < n; i++) {
    	/* Substring with single character is a palindrome */
    	table[i][i] = 1;
    }

    for (int i = 0; i < n - 1; i++) {
    	if (s[i] == s[i + 1]) {
    		start = i;
    		max_length = 2;
    		table[i][i + 1] = 1;
    	}
    }

    for (int k = 3; k <= n; k++) {
    	for (int i = 0; i < n - k + 1; i++) {
    		/* String of length k, starting from iTh index, ends at i + k - 1 */
    		int j = i + k - 1;

    		/* Check if sub string str[i + 1 ----- j - 1] is a palindrome. Check if ends are the same */
    		if (table[i + 1][j - 1] && s[i] == s[j]) {
    			table[i][j] = 1;

    			if (k > max_length) {
        			start = i;
        			max_length = k;
    			}
    		}
    	}
    }

    return s.substr(start, max_length);
}

int main() {

	string s = "geegksskeegg";
	longestPalindrome(s);


	return 0;
}
