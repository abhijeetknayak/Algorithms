#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    double median = 0.0;
    int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();

    /* Base case */
    if (n1 == 0)
        result = nums2;
    else if (n2 == 0)
        result = nums1;
    else {
        while (i < n1 || j < n2) {
            if (i == n1) {
                result.push_back(nums2[j]);
                j++;
            }
            else if (j == n2) {
                result.push_back(nums1[i]);
                i++;
            }
            else if (nums2[j] < nums1[i]) {
                result.push_back(nums2[j]);
                j++;
            }
            else {
                result.push_back(nums1[i]);
                i++;
            }
        }
    }

    for (auto ele : result)
        cout << ele << " ";

    /* Result has all numbers sorted */
    int mid = (n1 + n2) / 2;
    if ((n1 + n2) % 2 == 0) {
        /* Even number of numbers */
        median = (result[mid] + result[mid - 1]) / 2.0;
    }
    else
        median = result[mid];
    return median;
}


int main() {
	vector<int> nums1, nums2;

	nums1.push_back(1);
	nums1.push_back(3);

	nums2.push_back(2);

	cout << findMedianSortedArrays(nums1, nums2);

	return 0;
}
