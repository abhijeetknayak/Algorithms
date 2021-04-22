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

/* O(N) solution */
vector<int> arrayOfProducts(vector<int> array) {
	vector<int> result(array.size());
	int leftRunningProd = 1, rightRunningProd = 1;
	for(int i = 0; i < array.size(); i++) {
		result[i] = leftRunningProd;
		leftRunningProd *= array[i];
	}
	
	for(int i = array.size() - 1; i >= 0; i--) {
		result[i] *= rightRunningProd;
		rightRunningProd *= array[i];
	}
	
	return result;
}
