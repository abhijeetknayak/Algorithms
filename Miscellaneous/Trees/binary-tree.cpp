#include <bits/stdc++.h>
#include "binary-tree.h"

using namespace std;

int main() {
	struct node * root = new node(1);
	struct node * lc = new node(2);
	struct node * rc = new node(3);

	root->left_child = lc;
	root->right_child = rc;

	root->left_child->left_child = new node(4);

	root = insert_node(root, 5);

	// cout << root->left_child->right_child->data;

	root = delete_node(root, 8); // Deletion not possible
	root = delete_node(root, 2);
	root = delete_node(root, 3);

	cout << root->left_child->data << "  " << root->right_child->data << endl;





	return 0;
}
