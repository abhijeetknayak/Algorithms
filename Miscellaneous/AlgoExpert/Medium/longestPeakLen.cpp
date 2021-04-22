using namespace std;

int longestPeak(vector<int> array) {
	int longestPeakLen = 0;	
	int i = 1;
	
	while (i < int(array.size()) - 1) {
		bool peak = array[i - 1] < array[i] && array[i] > array[i + 1];
		if (!peak) { i++; continue; }
		int start = i - 2, end = i + 2;
		while(start >= 0 && array[start] < array[start + 1]) {
			start--;
		}
		while(end < array.size() && array[end] < array[end - 1]) {
			end++;
		}
		longestPeakLen = max(longestPeakLen, end - start - 1);
		i = end;
	}
  return longestPeakLen;
}
