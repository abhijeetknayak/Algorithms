#include <vector>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
	vector<vector<int>> merged_intervals;
	sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0]; });
	
	int index = 0;
	merged_intervals.push_back(intervals[0]);
	for (int i = 1; i < intervals.size(); i++) {
		if (merged_intervals[index][1] > intervals[i][1]) continue;
		else if (merged_intervals[index][1] >= intervals[i][0]) {
			merged_intervals[index][1] = intervals[i][1];
		}
		else {
			merged_intervals.push_back(intervals[i]);
			index++;
		}
	}
	
  return merged_intervals;
}
