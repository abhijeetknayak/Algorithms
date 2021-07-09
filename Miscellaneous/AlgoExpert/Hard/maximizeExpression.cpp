#include <vector>
using namespace std;

int maximizeExpression(vector<int> array) {
	if (array.size() < 4) return 0;
	vector<int> dp1(array.size(), INT_MIN);
	vector<int> dp2(array.size(), INT_MIN);
	vector<int> dp3(array.size(), INT_MIN);
	vector<int> dp4(array.size(), INT_MIN);
	
	dp1[0] = array[0];
	/* Max Value for A */
	for(int i = 1; i < array.size(); i++) {
		dp1[i] = max(dp1[i - 1], array[i]);
	}
	
	/* Max value for A - B */
	for (int i = 1; i < array.size(); i++) {
		dp2[i] = max(dp2[i - 1], dp1[i - 1] - array[i]);
	}
	
	/* Max value of A - B + C */
	for (int i = 2; i < array.size(); i++) {
		dp3[i] = max(dp3[i - 1], dp2[i - 1] + array[i]);
	}
	
	/* Max value of A - B + C - D */
	for (int i = 3; i < array.size(); i++) {
		dp4[i] = max(dp4[i - 1], dp3[i - 1] - array[i]);
	}
	
  return dp4[dp4.size() - 1];
}
