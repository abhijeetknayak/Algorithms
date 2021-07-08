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
