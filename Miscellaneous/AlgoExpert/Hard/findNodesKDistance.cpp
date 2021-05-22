using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

void print_parents(unordered_map<int, BinaryTree*> parents) {
	for (auto element : parents) {
		if (element.second == NULL) {
			cout << element.first << " " << "NULL" << endl; continue;
		}
		cout << element.first << " " << element.second->value << endl;
	}
}

void DFS(BinaryTree* tree, BinaryTree* parent_node, unordered_map<int, BinaryTree*>& parents) {
	if (parent_node == NULL) parents[tree->value] = NULL;
	else parents[tree->value] = parent_node;
		
	if (tree->left != NULL)	DFS(tree->left, tree, parents);
	if (tree->right != NULL) DFS(tree->right, tree, parents);
}

vector<int> findNodesDistanceK(BinaryTree *tree, int target, int k) {
	unordered_map<int, BinaryTree*> parents;
	DFS(tree, NULL, parents);
	
	BinaryTree* p = parents[target], * start_node;
	if (p->left->value == target) start_node = p->left;
	else start_node = p->right;
	
	BFS_from_target(start_node)
	
	print_parents(parents);
	
  return {};
}
