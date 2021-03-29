void recursion_helper(vector<int>& nums, int start_val, int target,
		set<vector<int>>& result, vector<int>& temp) {
	for (int i = start_val; i < nums.size(); i++) {
		int diff = target - nums[i];
		if (diff == 0) {
			/* Target reached */
			temp.push_back(nums[i]);
			result.insert(temp);
			temp.pop_back();
		}
		else if (diff > 0) {
			/* Continue Recursion */
			temp.push_back(nums[i]);
			recursion_helper(nums, i + 1, diff, result, temp);
			temp.pop_back();
		}
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	set<vector<int>> result;
  vector<vector<int>> res;
  vector<int> temp;
  
  sort(candidates.begin(), candidates.end());

	recursion_helper(candidates, 0, target, result, temp);
  copy(result.begin(), result.end(), back_inserter(res));

	return res;
}
