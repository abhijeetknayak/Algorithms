#include <vector>
using namespace std;

void swap(vector<int>& array, int i, int j) {
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

vector<int> insertionSort(vector<int> array) {
	for (int i = 1; i < array.size(); i++) {
		int j = i - 1;
		int temp = i;
		while (j >= 0 && array[temp] < array[j]) {
			swap(array, j, temp);
			j--; temp--;
		}
		
	}
	return array;
}
