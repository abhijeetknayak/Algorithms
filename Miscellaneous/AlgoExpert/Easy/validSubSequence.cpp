bool validSubsequence(vector<int>& array, vector<int>& sequence) {
	bool cont = true;
	int i = 0, j = 0;
	if (sequence.size() == 0 || array.size() == 0) return false;
	while(cont && (i < array.size())) {
		if (array[i] == sequence[j]) {
			j++;
			i++;
			if (j == sequence.size()) cont = false;
		}
		else i++;
	}
	return !cont;
}
