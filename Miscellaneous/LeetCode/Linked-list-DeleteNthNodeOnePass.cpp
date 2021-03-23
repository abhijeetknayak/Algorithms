#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {

	ListNode * dummy = new ListNode(0);
	dummy->next = head;
	ListNode * first = dummy, * second = dummy;

	/* Advance first node to maintain 'n' gap between first and second pointers */
	for (int i = 0; i < n; i++) {
		first = first->next;
	}

	/* Advance both pointers until the first reaches end of list */
	while(first->next != nullptr) {
		first = first->next;
		second = second->next;
	}

	second->next = second->next->next;
	return dummy->next;
}

int main() {
	ListNode a(0);
	a.next = new ListNode(1);
	a.next->next = new ListNode(2);
	a.next->next->next = new ListNode(3);
	a.next->next->next->next = new ListNode(4);
	a.next->next->next->next->next = new ListNode(5);

	ListNode * p = removeNthFromEnd(&a, 4);
	while(p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
}
