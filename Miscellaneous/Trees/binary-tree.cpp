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

	// root = delete_node(root, 8); // Deletion not possible
	// root = delete_node(root, 2);
	// root = delete_node(root, 3);

	/* BFS */
	tree_BFS(root);
	cout << endl;

	/* Inorder Traversal */
	tree_DFS_inorder_traversal(root);
	cout << endl;

	/* PreOrder Traversal */
	tree_DFS_preorder_traversal(root);
	cout << endl;

	/* PostOrder Traversal */
	tree_DFS_postorder_traversal(root);
	cout << endl;

	inorder_traversal_without_recursion(root);
	cout << endl;

	morris_traversal(root);
	cout << endl;

	int sum_depth = 0;
	DFS_depth(root, 0, &sum_depth);
	cout << sum_depth << endl;

	root = insert_node(root, 6);
	root = insert_node(root, 7);
	root = insert_node(root, 8);
	root = insert_node(root, 9);

	sum_depth = 0;
	DFS_depth(root, 0, &sum_depth);
	cout << sum_depth << endl;


	return 0;
}
