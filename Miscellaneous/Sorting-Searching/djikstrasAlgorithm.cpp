#include <vector>
using namespace std;

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
	vector<int> result, explored;
	int min_val = INT_MAX, next = -1, num = 1;
	for (int i = 0; i < edges.size(); i++) result.push_back(-1);
	result[start] = 0;
	
	explored.push_back(start);
	while(num < edges.size()) {		
		for (auto element : explored) {
			for (int i = 0; i < edges[element].size(); i++) {
				if (find(explored.begin(), explored.end(), edges[element][i][0]) == explored.end()) {
					if (result[element] + edges[element][i][1] < min_val) {
						min_val = result[element] + edges[element][i][1];
						next = edges[element][i][0];
					}
				}
			}
		}
		
		if (next == -1) break;
		explored.push_back(next);
		result[next] = min_val;
		min_val = INT_MAX;
		next = -1;
		
		num++;
	}
  return result;
}
