using namespace std;

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

vector<int> BFS_from_target(BinaryTree* start_node, unordered_map<int, BinaryTree*> parents, int k) {
	vector<int> result, explored;
	queue<pair<BinaryTree*, int>> frontier;
	frontier.push(make_pair(start_node, 0));
	
	while(!frontier.empty()) {
		pair<BinaryTree*, int> p = frontier.front(); frontier.pop();
		if (find(explored.begin(), explored.end(), p.first->value) != explored.end()) {
			continue;
		}
		int val = p.second;
		if (val == k) { 
			result.push_back(p.first->value); 
			continue;
		}
		if (p.first->left != NULL) frontier.push(make_pair(p.first->left, val + 1));
		if (p.first->right != NULL) frontier.push(make_pair(p.first->right, val + 1));
		if (parents[p.first->value] != NULL) frontier.push(make_pair(parents[p.first->value], val + 1));
		
		explored.push_back(p.first->value);
	}
	return result;
}

vector<int> findNodesDistanceK(BinaryTree *tree, int target, int k) {
	unordered_map<int, BinaryTree*> parents;
	DFS(tree, NULL, parents);
		
	print_parents(parents);
	cout << "Done!";
	
	BinaryTree* p = parents[target], * start_node;
	if (p == NULL) start_node = tree;
	else if (p->left == NULL) start_node = p->right;
	else if (p->right == NULL) start_node = p->left;
	else if (p->left->value == target) start_node = p->left;
	else start_node = p->right;
	
	vector<int> result = BFS_from_target(start_node, parents, k);	
  return result;
}
