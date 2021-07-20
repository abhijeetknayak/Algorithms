using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void insert_node(BST * root, int value) {
	BST * temp = root;
	BST * new_node = new BST(value);
	
	while(true) {
		if (root->value > value) {
			if (root->left == NULL) {
				root->left = new_node; break;
			}
			root = root->left;
		}
		else {
			if (root->right == NULL) {
				root->right = new_node; break;
			}
			root = root->right;
		}
	}
	
	root = temp;
}

BST * reconstructBst1(vector<int> preOrderTraversalValues) {
	if (preOrderTraversalValues.size() == 0) return NULL;
	
	BST * root = new BST(preOrderTraversalValues[0]);
	for (int i = 1; i < preOrderTraversalValues.size(); i++) {
		if (preOrderTraversalValues[i] < preOrderTraversalValues[0]) {
			insert_node(root, preOrderTraversalValues[i]);
		}
		else {
			insert_node(root, preOrderTraversalValues[i]);
		}
	}
	
	return root;
}

BST *reconstructBst2(vector<int> preOrderTraversalValues) {
	if (preOrderTraversalValues.size() == 0) return NULL;
	
	int rightIdx = preOrderTraversalValues.size();
	BST * root = new BST(preOrderTraversalValues[0]);
	
	for (int i = 1; i < preOrderTraversalValues.size(); i++) {
		if (preOrderTraversalValues[i] >= preOrderTraversalValues[0]) {
			rightIdx = i;
			break;
		}
	}
	
	/* Left and Right sub tree available */
	root->left = reconstructBst(vector<int>(preOrderTraversalValues.begin() + 1, preOrderTraversalValues.begin() + rightIdx));
	root->right = reconstructBst(vector<int>(preOrderTraversalValues.begin() + rightIdx, preOrderTraversalValues.end()));
		
  return root;
}
