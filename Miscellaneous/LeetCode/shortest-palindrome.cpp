#include <bits/stdc++.h>

using namespace std;


string shortestPalindromeNaive(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    int n = s.length();
    if (n == 0) return "";
    for (int i = 0; i < n; i++) {
        if (s.substr(0, n - i) == rev.substr(i)) {
            return rev.substr(0, i) + s;
        }
    }
    return rev + s;
}

int main() {
	string s1 = "aababbabba";
	cout << shortestPalindromeNaive(s1) << endl;

	return 0;
}
