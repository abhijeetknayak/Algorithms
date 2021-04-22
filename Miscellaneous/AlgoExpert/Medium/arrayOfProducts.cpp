#include <vector>

using namespace std;

vector<int> arrayOfProductsBruteForce(vector<int> array) {
	vector<int> result;
	int exclude = 0;
	while(exclude < array.size()) {
		int temp = 1;
		for (int i = 0; i < array.size(); i++) {
			if (i == exclude) continue;
			else temp *= array[i];
		}
		result.push_back(temp);
		exclude++;
	}
  return result;
}
