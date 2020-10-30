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

string shortestPalindromeNaive_reverse(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    int n = s.length();
    if (n == 0) return "";
    for (int i = 0; i < n; i++) {
        if (rev.substr(0, n - i) == s.substr(i)) {
            return s.substr(0, i) + rev;
        }
    }
    return s + rev;
}

int main() {
	string s1 = "aababbabbac";
	cout << shortestPalindromeNaive(s1) << endl;

	cout << shortestPalindromeNaive_reverse(s1) << endl;

	return 0;
}
