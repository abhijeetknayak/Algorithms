using namespace std;

int levenshteinDistance(string str1, string str2) {
	vector<vector<int>> dp(str1.size() + 1, vector<int> (str2.size() + 1, 0));
	for (int i = 1; i < dp.size(); i++) {
		dp[i][0] = i;	
	}
	for (int j = 1; j < dp[0].size(); j++) {
		dp[0][j] = j;
	}
	for (int i = 1; i < dp.size(); i++) {
		for (int j = 1; j < dp[0].size(); j++) {
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else {
				int min_val = min(dp[i - 1][j - 1], dp[i - 1][j]);
				min_val = min(min_val, dp[i][j - 1]);
				dp[i][j] = min_val + 1;
			}
		}
	}
  return dp[dp.size() - 1][dp[0].size() - 1];
}
