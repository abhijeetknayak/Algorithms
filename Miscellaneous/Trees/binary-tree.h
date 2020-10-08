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
