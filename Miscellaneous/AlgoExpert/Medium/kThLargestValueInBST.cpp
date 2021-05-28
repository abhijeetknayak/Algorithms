using namespace std;

class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void DFS_naive(BST* tree, vector<int>& result) {
	if (tree == NULL) return;
	
	DFS(tree->left, result);
	result.push_back(tree->value);
	DFS(tree->right, result);
}

int findKthLargestValueInBst_naive(BST *tree, int k) {
	vector<int> result;
	DFS(tree, result);
	int index = result.size() - k;
	if (index >= 0) return result[index];
  return -1;
}

void DFS(BST* tree, int k, int& num_elements_passed, int& result) {
	if (tree == NULL || num_elements_passed == k) return;	

	DFS(tree->right, k, num_elements_passed, result);
	num_elements_passed += 1; 
	if (num_elements_passed == k) result = tree->value;
	DFS(tree->left, k, num_elements_passed, result);	
}

int findKthLargestValueInBst(BST *tree, int k) {
	int result;
	int num_passed = 0;
	DFS(tree, k, num_passed, result);
  return result;
}
