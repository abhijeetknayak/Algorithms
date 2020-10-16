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
	}
};
