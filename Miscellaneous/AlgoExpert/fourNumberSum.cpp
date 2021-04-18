#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum1(vector<int> array, int targetSum) {
	vector<vector<int>> result;
	int left = 0, right = 0;
	sort(array.begin(), array.end());
	for(int i = 0; i < array.size() - 3; i++) {
		for (int j = i + 1; j < array.size() - 2; j++) {
			left = j + 1;
			right = array.size() - 1;
			while(left < right) {
				int cur_sum = array[i] + array[j] + array[left] + array[right];
				if (cur_sum == targetSum) {
					vector<int> temp{array[i], array[j], array[left], array[right]};
					result.push_back(temp);
					left++; right--;
				}
				else if(cur_sum < targetSum) left++;
				else right--;
			}
		}
	}
  return result;
}

#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum2(vector<int> array, int targetSum) {
	map<int, vector<vector<int>>> table;
	vector<vector<int>> result;
	
	for (int i = 1; i < array.size(); i++) {
		for(int j = i + 1; j < array.size(); j++) {
			int cur_sum = array[i] + array[j];
			int diff = targetSum - cur_sum;
			if(table.find(diff) != table.end()) {
				for(auto pair : table[diff]) {
					pair.push_back(array[i]);
					pair.push_back(array[j]);
					result.push_back(pair);
				}
			}			
		}
		
		for (int k = 0; k < i; k++) {
			/* Now add stuff to the table */
			int temp_sum = array[k] + array[i];
			if (table.find(temp_sum) != table.end()) {
				/* Add to already existing vector */
				table[temp_sum].push_back(vector<int>{array[k], array[i]});
			}
			else {
				table[temp_sum] = vector<vector<int>>{{array[i], array[k]}};
			}
		}
	}
  return result;
}

