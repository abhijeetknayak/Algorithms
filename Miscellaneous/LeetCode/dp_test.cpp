#include <bits/stdc++.h>

using namespace std;

int memoization(int * memo, int n) {
	if (n == 1) return 0;
	if (memo[n] != -1)
		return memo[n];

	int r = 1 + memoization(memo, n - 1);  // Worst case
	if(n % 2 == 0)
		r = min(r, 1 + memoization(memo, n / 2));
	if (n % 3 == 0)
		r = min(r, 1 + memoization(memo, n / 3));
	memo[n] = r;  // Save state
	return r;
}

int dp(int n) {
	int dp_array[n + 1];

	// Base case
	dp_array[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp_array[i] = 1 + dp_array[i - 1]; // Worst case
		if (i % 2 == 0)
			dp_array[i] = min(dp_array[i], 1 + dp_array[i / 2]);
		if (i % 3 == 0)
			dp_array[i] = min(dp_array[i], 1 + dp_array[i / 3]);
	}

	return dp_array[n];
}

void fibonacci(int n, int * fib) {
	int dp_array[n + 1];
	if (fib != NULL) {
		fib[1] = 1;  // Base case
		fib[2] = 1;
		for (int i = 3; i <= n; i++) {
			fib[i] = fib[i - 1] + fib[i - 2];
		}
	}
}

int main() {
	int n = 1000;
	int memo[n + 1];
	for (int i = 0; i <= n; i++) {
		memo[i] = -1;
	}
	cout << memoization(memo, n) << endl;
	cout << dp(n) << endl;

	int fib[n + 1];

	fibonacci(n, fib);
	cout << fib[8];

	return 0;
}
