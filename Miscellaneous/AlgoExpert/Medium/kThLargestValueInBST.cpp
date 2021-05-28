using namespace std;

class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void DFS(BST* tree, vector<int>& result) {
	if (tree == NULL) return;
	
	DFS(tree->left, result);
	result.push_back(tree->value);
	DFS(tree->right, result);
}

int findKthLargestValueInBst(BST *tree, int k) {
	vector<int> result;
	DFS(tree, result);
	int index = result.size() - k;
	if (index >= 0) return result[index];
  return -1;
}
