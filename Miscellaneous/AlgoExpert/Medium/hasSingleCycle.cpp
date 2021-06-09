using namespace std;

bool hasSingleCycle(vector<int> array) {
	int n = array.size();
	int value = 0;
	for (int i = 0; i < n; i++) {
		int temp = i + array[i];
		if (temp < 0) {
			temp = temp + n * (1 + abs(temp) / n); 
		}		
		array[i] = temp % n;
		value += array[i];
	}
	
	if (value != (n - 1) * n / 2) return false;
	int i = 0, count = 0;
	while(count < n) {
		if (array[i] == -1 && count < n - 1) return false;
		else {
			int temp = array[i];
			array[i] = -1;
			i = temp;
		}
		count++;
	}
	return true;
}
