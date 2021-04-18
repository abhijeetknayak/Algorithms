#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
	sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());
	
	int first = 0, second = 0, min_diff = INT_MAX, diff = 0;
	vector<vector<int>> result;
	while(first < arrayOne.size() && second < arrayTwo.size()) {
		diff = arrayOne[first] - arrayTwo[second];
		if (abs(diff) < min_diff) {
			min_diff = abs(diff);
			vector<int> temp{arrayOne[first], arrayTwo[second]};
			result.push_back(temp);
		}
		
		if (diff < 0) first++;
		else second++;
	}
		

  return result[result.size() - 1];
}
