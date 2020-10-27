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

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int j = 0, k = 0, result = 0, min_val = INT_MAX;
    for (int i = 0; i < nums.size() - 2; i++) {
        j = i + 1;
        k = nums.size() - 1;

        while (j < k) {
            int val = nums[i] + nums[j] + nums[k];
            if (abs(val - target) < min_val) {
                result = val;
                min_val = abs(val - target);
            }

            if (val < target) j++;
            else k--;
        }
    }
    return result;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    set<vector<int>> res;
    if (nums.size() < 4) {
        vector<vector<int>> ret;
        return ret;
    }
    int k = 0, l = 0;
    for (int i = 0; i < nums.size() - 3; i++) {
        for (int j = i + 1; j < nums.size() - 2; j++) {
            k = j + 1;
            l = nums.size() - 1;

            while(k < l) {
                int val = nums[i] + nums[j] + nums[k] + nums[l];
                if (val == target) {
                    vector<int> s{nums[i], nums[j], nums[k++], nums[l--]};
                    res.insert(s);
                }
                else if (val < target) k++;
                else l--;
            }
        }
    }

    vector<vector<int>> r(res.begin(), res.end());
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

	cout << threeSumClosest(nums, 1) << endl;

	res = fourSum(nums, 2);
	for (auto ele : res) {
		for (auto val : ele) {
			cout << val << " ";
		}
		cout << endl;
	}

	cout << "Clean Exit" << endl;
	return 0;

}
