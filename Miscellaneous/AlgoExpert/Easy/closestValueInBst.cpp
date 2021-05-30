class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

void recursion_helper(BST* tree, int target, int& closest) {
	if (tree == NULL) return;
	if (tree->value > target) {
		if (abs(target - tree->value) < abs(target - closest)) {
			closest = tree->value;
		}
		recursion_helper(tree->left, target, closest);		
	}
	if (tree->value <= target) {
		if (abs(target - tree->value) < abs(target - closest)) {
			closest = tree->value;
		}
		recursion_helper(tree->right, target, closest);		
	}
}

int findClosestValueInBst(BST *tree, int target) {
	int closest = INT_MIN;
	recursion_helper(tree, target, closest);
	
	return closest;
}
