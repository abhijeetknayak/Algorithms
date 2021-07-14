#include <vector>
using namespace std;

void recursive_helper(vector<int>& array, int start_idx, int end_idx) {
	if (start_idx >= end_idx) return;
	
	int left = start_idx + 1, right = end_idx;
	int pivot = start_idx;
	
	while(left <= right) {
		if (array[left] <= array[pivot]) { left++; }
		if (array[right] > array[pivot]) { right--; }
		if (left > right) break;
		if (array[left] > array[pivot] && array[right] <= array[pivot]) { 
			swap(array[left], array[right]);
			left++; right--;
		}		


	}
	swap(array[pivot], array[right]);
	
	recursive_helper(array, start_idx, right - 1);
	recursive_helper(array, right + 1, end_idx);
}

vector<int> quickSort(vector<int> array) {
	recursive_helper(array, 0, array.size() - 1);
  return array;
}
