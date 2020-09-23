#include <bits/stdc++.h>
#include <vector>

using namespace std;

void sieveOfEratosthenes(bool * prime) {
	prime[0] = false;
	prime[1] = false;
	
	for (int p = 2; p < 1000000; p++) {
		prime[p] = true;
	}
	
	for (int p = 2; p * p < 1000000; p++) {
		if (prime[p]) {
			for (int i = 2 * p; i < 1000000; i += p) {
				prime[i] = false;  // Multiples of p. Mark as "not prime"
			}
		}
	}
}

int main() {
	int n, x, k, val = 0;
	bool prime[1000000];
	sieveOfEratosthenes(prime);
	
	vector<int> arr;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr.push_back(x);
	}	
	
	if (n < k) 
		cout << "Not Possible";
	else {
		for (int i = 0; i < k; i++) {
			val += arr[i];
		}
		if (prime[val]) {
			for (int i = 0; i < k; i++) {
				cout << arr[i] << " ";
			}
			return 0;
		}
		int start = 0, end = k;
		while (end < n) {
			/* Traverse till end index reaches 'n' */
			val = val + arr[end] - arr[start];
			if (prime[val]) {
				for (int i = start + 1; i <= end; i++) {
				    cout << arr[i] << " ";
				}
				return 0;
			}
			start++;
			end++;
		}
	}
	return 0;
}