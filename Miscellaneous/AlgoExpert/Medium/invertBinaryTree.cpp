#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void swap(BinaryTree* root) {
	if (root == NULL) return;
	BinaryTree* temp = root->left;
	root->left = root->right;
	root->right = temp;	
	
	/* Recursive Calls */
	swap(root->left);
	swap(root->right);
}

void invertBinaryTree(BinaryTree *tree) {
	swap(tree);
}
