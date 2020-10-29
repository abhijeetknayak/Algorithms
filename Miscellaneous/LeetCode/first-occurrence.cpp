#include <bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle) {
    int i = 0, j = 0;
    int n1 = haystack.length(), n2 = needle.length();
    if (n1 == 0 && n2 == 0) return 0;  // Base cases
    if (n1 == 0 || n2 > n1) return -1;
    if (n2 == 0) return 0;

    while (i < n1 && j < n2) {
        /* Pointers should be within ranges */
        if (haystack[i] == needle[j]) {
            if (j == n2 - 1) break;  /* Reached end */
            i++; j++;
        }
        else { i = i - j + 1; j = 0; }
    }

    /* If found, i is at the end index of the "needle" */
    if (j == n2 - 1 && haystack[i] == needle[j])
        return i - j;
    return -1;
}

int main() {
	string s1 = "mississippi";
    string s2 = "issip";

    cout << strStr(s1, s2);

	return 0;
}
