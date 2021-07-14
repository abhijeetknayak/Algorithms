using namespace std;

int getNthFib(int n) {
	vector<int> dp{0, 1};
	if (n == 1) return dp[0];
	if (n == 2) return dp[1];
		
	for (int i = 2; i < n; i++) {
		int temp = dp[1];
		dp[1] = dp[0] + dp[1];
		dp[0] = temp;
	} 
	
  return dp[1];
}

int getNthFibONspace(int n) {
	int dp[n];
	dp[0] = 0; dp[1] = 1;
	
	for (int i = 2; i < n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	} 
	
  return dp[n - 1];
}
