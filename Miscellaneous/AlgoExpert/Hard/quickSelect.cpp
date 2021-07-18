#include <vector>
using namespace std;

void recursive_helper(vector<int>& array, int start_idx, int end_idx, int k) {
	if (start_idx >= end_idx) return;
	int left = start_idx + 1, right = end_idx, pivot_idx = start_idx;
	while(left <= right) {
		if (array[left] > array[pivot_idx] && array[right] <= array[pivot_idx]) {
			swap(array[left], array[right]);
			left++; right--;
		}
		if (array[left] <= array[pivot_idx]) left++;
		if (array[right] > array[pivot_idx]) right--;
	}
	swap(array[right], array[pivot_idx]);
	
	if (right == k - 1) return;
	// start_idx -> right - 1; right + 1 -> end_idx
	else if (k - 1 >= start_idx && k - 1 < right) {
		recursive_helper(array, start_idx, right - 1, k);
	}
	 // if (k - 1 > right && k - 1 <= end_idx)
	else {
		recursive_helper(array, right + 1, end_idx, k);
	}
}

int quickselect(vector<int> array, int k) {
	if (k < 0 && k >= array.size()) return -1;
	recursive_helper(array, 0, array.size() - 1, k);
  return array[k - 1];
}

int quickselectIterative(vector<int> array, int k) {
	int start_idx = 0, end_idx = array.size() - 1;
	while(true) {
		int pivot_idx = start_idx;
		int left = start_idx, right = end_idx;
		
		while (left <= right) {
			if (array[left] > array[pivot_idx] && array[right] <= array[pivot_idx]) {
				swap(array[left], array[right]);
				left++; right--;
			}
			if (array[left] <= array[pivot_idx]) left++;
			if (array[right] > array[pivot_idx]) right--;
		}
		swap(array[right], array[pivot_idx]);
			
		if (k - 1 == right) return array[right];
		else if (k - 1 < right) {
			end_idx = right - 1;
		}
		else {
			start_idx = right + 1; 
		}
	}
  return -1;
}
