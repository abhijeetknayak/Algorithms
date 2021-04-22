using namespace std;

bool isMonotonic(vector<int> array) {
	int n = array.size();
	if (n == 0 || n == 1) return true;

	bool dec = false, inc = false;
	for (int i = 0; i < n - 1; i++) {
		if (array[i] < array[i + 1]) inc = true; 
		else if (array[i] > array[i + 1]) dec = true;
	}
	
	/* All values equal */
	if (dec == false && inc == false) return true;
	return (inc != dec);
}
