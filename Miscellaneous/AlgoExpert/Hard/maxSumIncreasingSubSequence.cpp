#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
	vector<int> sumArray = array;
	vector<int> list(array.size(), INT_MIN);
	int maxVal = INT_MIN, maxIdx = -1;
	
	
		for (int i = 0; i < array.size(); i++) {
		int currentNum = array[i];
		for (int j = 0; j < i; j++) {
			int num = array[j];
			if (num < currentNum && sumArray[j] + currentNum >= sumArray[i]) {
				sumArray[i] = currentNum + sumArray[j];
				list[i] = j;
			}			
		}
		if (sumArray[i] > maxVal) { maxVal = sumArray[i]; maxIdx = i; }
	}
	
	vector<int> result;
	while (maxIdx != INT_MIN) {
		result.insert(result.begin(), array[maxIdx]);
		maxIdx = list[maxIdx];
	}

  return {
      {maxVal}, // Sum of sequence.
      result,  // Elements of the sequence.
  };
}
