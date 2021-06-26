using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

void is_descendent(BST * cur_node, BST * nodeToSearch, bool& found) {
	if (cur_node == NULL) return;
	
	if (cur_node == nodeToSearch) {
		found = true; return;
	}
	
	if (nodeToSearch->value >= cur_node->value) {
			is_descendent(cur_node->right, nodeToSearch, found);
	}
	else {
			is_descendent(cur_node->left, nodeToSearch, found);
	}
}

bool validateThreeNodesNaive(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
	BST * temp;
	bool found = false;
	is_descendent(nodeTwo, nodeOne, found);
	if (found != true) {
		is_descendent(nodeTwo, nodeThree, found);
		if (found != true) return false;
		else temp = nodeOne;
	}
	else temp = nodeThree;
	
	found = false;
	is_descendent(temp, nodeTwo, found);
	
  return found;
}
