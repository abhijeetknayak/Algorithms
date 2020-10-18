#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node * left_child;
	struct node * right_child;

	node(int value) {
		data = value;
		left_child = NULL;
		right_child = NULL;
	}
};

node * insert_node(node * root_node, int data) {
	if (root_node == NULL) {
		root_node = new node(data);
		return root_node;
	}

	// Traverse entire tree to find a NULL child element
	queue<node*> nodes;
	nodes.push(root_node);

	while(!nodes.empty()) {
		/* Do this until the queue is empty */
		node * n = nodes.front();
		nodes.pop();

		if (n->left_child == NULL) {
			node * new_node = new node(data);
			n->left_child = new_node;
			return root_node;
		}
		else { nodes.push(n->left_child); }

		if (n->right_child == NULL) {
			node * new_node = new node(data);
			n->right_child = new_node;
			return root_node;
		}
		else { nodes.push(n->right_child); }
	}

	return root_node; // Control cannot reach here unless the node was not inserted
}

node * find_deepest_element(node * root_node, int value, node * del_ele) {
	node * temp;

	queue<node *> nodes;
	nodes.push(root_node);

	while(!nodes.empty()) {
		temp = nodes.front();
		if (temp != NULL && temp->data == value) {
			del_ele = temp;
		}
		nodes.pop();

		if(temp->left_child != NULL) {
			nodes.push(temp->left_child);
		}

		if (temp->right_child != NULL) {
			nodes.push(temp->right_child);
		}
	}

	return temp;
}

node * delete_node(node * root_node, int val) {
	node * del_ele = NULL;
	node * last_element = NULL;
	last_element = find_deepest_element(root_node, val, del_ele);

	/* del_ele contains the element to be deleted. Last_element contains the deepest element in the tree */

	if (del_ele != NULL && last_element != NULL) {
		cout << del_ele->data;
		del_ele->data = last_element->data;
		delete last_element;
	}
	else {
		cout << "Deletion not possible" << endl;
	}

	return root_node;
}

void tree_BFS(node * root_node) {
	if (root_node != NULL) {
		queue<node*> nodes;
		nodes.push(root_node);

		while(!nodes.empty()) {
			node * front = nodes.front();
			cout << front->data << " ";
			nodes.pop();

			if (front->left_child != NULL) {
				/* Add left child to nodes queue */
				nodes.push(front->left_child);
			}

			if (front->right_child != NULL) {
				/* Add left child to nodes queue */
				nodes.push(front->right_child);
			}
		}
	}
}

void tree_DFS_inorder_traversal(node * root_node) {
	/* Recursive solution - [Left Child -> Root -> Right Child] */
	if (root_node == NULL) { return; }

	tree_DFS_inorder_traversal(root_node->left_child);
	cout << root_node->data << " ";
	tree_DFS_inorder_traversal(root_node->right_child);
}

void tree_DFS_preorder_traversal(node * root_node) {
	/* Recursive solution - [Root -> Left Child -> Right Child] */
	if (root_node == NULL) { return; }

	cout << root_node->data << " ";
	tree_DFS_preorder_traversal(root_node->left_child);
	tree_DFS_preorder_traversal(root_node->right_child);

}

void tree_DFS_postorder_traversal(node * root_node) {
	/* Recursive solution - [Left Child -> Right Child -> Root] */
	if (root_node == NULL) { return; }

	tree_DFS_postorder_traversal(root_node->left_child);
	tree_DFS_postorder_traversal(root_node->right_child);
	cout << root_node->data << " ";
}


