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

void recursive_helper(BinaryTree* root, int value, vector<int>& result) {
	if (root->left == NULL && root->right == NULL) {
		result.push_back(value + root->value); return;
	}	
	if (root->left != NULL) recursive_helper(root->left, value + root->value, result);
	if (root->right != NULL) recursive_helper(root->right, value + root->value, result);
}

vector<int> branchSums(BinaryTree *root) {
	vector<int> result;
	recursive_helper(root, 0, result);
  return result;
}
