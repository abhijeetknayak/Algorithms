#include <bits/stdc++.h>

using namespace std;

int max_sum(int array[], int N, int K) {
	int p[N], dp[N];
	p[0] = array[0];
	
	memset(dp, 0, sizeof(dp));	
	
	for (int i = 1; i < N; i++) {
		p[i] = p[i - 1] + array[i];		
	}
	
	dp[0] = p[0];
	
	for (int i = 1; i < K - 1; i++) {
		/* For all i less than K-1 */
		dp[i] = p[i];		
	}
	
	for (int i = K - 1; i < N; i++) {
		for (int j = i; j >= (i - K + 1); j--) {
			dp[i] = max(dp[i], dp[j - 1] + p[i] - p[j]);
		}		
	}
	return dp[N - 1];  // Max sum when all elements are used	
}

int main() {
	int N, K, max_val;
	cin >> N >> K;
	
	int data[N];
	
	for (int i = 0; i < N; i++) {
		cin >> data[i];  // Store all elements from user input		
	}
	
	cout << max_sum(data, N, K);
}