#include <vector>
using namespace std;

vector<int> largestRangeOptimized(vector<int> array) {
	map<int, bool> table;	
	for(int i = 0; i < array.size(); i++) {
		table[array[i]] = true;
	}	
	
	int max_len = INT_MIN;
	vector<int> best_range; 
	for (int i = 0; i < array.size(); i++) {
		int num = array[i];
		int left = num - 1, right = num + 1;
		int cur_len = 1;
		
		table[num] = false;
		while(table.find(left) != table.end()) {
			cur_len++;
			table[left] = false;
			left--;
		}
		
		while(table.find(right) != table.end()) {
			cur_len++;
			table[right] = false;
			right++;
		}
		
		if (cur_len > max_len) {
			max_len = cur_len;
			best_range = {left + 1, right - 1};
		}		
	}	
  return best_range;
}

vector<int> largestRangeSortOfOptimized(vector<int> array) {
	map<int, bool> table;
	int min_val = INT_MAX, max_val = INT_MIN,
	max_len = INT_MIN, len = 0, temp_end, end = -1, start = -1;
	
	for(int i = 0; i < array.size(); i++) {
		table[array[i]] = true;
		if (array[i] < min_val) min_val = array[i];
		if (array[i] > max_val) max_val = array[i];
	}
	
	for (int i = min_val; i <= max_val; i++) {
		if (table.find(i) != table.end()) {
			len++;
			temp_end = i;
		}
		else {
			if (len > max_len) {
				max_len = len; len = 0;
				end = temp_end;
				start = end - max_len + 1;
			}
		}
	}
	
	if (len > max_len) {
		max_len = len;
		end = temp_end;
		start = end - len + 1;
	}
	
	return vector<int> {start, end};	
}
