ListNode* swapNodes(ListNode* head, int k) {
    long int len = 0;
    if (head == nullptr || head->next == nullptr) return head;
    ListNode * current = head, * first = head, * second = head;

    if (head->next->next == nullptr) {
        current = head->next;
        head->next->next = head;
        head->next = nullptr;
        head = current;
        return head;
    }
    while(current != NULL) {
        len++;
        current = current->next;
    }

    if (k == 1 || k == len) {
        k = 1;
    	current = new ListNode(0);
    	current->next = head;
    	first = current;
    }

    for (int i = 0; i < k - 2; i++) {
        first = first->next;
    }

    for (int i = 0; i < len - k - 1; i++) {
        second = second->next;
    }

    if (k - 2 > len - k - 1) {
    	/* Swap first and second */
    	current = second;
    	second = first;
    	first = current;
    }

    /* Swap the nodes */
    current = first->next;
    first->next = second->next;
    second->next = current;

    current = second->next->next;

    if (first->next->next == nullptr) {
    	first->next->next = current;
    	second->next->next = nullptr;
    	return first->next;
    }
    else {
        second->next->next = first->next->next;
        first->next->next = current;
    }


    return head;
}
