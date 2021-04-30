#include <vector>
using namespace std;

void swap(vector<int>& array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

vector<int> selectionSort(vector<int> array) {
	for (int i = 0; i < array.size() - 1; i++) {
		int minimum = i;
		for (int j = i + 1; j < array.size(); j++) {
			if (array[j] < array[minimum]) minimum = j;
		}
		swap(array, i, minimum);
	}
  return array;
}
