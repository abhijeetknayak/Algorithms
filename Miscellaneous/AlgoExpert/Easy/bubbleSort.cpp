#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) {
	int counter = 0;
	while(true) {
		int swapCount = 0;
		for (int i = 0; i < array.size() - 1 - counter; i++) {
			if (array[i] > array[i + 1]) {
				swapCount += 1;
				swap(array[i], array[i + 1]);
			}
		}
		counter++;
		if (swapCount == 0) break;
	}
  return array;
}
