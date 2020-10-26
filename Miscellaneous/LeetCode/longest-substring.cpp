#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
	int n = 256; // Total number of characters
	int length = 0, j = 0;
	vector<int> prevIndex(n, -1);  // Store previous index here
	int str_len = s.size();

	for (int i = 0; i < str_len; i++) {
		j = max(j, prevIndex[s[i]] + 1);  // First occurance
		length = max(length, i - j + 1);  // Final result = max(res, distance from i to j)
		prevIndex[s[i]] = i;
	}
	return length;
}

int main() {
	string s = "HelloWorld!";
	int max_len = lengthOfLongestSubstring(s);

	cout << max_len;

	return 0;
}
