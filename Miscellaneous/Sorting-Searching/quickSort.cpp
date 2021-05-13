#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> array);
void quicksort(vector<int>& array, int startIdx, int endIdx);

void quicksort_new(vector<int>& array, int startIdx, int endIdx) {
	if (startIdx >= endIdx) return;
	if (endIdx - startIdx == 1) {
		if (array[startIdx] > array[endIdx]) {
			swap(array[startIdx], array[endIdx]);
			return;
		}
	}

	int pivotIdx = startIdx, leftIdx = startIdx + 1, rightIdx = endIdx;

	while (rightIdx >= leftIdx) {
		if (array[leftIdx] > array[pivotIdx] && array[rightIdx] < array[pivotIdx]) {
			swap(array[leftIdx], array[rightIdx]); leftIdx++; rightIdx--;
		}
		while (array[leftIdx] <= array[pivotIdx]) leftIdx++;
		while (array[rightIdx] >= array[pivotIdx]) rightIdx--;
	}

	swap(array[pivotIdx], array[rightIdx]);

	quicksort(array, startIdx, rightIdx - 1);
	quicksort(array, rightIdx + 1, endIdx);
}

void quicksort(vector<int>& array, int startIdx, int endIdx) {
	if (startIdx >= endIdx) return;
	if (endIdx - startIdx == 1) {
		if (array[startIdx] > array[endIdx]) {
			swap(array[startIdx], array[endIdx]);
			return;
		}
	}

	int pivotIdx = startIdx, leftIdx = startIdx + 1, rightIdx = endIdx;
	while (leftIdx <= rightIdx) {
		if (array[rightIdx] < array[pivotIdx] && array[leftIdx] > array[pivotIdx]) {
			swap(array[leftIdx], array[rightIdx]);
		}
		if (array[leftIdx] <= array[pivotIdx]) leftIdx++;
		if (array[rightIdx] >= array[pivotIdx]) rightIdx--;
	}

	swap(array[pivotIdx], array[rightIdx]);
	quicksort(array, startIdx, rightIdx - 1);
	quicksort(array, rightIdx + 1, endIdx);
}

void print_vector(vector<int> array) {
	for (auto ele : array) {
		cout << ele << " ";
	}
	cout << endl;
}

int main() {
	vector<int> a{ 23, 4, 56, 38, 19, 8, 12, 93, 7, 15, 25, 13, 42, 76, 10 };
	quicksort_new(a, 0, a.size() - 1);
	print_vector(a);
	return 0;
}
