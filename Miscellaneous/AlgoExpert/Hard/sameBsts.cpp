#include <vector>

using namespace std;

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
	/* Base cases */
	if (arrayOne.size() != arrayTwo.size()) return false;
	if (arrayOne.size() == 0) return true;
	if (arrayOne[0] != arrayTwo[0]) return false;
	
	vector<int> arrayOneLeft;
	vector<int> arrayTwoLeft;
	vector<int> arrayOneRight;
	vector<int> arrayTwoRight;
	int root_val = arrayOne[0];
	
	/* Create Subarrays */
	for (int i = 1; i < arrayOne.size(); i++) {
		if (arrayOne[i] < root_val) arrayOneLeft.push_back(arrayOne[i]);
		else arrayOneRight.push_back(arrayOne[i]);
		
		if (arrayTwo[i] < root_val) arrayTwoLeft.push_back(arrayTwo[i]);
		else arrayTwoRight.push_back(arrayTwo[i]);
	}
	
	return sameBsts(arrayOneLeft, arrayTwoLeft) && sameBsts(arrayOneRight, arrayTwoRight);
}

int getFirstGtOrEqIdx(vector<int> array, int idx, int max_val) {
	for (int i = idx + 1; i < array.size(); i++) {
		if (array[i] >= array[idx] && array[i] < max_val)	return i;
	}
	return -1;
}

int getFirstSmallerIdx(vector<int> array, int idx, int min_val) {
	for (int i = idx + 1; i < array.size(); i++) {
		if (array[i] < array[idx] && array[i] >= min_val) return i;
	}
	return -1;
}

bool recursive_helper(vector<int> arrayOne, vector<int> arrayTwo, int idx1, int idx2, int min_val, int max_val) {
	if (idx1 == -1 || idx2 == -1) return idx1 == idx2;
	if (arrayOne[idx1] != arrayTwo[idx2]) return false;
	
	int smallIdx1 = getFirstSmallerIdx(arrayOne, idx1, min_val);
	int smallIdx2 = getFirstSmallerIdx(arrayTwo, idx2, min_val);
	
	int gtOrEqIdx1 = getFirstGtOrEqIdx(arrayOne, idx1, max_val);
	int gtOrEqIdx2 = getFirstGtOrEqIdx(arrayTwo, idx2, max_val);
	
	bool left = recursive_helper(arrayOne, arrayTwo, smallIdx1, smallIdx2, min_val, arrayOne[idx1]);
	bool right = recursive_helper(arrayOne, arrayTwo, gtOrEqIdx1, gtOrEqIdx2, arrayOne[idx1], max_val);
	
	return left && right;
}

bool sameBstsBetterSpaceComplexity(vector<int> arrayOne, vector<int> arrayTwo) {	
  return recursive_helper(arrayOne, arrayTwo, 0, 0, INT_MIN, INT_MAX);
}
