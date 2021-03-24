ListNode* swapPairs(ListNode* head) {
	ListNode * dummy = new ListNode(-1), * first = dummy, * second = head;
	dummy->next = head;

	if (head->next == nullptr || head == nullptr) return head;

	while(true) {
		first->next = second->next;
		second->next = second->next->next;
		first->next->next = second;

		if (second->next == nullptr) break;

		first = second;
		second = second->next;

		if (second->next == nullptr) break;
	}

	return dummy->next;
}
