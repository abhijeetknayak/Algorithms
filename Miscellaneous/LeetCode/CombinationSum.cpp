void recursion_helper(vector<int>& nums, int start_val, int target,
		vector<vector<int>>& result, vector<int>& temp) {
	for (int i = start_val; i < nums.size(); i++) {
		int diff = target - nums[i];
		if (diff == 0) {
			/* Target reached */
			temp.push_back(nums[i]);
			result.push_back(temp);
			temp.pop_back();
		}
		else if (diff > 0) {
			/* Continue Recursion */
			temp.push_back(nums[i]);
			recursion_helper(nums, i, diff, result, temp);
			temp.pop_back();
		}
	}
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> result;
	vector<int> temp;
	
	recursion_helper(candidates, 0, target, result, temp);
	
	return result;
}
