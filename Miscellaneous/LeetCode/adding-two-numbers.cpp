#include <bits/stdc++.h>

using namespace std;

struct ListNode{
	int val;
	ListNode * next;

	ListNode(int value) {
		val = value;
		next = NULL;
	}
};

void print_number(ListNode * node) {
	while (node != NULL) {
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode * result = new ListNode(0);
	ListNode * current = result;

	int val = 0;
	while(l1 != NULL || l2 != NULL) {
		if (l1 != NULL) {
			val += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL) {
			val += l2->val;
			l2 = l2->next;
		}
		int res = val % 10;
		val = val / 10;
		current->next = new ListNode(res);
		current = current->next;
	}

	if (val > 0) {
		/* Create last node with val */
		current->next = new ListNode(val);
	}
	print_number(current);
	return(result->next);
}

int main() {
	ListNode * n1 = new ListNode(5);
	ListNode * n2 = new ListNode(6);
	ListNode * n3 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;

	ListNode * n4 = new ListNode(2);
	ListNode * n5 = new ListNode(4);
	ListNode * n6 = new ListNode(3);

	n4->next = n5;
	n5->next = n6;

	print_number(n1);
	print_number(n4);

	ListNode * result = addTwoNumbers(n1, n4);
	cout << "Res : ";

	print_number(result);

	return 0;
}
