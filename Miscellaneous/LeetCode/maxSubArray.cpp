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
