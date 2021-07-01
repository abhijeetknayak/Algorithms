#include <vector>
using namespace std;

int lineThroughPoints(vector<vector<int>> points) {
	int max_val = -1;
	if (points.size() == 1) return 1;
	for (int i = 0; i < points.size(); i++) {
		cout << "I is " << i << endl;
		unordered_map<string, int> slopes;
		for (int j = i + 1; j < points.size(); j++) {
			string s = "";
			double slope = 0.0;
			if (points[i][0] == points[j][0])
				s = "INF";
			else {
				slope = (points[i][1] - points[j][1]) / (double)(points[i][0] - points[j][0]);
				s = to_string(slope);
			}
			
			cout << s << endl;
			
			if (slopes.find(s) != slopes.end()) {
				slopes[s] += 1;
			}
			else {
				slopes[s] = 2;
			}
		}
		
		for (auto element : slopes) {
			if (element.second > max_val) max_val = element.second; 
		}
	}
  return max_val;
}
