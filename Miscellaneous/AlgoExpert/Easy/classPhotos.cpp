#include <vector>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
	/* Sort arrays */
	sort(redShirtHeights.begin(), redShirtHeights.end());
	sort(blueShirtHeights.begin(), blueShirtHeights.end());
	
	int factor = 1;
	if (redShirtHeights[0] >= blueShirtHeights[0]) factor = -1;
	
	for (int i = 0; i < redShirtHeights.size(); i++) {
		if (factor * redShirtHeights[i] >= factor * blueShirtHeights[i]) return false;
	}
	
  return true;
}
