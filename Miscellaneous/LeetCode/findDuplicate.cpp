#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    bool avl[n + 1];
    for (int i = 0; i < n + 1; i++) avl[i] = false;

    for (int i = 0; i <= n; i++) {
        if (avl[nums[i]]) return nums[i];
        else avl[nums[i]] = 1;
    }
    return -1;
}
