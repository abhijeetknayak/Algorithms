using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

void recursive_helper(BinaryTree* root, vector<BinaryTree*>& inorder) {
	if (root == NULL) return;
	
	recursive_helper(root->left, inorder);
	inorder.push_back(root);
	recursive_helper(root->right, inorder);
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
	vector<BinaryTree*> inorder;
	recursive_helper(tree, inorder);
	inorder.push_back(NULL);
	for (int i = 0; i < inorder.size(); i++) {
		if (inorder[i] == node) return inorder[i + 1]; 
	}
  return nullptr;
}
