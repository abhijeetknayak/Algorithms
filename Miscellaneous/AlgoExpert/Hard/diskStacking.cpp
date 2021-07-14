#include <vector>
using namespace std;

bool checkDimensions(vector<int> a, vector<int> b) {
	if (a[0] > b[0] && a[1] > b[1] && a[2] > b[2]) return true;
	return false;
}

vector<vector<int>> createOutput(vector<vector<int>> disks,
																 vector<int> sequences,
																 int start_idx) {
	vector<vector<int>> result;
	while (start_idx != INT_MIN) {
		result.insert(result.begin(), disks[start_idx]);
		start_idx = sequences[start_idx];
	}
	
	return result;
}

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
	bool proceed = false;
	int max_idx = -1;
	vector<int> h(disks.size(), 0);
	sort(disks.begin(), disks.end(),
			 [](vector<int> &a, vector<int>& b)
			 { return a[2] < b[2]; });
	
	for (int i = 0; i < disks.size(); i++) {
		h[i] = disks[i][2];
	}
	
	vector<int> sequence(disks.size(), INT_MIN);
	
	for (int i = 0; i < disks.size(); i++) {
		for (int j = 0; j < i; j++) {
			proceed = checkDimensions(disks[i], disks[j]);
			if (proceed && disks[i][2] + h[j] > h[i]) {
				h[i] = disks[i][2] + h[j];
				sequence[i] = j;
			}
		}
		if (h[i] > h[max_idx]) max_idx = i;
	}
	
	return createOutput(disks, sequence, max_idx);
}
