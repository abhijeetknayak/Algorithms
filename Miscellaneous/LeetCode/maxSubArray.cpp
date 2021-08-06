int maxSubArray(vector<int>& nums) {
    /* Max Sub Array sum */
    int max_sum, cur_sum;
    max_sum = cur_sum = nums[0];

    for(int i = 1; i < nums.size(); i++) {
    	cur_sum = max(nums[i], cur_sum + nums[i]);
    	max_sum = max(max_sum, cur_sum);
    }

    return max_sum;
}

int maxSubArray1(vector<int>& nums) {
  /* Max Sub Array including the indices */
	int first = 0, second = 0;
	int cur_sum = nums[0], max_sum = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		int temp = cur_sum + nums[i];

		if (nums[i] > temp) {
			second = i;
			first = i;
			cur_sum = nums[i];
		}
		else if (temp > max_sum){
			second = i;
			max_sum = cur_sum = temp;
		}
		else { cur_sum = temp; }
    
    if (cur_sum > max_sum) max_sum = cur_sum;
	}
	cout << first << " " << second << " " << max_sum;
	return max_sum;
}

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = INT_MIN, max_end_here = 0;
        int left = -1, right = -1;
        for (int i = 0; i < nums.size(); i++) {
            max_end_here += nums[i];
            if (max_end_here < nums[i]) {
                max_end_here = nums[i];
                left = i;
                right = i;
            }
            
            if (max_so_far < max_end_here) {
                max_so_far = max_end_here;
                right = i;
            }
        }
        cout << left << " " << right << endl;
        return max_so_far;
    }
};
