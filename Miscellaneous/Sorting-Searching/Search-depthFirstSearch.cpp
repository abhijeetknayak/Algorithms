#include <vector>
using namespace std;
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string> *array) {
		array->push_back(name);
		for (int i = 0; i < children.size(); i++) {
			children[i]->depthFirstSearch(array); // Recursive
		}
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};

/* Recursive DFS without Trees */
void DepthFirstSearch(vector<vector<int>> graph, int start, vector<int>& explored) {
	explored.push_back(start);
	for (int i = 0; i < graph[start].size(); i++) {
		if (find(explored.begin(), explored.end(), graph[start][i]) == explored.end()) {
			DepthFirstSearch(graph, graph[start][i], explored);
		}
	}
}
