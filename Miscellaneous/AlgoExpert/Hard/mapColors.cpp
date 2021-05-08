#include <iostream>
#include <vector>

using namespace std;

bool isValidColor(int index, char color, vector<vector<int>> nodes, vector<char> nodeColors);
bool tryAddingColor(int index, vector<vector<int>> nodes, vector<char>& nodeColors, vector<char> possibleColors);
bool solveColor(int index, vector<vector<int>> nodes, vector<char>& nodeColors, vector<char> possibleColors);

bool isValidColor(int index, char color, vector<vector<int>> nodes, vector<char> nodeColors) {
	for (int i = 0; i < (int)nodes[index].size(); i++) if (nodeColors[nodes[index][i]] == color) return false;
	return true;
}

bool tryAddingColor(int index, vector<vector<int>> nodes, vector<char>& nodeColors, vector<char> possibleColors) {
	for (int i = 0; i < (int)possibleColors.size(); i++) {
		if (isValidColor(index, possibleColors[i], nodes, nodeColors)) {
			nodeColors[index] = possibleColors[i];
			return solveColor(index + 1, nodes, nodeColors, possibleColors);
		}
	}

	nodeColors[index] = 'N';
	return false;
}
bool solveColor(int index, vector<vector<int>> nodes, vector<char>& nodeColors, vector<char> possibleColors) {
	if (index == nodes.size()) return true;

	if (nodeColors[index] == 'N') return tryAddingColor(index, nodes, nodeColors, possibleColors);

	return solveColor(index + 1, nodes, nodeColors, possibleColors);
}

int main() {
	vector<char> colors{ 'R', 'G', 'B', 'Y' };
	vector<vector<int>> a{ {1, 6}, {0, 2, 3, 4, 5, 7}, {0, 1, 3, 7}, {1, 2, 7}, {1, 5}, {1, 4}, {0}, {1, 2, 3} };

	vector<char> node_colors(a.size());
	for (int i = 0; i < (int)node_colors.size(); i++) {
		node_colors[i] = 'N';
	}

	solveColor(0, a, node_colors, colors);

	for (auto ele : node_colors) {
		cout << ele << " ";
	}
	cout << endl;
	return 0;
}
