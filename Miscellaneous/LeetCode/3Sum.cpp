#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
	set<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) {
        	/* Iterate j and k until they reach each other */
        	int sum = nums[i] + nums[j] + nums[k];
        	if (sum == 0) {
        		vector<int> s;
        		s.push_back(nums[i]);
        		s.push_back(nums[j++]);
        		s.push_back(nums[k--]);
        		result.insert(s);
        	}
        	else if (sum < 0) j++;
        	else if (sum > 0) k--;
        }
    }

    vector<vector<int>> r(result.begin(), result.end());

    return r;
}

int main() {
	vector<int> nums;

	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-4);

	vector<vector<int>> res(threeSum(nums));

	for (auto ele : res) {
		for (auto val : ele) {
			cout << val << " ";
		}
		cout << endl;
	}

}
