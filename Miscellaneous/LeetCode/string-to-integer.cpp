#include <bits/stdc++.h>

using namespace std;


int stoi(string s) {
	int i = 0, result = 0, sign = 1;

	while(i < s.length() && s[i] == ' ')
		i++;

	if (i < s.length() && (s[i] == '-' || s[i] == '+'))
		sign = (s[i++] == '-') ? -1 : 1;

	while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
		if (result > INT_MAX / 10 || result * 10 > INT_MAX - ((s[i] - '0')))
			return (sign == 1) ? INT_MAX : INT_MIN;
		result = result * 10 + (s[i++] - '0');
	}

	return result;
}

int reverse(int x) {
    int result = 0, temp = 0;
    while (x != 0) {
        temp = x % 10;
        x /= 10;
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && temp > 7)) return 0;
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && temp < -8)) return 0;

        result = result * 10 + temp;
    }
    return result;
}

bool isPalindrome(int x) {
    if (x >= 0) {
        int x_rev = reverse(x);
        if (x_rev == x) return 1;
    }
    return 0;

}

int main() {
	string s = "432";

	int i = 432;
	cout << reverse(i) << endl;

	cout << isPalindrome(i) << endl;

	return 0;
}
