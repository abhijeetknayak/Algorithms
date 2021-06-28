#include <vector>
using namespace std;

int waterArea(vector<int> heights) { 
	vector<int> lowHeights(heights.size(), 0);
	vector<int> highHeights(heights.size(), 0);
	for (int i = 1; i < heights.size(); i++) {
		if (heights[i - 1] > lowHeights[i - 1]) lowHeights[i] = heights[i - 1];
		else lowHeights[i] = lowHeights[i - 1];
	}
	for (int i = heights.size() - 2; i >= 0; i--) {
		if (heights[i + 1] > highHeights[i + 1]) highHeights[i] = heights[i + 1];
		else highHeights[i] = highHeights[i + 1];
	}
	
	int area = 0;
	for (int i = 0; i < heights.size(); i++) {
		area += max(0, min(lowHeights[i], highHeights[i]) - heights[i]);
	}
	
  return area;
}
