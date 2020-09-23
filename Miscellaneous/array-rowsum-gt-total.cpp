#include <bits/stdc++.h>

using namespace std;

int main() {
	int R, C, x = 0, count = 0, rowSum = 0, totSum = 0;
	cin >> R >> C;
	vector<int> sums;
	
	for (int i = 0; i < R; i++) {
		rowSum = 0;
		for (int j = 0; j < C; j++) {
			cin >> x;
			rowSum += x;
		}
		totSum += rowSum;
		sums.push_back(rowSum);
	}
	
	for (auto element : sums) {
		if (element > totSum - element)
		count++;		
	}
	
	cout << count;
	
	return 0;	
}