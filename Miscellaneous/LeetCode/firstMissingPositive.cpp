#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    long int num = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == num) num++;
        else if (nums[i] <= 0 || nums[i] < num) continue;
        else {
        	break;
        }
    }
    return num;
}
