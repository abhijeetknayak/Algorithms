#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    /* Array is sorted! Duplicates should come together */
    int n = nums.size();
    if (n == 0) return 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (nums[j] != nums[i]) {
            j++;
            nums[j] = nums[i];
        }
    }
    return j + 1;
}

int removeElement(vector<int>& nums, int val) {
    int j = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] != val) {
            nums[j++] = nums[i];
        }
    }
    return j;
}

int main() {
	vector<int> nums{1, 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6, 7};
	cout << removeDuplicates(nums) << endl;

	vector<int> nums1{1, 1, 1, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6, 7};
	cout << removeElement(nums1, 5) << endl;


	return 0;
}
