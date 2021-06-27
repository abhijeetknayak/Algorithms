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
bool validateThreeNodes(BST *nodeOne, BST *nodeTwo, BST *nodeThree) {
  BST * searchFromOne = nodeOne;
	BST * searchFromThree = nodeThree;
	
	bool found2_from3 = false, found2_from1 = false, retVal = false;
	
	while(true) {
		if (!found2_from3) found2_from3 = searchFromThree == nodeTwo;
		if (!found2_from1) found2_from1 = searchFromOne == nodeTwo;
				
		if (searchFromOne != NULL) {
			if (found2_from1) {
				if (searchFromOne == nodeThree) {
					retVal = true; break;
				}
				else if (nodeThree->value < searchFromOne->value)
					searchFromOne = searchFromOne->left;
				else searchFromOne = searchFromOne->right;
			}
			else {	
				if (searchFromOne == nodeThree) break;
				else if (nodeTwo->value < searchFromOne->value) 
					searchFromOne = searchFromOne->left;
				else searchFromOne = searchFromOne->right;
			}				
		}
		
		if (searchFromThree != NULL) {
			if (found2_from3) {
				if (searchFromThree == nodeOne) {
					retVal = true; break;
				}
				else if (nodeOne->value < searchFromThree->value)
					searchFromThree = searchFromThree->left;
				else searchFromThree = searchFromThree->right;
			}
			else {		
				if (searchFromThree == nodeOne) break;
				else if (nodeTwo->value < searchFromThree->value) 
					searchFromThree = searchFromThree->left;
				else searchFromThree = searchFromThree->right;
			}				
		}
		
		if (searchFromThree == NULL && searchFromOne == NULL) break;
	}
	return retVal;
}


