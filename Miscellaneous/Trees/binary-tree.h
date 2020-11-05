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

void inorder_traversal_without_recursion(node * root_node) {
	stack<node *> nodes;
	node * current = root_node;

	while((current != NULL) || (!nodes.empty())) {
		while(current != NULL) {
			/* Get to leftmost nodes from current node */
			nodes.push(current);
			current = current->left_child;
		}
		/* Last Element in the leftmost leaf */
		current = nodes.top();
		cout << current->data << " ";
		nodes.pop();

		/* Starting with the right child now. Next while loop will start with the right child as root */
		current = current->right_child;
	}
}

void morris_traversal(node * root_node) {
	node * current = root_node, * pre;
	while(current != NULL) {
		if (current->left_child == NULL) {
			cout << current->data << " ";
			current = current->right_child;
		}
		else {
			pre = current->left_child;
			while (pre->right_child != NULL && pre->right_child != current)
				pre = pre->right_child;
			if (pre->right_child == NULL) {
				pre->right_child = current;
				current = current->left_child;
			}
			else {
				pre->right_child = NULL;
				cout << current->data << " ";
				current = current->right_child;
			}

		}
	}
}

void DFS_depth(node * root_node, int depth, int * sum_depth) {
	/* Recursive solution - [Left Child -> Root -> Right Child] */
	if (root_node == NULL) { return; }

	if (sum_depth != NULL) { *sum_depth += depth; }

	DFS_depth(root_node->left_child, depth + 1, sum_depth);
	DFS_depth(root_node->right_child, depth + 1, sum_depth);
}


