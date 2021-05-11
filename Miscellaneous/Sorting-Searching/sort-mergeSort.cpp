void merge_arrays(vector<int>& array, vector<int> x1, vector<int> x2) {
	/* Merging the arrays */
	int first = 0, second = 0, i = 0;
	while (i < array.size()) {
		if (first == x1.size() && second == x2.size()) break;
		else if (second == x2.size()) {
			array[i] = x1[first];
			first++; i++;
		}
		else if (first == x1.size()) {
			array[i] = x2[second];
			second++; i++;
		}
		else if (x1[first] < x2[second]) {
			array[i] = x1[first];
			first++; i++;
		}
		else {
			array[i] = x2[second];
			second++; i++;
		}
	}
}

void mergesort_recursive(vector<int>& array) {
	/* Base Case for size == 1 or 2 */
	if (array.size() == 1) { return; }
	if (array.size() == 2) {
		if (array[0] > array[1]) {
			swap(array[0], array[1]);
		}
		return;
	}

	int mid = array.size() / 2;

	vector<int> x1(array.begin(), array.begin() + mid);
	vector<int> x2(array.begin() + mid, array.end());

	mergesort_recursive(x1);
	mergesort_recursive(x2);

	merge_arrays(array, x1, x2);
}

void print_vector(vector<int> array) {
	for (auto ele : array) {
		cout << ele << " ";
	}
	cout << endl;
}

int main() {
	vector<int> a{ 23, 4, 56, 38, 19, 8, 12, 93, 7, 15, 25, 13, 42, 76, 10 };
	//quicksort(a, 0, a.size() - 1);
	mergesort_recursive(a);
	print_vector(a);
	return 0;
}
