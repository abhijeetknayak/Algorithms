#include <vector>
using namespace std;

vector<int> twoNumberSumHashTable(vector<int> array, int targetSum) {
	vector<int> result;
	map<int, bool> table;
	
	for(int i = 0; i < array.size(); i++) {
		auto it = table.find(targetSum - array[i]);
		if (it != table.end()) {
			result.push_back(array[i]);
			result.push_back(it->first);
			return result;
		}
		else table.insert({array[i], true});
	}
	return result;
}

vector<int> twoNumberSumWithSort(vector<int> array, int targetSum) {
	int current = 0, left = 0, right = array.size() - 1;
	vector<int> result;
	sort(array.begin(), array.end());
	
	while(left < right) {
		current = array[left] + array[right];
		if (current == targetSum) {
			result.push_back(array[left]);
			result.push_back(array[right]);
			return result;
		}
		else if (current > targetSum) right--;
		else left++;
	}
  return result;
}
