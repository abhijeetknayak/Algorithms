#include <vector>
using namespace std;

int largestRectangleUnderSkylineBruteForce(vector<int> buildings) {
	int max_area = 0, left = 0, right = 0;
	for (int i = 0; i < buildings.size(); i++) {
		left = i; right = i;
		while(left > 0) {
			if (buildings[left - 1] >= buildings[i]) left--;
			else break;
		}
		while(right < buildings.size() - 1) {
			if (buildings[right + 1] >= buildings[i]) right++;
			else break;
		}
		max_area = max(max_area, (right - left + 1) * buildings[i]);
	}
  return max_area;
}
