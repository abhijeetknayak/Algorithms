using namespace std;

// This is an input class. Do not edit.
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

int recursive_helper(BinaryTree* tree, int& max_val) {	
	if (tree == NULL) return 0;
	
	int left_val = recursive_helper(tree->left, max_val);
	int right_val = recursive_helper(tree->right, max_val);
	int max_branch = max(left_val, right_val);
	int path_incl_root = left_val + right_val;
	
	if (path_incl_root > max_val) max_val = path_incl_root;
	
	return max_branch + 1;
}

int binaryTreeDiameter(BinaryTree *tree) {
	int max_val = 0;
	recursive_helper(tree, max_val);
  return max_val;
}
