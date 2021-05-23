using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

void DFS(BinaryTree* root, int cur_depth, int& total_depth) {
	if (root == NULL) return;
	total_depth += cur_depth;
	
	if (root->left != NULL) DFS(root->left, cur_depth + 1, total_depth);
	if (root->right != NULL) DFS(root->right, cur_depth + 1, total_depth);
}

int nodeDepths(BinaryTree *root) {
	int total_depth = 0;
	DFS(root, 0, total_depth);
  return total_depth;
}
