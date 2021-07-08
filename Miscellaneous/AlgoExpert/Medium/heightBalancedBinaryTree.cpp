using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

int recursive_helper(BinaryTree * root, bool& balanced) {
	if (root == NULL) return 0;
	int left_height = recursive_helper(root->left, balanced);
	int right_height = recursive_helper(root->right, balanced);
	
	if (abs(left_height - right_height) > 1) balanced = false;
	int height = max(left_height, right_height) + 1;
	return height;
}

bool heightBalancedBinaryTree(BinaryTree *tree) {
  bool balanced = true;
	recursive_helper(tree, balanced);
  return balanced;
}
