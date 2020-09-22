#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n = 0, x, y, max_val = 0;  // Number of coordinates	
	vector<pair<int, int>> coordinates;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		coordinates.push_back(make_pair(x, y));		
	}
	
	vector<int> sum_vec, diff_vec;
	for (auto ele : coordinates) {
		/* Store the sum and difference values */
		sum_vec.push_back(ele.first + ele.second);
		diff_vec.push_back(ele.first - ele.second);		
	}
	
	/* Sort the sum and difference vectors */
	sort(sum_vec.begin(), sum_vec.end());
	sort(diff_vec.begin(), diff_vec.end());
	
	/*The value we need is max(sum_vec[N - 1] - sum[0], diff_vec[N - 1] - diff_vec[0]) as the vectors are sorted */
	max_val = max(sum_vec.at(n - 1) - sum_vec.at(0), diff_vec.at(n - 1) - diff_vec.at(0));
	
	cout << max_val;
	
	return 0;
}