#include <vector>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }

	BST& insert(int val) {
		if (this->value > val) {
			/* Insert new node in the left sub tree */
			if (this->left == NULL) {
				BST * new_node = new BST(val);
				this->left = new_node;
			}
			else this->left->insert(val); 
		}
		else {
			/* Insert new node innthe right sub tree */
			if (this->right == NULL) {
					BST * new_node = new BST(val);
					this->right = new_node;
				}
			  else this->right->insert(val); 
		}
		return *this;
	}
	
	int get_min_value() {
		if (this->left == NULL) return this->value;
		else return this->left->get_min_value();
	}

  bool contains(int val) {
		if (this->value == val) return true;
		else if (this->value > val) {
			if (this->left == NULL) return false;
			else return this->left->contains(val);
		} 
		else {
			if (this->right == NULL) return false;
			return this->right->contains(val);			
		}
    return false;
  }

  BST &remove(int val, BST* parent = NULL) {
		if (this->value > val) {
			if (this->left != NULL) 
				this->left->remove(val, this);
		}
		else if (this->value < val) {
			if (this->right != NULL)
				this->right->remove(val, this);
		}
		else {
			/* Value is the same */
			if (this->left != NULL && this->right != NULL) {
				this->value = this->right->get_min_value();
				this->right->remove(value, this);
			}
			/* One or both of the child pointers are NULL */
			else {
				if (parent == NULL) {
					/* First node - Root */
					if (this->left != NULL) {
						/* Just delete the topmost element */
						this->value = this->left->value;
						this->right = this->left->right;
						this->left = this->left->left;
					}
					else if (this->right != NULL) {
						this->value = this->right->value;
						this->left = this->right->left;
						this->right = this->right->right;
					}
					else { }
				}
				else {
					/* Parent is not Null. This means the node is somewhere at the end */
					if (this == parent->left) {
						parent->left = this->left != NULL ? this->left : this->right;
					}
					else if (this == parent->right) {
						parent->right = this->left != NULL ? this->left : this->right;
					}
				}
			}
		}
			
		
    return *this;
  }
};
