#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int i = 0, n = nums.size();
    while (i < n) {
        if (nums[i] == target)
            return i;
        else if (nums[i] > target) {
            break;
        }
        else {
            i++;
        }
    }
    return i;
}

int main() {
	vector<int> nums;
	cout << searchInsert(nums, 3) << endl;
	cout << searchInsert(nums, 0) << endl;
	cout << searchInsert(nums, 7) << endl;
	cout << searchInsert(nums, 10) << endl;

}
