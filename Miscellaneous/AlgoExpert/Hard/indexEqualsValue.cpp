#include <vector>
using namespace std;

int indexEqualsValueBF(vector<int> array) {
	for (int i = 0; i < array.size(); i++) {
		 if (i == array[i]) return i;
	}
  return -1;
}

int indexEqualsValue(vector<int> array) {
	// Sorted Array
	int first = 0, last = array.size() - 1, ret = -1, mid = 0;
	while(first <= last) {
		mid = first + (last - first) / 2;
		if (array[mid] == mid) {
			last = mid - 1;
			ret = mid;
		}
		else if (array[mid] < mid) {
			// Go to the right side
			first = mid + 1;
		}
		else {
			// Go left
			last = mid - 1;
		}
	}
  return ret;
}
