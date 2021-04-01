#include <bits/stdc++.h>
using namespace std;

int maxProfitWithKTransactionsNoDP(vector<int> prices, int k) {
	int n = prices.size();
	int dp[k + 1][n], m_b = 0, m_b1 = 0;

	for(int i = 0; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= k; i++) {
		for(int j = 1; j < n; j++) {
			m_b1 = 0;
			m_b = dp[i][j - 1];
			for(int l = 0; l < j; l++) {
				m_b1 = max(m_b1, prices[j] + dp[i - 1][l] - prices[l]);
			}
			dp[i][j] = max(m_b, m_b1);
		}
	}

	for(int i = 0; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[k][n - 1];
}

int maxProfitWithKTransactionsDP(vector<int> prices, int k) {
    int n = prices.size();
    int dp[k + 1][n], m_b = 0, m_b1 = 0;

    for(int i = 0; i <= k; i++) {
	for (int j = 0; j < n; j++) {
	    dp[i][j] = 0;
	}
    }
	
    for (int i = 1; i <= k; i++) {
	m_b = -INT_MAX;
	for(int j = 1; j < n; j++) {
	    m_b1 = max(m_b1, dp[i - 1][j - 1] - prices[j - 1]);
	    dp[i][j] = max(dp[i][j - 1], m_b1 + prices[j]);
	}
    }
    
    return dp[k][n - 1];
}

int main() {
	vector<int> prices {5, 11, 3, 50, 60, 90};
	cout << maxProfitWithKTransactionsNoDP(prices, 2);
	cout << maxProfitWithKTransactionsDP(prices, 2);
}
