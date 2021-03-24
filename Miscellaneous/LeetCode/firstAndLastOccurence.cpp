void searchHelper(vector<int>& nums, int start, int end, int target, int& low, int& high) {
	int loc = start + (end - start) / 2;

	if (nums[loc] == target) {
		if (loc < low) low = loc;
		if (loc > high) high = loc;
	}
	if (loc + 1 == end) {
		if (nums[loc + 1] == target) {
			if (loc + 1 < low) low = loc + 1;
			if (loc + 1 > high) high = loc + 1;
		}
	}
	if (loc == start) return;

	searchHelper(nums, start, loc, target, low, high);
	searchHelper(nums, loc, end, target, low, high);
}

vector<int> searchRange(vector<int>& nums, int target) {
	int high = -1, low = -1;
	if (nums.size() == 0) return vector<int> {-1, -1};
	else if (nums.size() == 1) {
		if (nums[0] == target) return vector<int> {0, 0};
		else return vector<int> {-1, -1};
	}
	else if (nums.size() == 2) {
		if (nums[0] == target) {
			low = 0; high = 0;
		}
		if (nums[1] == target) {
			high = 1;
			if (low == -1) low = high;
		}
		return vector<int> {low, high};
	}

	int len = nums.size();
	high = -1;
	low = len;
    searchHelper(nums, 0, len - 1, target, low, high);

    if (low == len && high == -1) return vector<int> {-1, -1};
    else return vector<int> {low, high};
}
