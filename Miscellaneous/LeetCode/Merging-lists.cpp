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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode * head = new ListNode(0), * current = head;

	while (l1 != NULL || l2 != NULL) {
		if (l1 == NULL) {
			current->next = l2;
			l2 = l2->next;
			current = current->next;
		}
		else if (l2 == NULL) {
			current->next = l1;
			l1 = l1->next;
			current = current->next;
		}
		else {
			/* Both not NULL */
			if (l1->val <= l2->val) {
				current->next = l1;
				l1 = l1->next;
				current = current->next;
			}
			else {
				current->next = l2;
				l2 = l2->next;
				current = current->next;
			}
		}
	}

	return head->next;
}

int main() {
	ListNode * n1 = new ListNode(1);
	ListNode * n2 = new ListNode(2);
	ListNode * n3 = new ListNode(4);
	n1->next = n2;
	n2->next = n3;

	ListNode * n4 = new ListNode(1);
	ListNode * n5 = new ListNode(3);
	ListNode * n6 = new ListNode(6);
	n4->next = n5;
	n5->next = n6;

	ListNode * res = mergeTwoLists(n1, n4);
	while (res != NULL) {
		cout << res->val << " ";
		res = res->next;
	}

	return 0;
}
