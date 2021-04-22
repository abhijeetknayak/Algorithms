#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
	int low = 0, high = array.size() - 1, ret = -1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if (array[mid] == target) { 
			ret = mid;
			break;
		}
		else if (array[mid] > target) high = mid - 1;
		else low = mid + 1;
	}
  return ret;
}
