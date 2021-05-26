#include <vector>
using namespace std;

void DFS(vector<vector<int>> edges, int start, vector<int> explored, vector<vector<int>>& cycles) {
	explored.push_back(start);
	for (int i = 0; i < edges[start].size(); i++) {
		if (find(explored.begin(), explored.end(), edges[start][i]) != explored.end()) {
			explored.push_back(edges[start][i]);
			cycles.push_back(explored);
		}
		else {
			DFS(edges, edges[start][i], explored, cycles);
		}		
	}	
}

bool cycleInGraph(vector<vector<int>> edges) {
	vector<int> explored;
	vector<vector<int>> cycles;
	for(int i = 0; i < edges.size(); i++) {
		DFS(edges, i, explored, cycles);
	}
	if (cycles.size() != 0) return true;
  return false;
}
