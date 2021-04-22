#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
	int left = 0, right = 0, cur_sum = 0;
	vector<vector<int>> result;
	sort(array.begin(), array.end());
	
	for(int i = 0; i < array.size() - 2; i++) {
		left = i + 1; right = array.size() - 1;
		while (left < right) {
			cur_sum = array[i] + array[left] + array[right];
			if (cur_sum == targetSum) {
				vector<int> temp{array[i], array[left], array[right]};
				result.push_back(temp);
				left++; right--;
			}
			else if (cur_sum < targetSum) left++;
			else right--;
		}
	}
  return result;
}
