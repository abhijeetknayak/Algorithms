#include <vector>
#include <iostream>
using namespace std;

bool check_condition(int index, vector<int> array) {
	if (index == 0) {
		return array[index] <= array[index + 1];		
	}
	else if (index == array.size() - 1) {
		return array[index] >= array[index - 1];
	}
	else {
		return (array[index - 1] <= array[index] && array[index] <= array[index + 1]);
	}
}

vector<int> subarraySort(vector<int> array) {
	int minUnsorted = INT_MAX, maxUnSorted = INT_MIN; 
	
	for (int i = 0; i < array.size(); i++) {
		bool fine = check_condition(i, array);
		if (!fine) {
			minUnsorted = min(minUnsorted, array[i]);
			maxUnSorted = max(maxUnSorted, array[i]);
		}
	}
	
	if (minUnsorted == INT_MAX) return vector<int> {-1, -1};
	
	int index = 0;
	while(minUnsorted >= array[index]) {
		index++;
	}
	vector<int> result {index};
	index = array.size() - 1;
	
	while(maxUnSorted <= array[index]) {
		index--;
	}
	result.push_back(index);
  return result;
}
