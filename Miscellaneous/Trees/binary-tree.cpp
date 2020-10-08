#include <bits/stdc++.h>
#include "binary-tree.h"

using namespace std;

int main() {
	struct node * root = new node(1);
	struct node * lc = new node(2);
	struct node * rc = new node(3);

	root->left_child = lc;
	root->right_child = rc;



	return 0;
}
