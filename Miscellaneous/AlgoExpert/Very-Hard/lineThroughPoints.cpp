#include <vector>
using namespace std;

int findGCD(int a, int b) {
	while(true) {
		if (a == 0)
			return b;
		if (b == 0) 
			return a;
		int tB = b;
		b = a % b;
		a = tB;
	}
}

string getString(vector<int> a, vector<int> b) {
	string s = "";
	if (b[0] != a[0]) {
		/* X-Coordinates are different */
		int gcd = findGCD(b[0] - a[0], b[1] - a[1]);
		int num = (b[1] - a[1]) / gcd;
		int den = (b[0] - a[0]) / gcd;
		if (num == 0) {
			s = to_string(num) + ':' + to_string(num);
		}
		else {
			s = to_string(num) + ':' + to_string(den);
		}		
	}
	else {
		s = "INF:INF";
	}
	
	return s;
}
int lineThroughPoints(vector<vector<int>> points) {
	int max_val = -1;
	if (points.size() == 1) return 1;
	for (int i = 0; i < points.size(); i++) {
		cout << "I is " << i << endl;
		unordered_map<string, int> slopes;
		for (int j = i + 1; j < points.size(); j++) {
			string s = getString(points[i], points[j]);
			
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
